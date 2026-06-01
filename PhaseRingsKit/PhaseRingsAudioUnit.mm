//
//  PhaseRingsAudioUnit.mm
//  PhaseRingsKit
//
//  See PhaseRingsAudioUnit.h and auv3-plan.md (Phase C).
//

#import "PhaseRingsAudioUnit.h"
#import <atomic>

const OSType PhaseRingsAUType         = kAudioUnitType_MusicDevice;       // 'aumu'
const OSType PhaseRingsAUSubType      = 'phrg';
const OSType PhaseRingsAUManufacturer = 'CPMa';

// fullState key under which the non-parameter instrument settings ride
// alongside the auto-serialised parameter tree. (Issue #23, Phase F.4.)
static NSString *const kPhaseRingsInstrumentStateKey = @"PhaseRingsInstrumentState";

// Parameter addresses. The float-receiver params map 1:1 onto Heavy [r …]
// names; `synth` is special-cased to HeavyCore -selectSynth:.
typedef NS_ENUM(AUParameterAddress, PhaseRingsParam) {
    PhaseRingsParamMasterVolume = 0,
    PhaseRingsParamReverbVolume,
    PhaseRingsParamDistortLevel,
    PhaseRingsParamProcessEffects,
    PhaseRingsParamSound,
};

// Sound schemes 0..6 (matches the standalone app's Settings `sound`): 0/1 are
// the Phase / String synths, 2..6 are SoundScraper samples picked via the
// `selectsound` receiver.
static HeavySynth SynthForScheme(NSInteger scheme) {
    if (scheme <= 0) return HeavySynthPhase;
    if (scheme == 1) return HeavySynthCircleStrings;
    return HeavySynthSoundScraper;
}

// Receiver names for the float params (indexed by address; synth is handled
// separately).
static NSString *ReceiverForParam(AUParameterAddress addr) {
    switch (addr) {
        case PhaseRingsParamMasterVolume:  return @"mastervolume";
        case PhaseRingsParamReverbVolume:  return @"reverbvolume";
        case PhaseRingsParamDistortLevel:  return @"distortlevel";
        case PhaseRingsParamProcessEffects:return @"processeffects";
        default: return nil;
    }
}

namespace {
// Capacity of the outgoing-MIDI FIFO (single-producer main thread → single-
// consumer render thread). Power of two so wrap is a mask.
constexpr uint32_t kMidiOutCap = 256;

// Stable, heap-owned state the render block captures. The host guarantees it
// will not call the render block while render resources are deallocated, so
// the block only ever sees a valid (or null) refCon. The atomic guards the
// allocate/deallocate publish against a late render.
struct AURenderCtx {
    std::atomic<void *> heavyRefCon{nullptr};  // HeavyCore.renderRefCon (HeavyRenderState*)
    float *scratch[2] = { nullptr, nullptr };  // fallback output when the host hands us null buffers
    uint32_t scratchFrames = 0;

    // Outgoing MIDI (B3a): the gesture→MIDI mapping runs on the main thread and
    // enqueues here; the render block drains and emits via the host's
    // MIDIOutputEventBlock. SPSC ring; 3-byte messages (the only kind we emit).
    uint8_t midiOut[kMidiOutCap][3];
    std::atomic<uint32_t> midiHead{0};  // producer (main)
    std::atomic<uint32_t> midiTail{0};  // consumer (render)
    // (__bridge) AUMIDIOutputEventBlock, kept alive by the AU's capturedMIDIOut.
    std::atomic<void *> midiSink{nullptr};
};
}

@interface PhaseRingsAudioUnit () {
    AURenderCtx *_rc;
}
@property (nonatomic, strong, nullable) HeavyCore *core;
@property (nonatomic, strong) AUAudioUnitBus *outputBus;
@property (nonatomic, strong) AUAudioUnitBusArray *outputBusArray;
@property (nonatomic, strong) AUParameterTree *parameterTree;
// Strong copy of the host's MIDI-output block; keeps it alive while the render
// block holds a __bridge pointer to it in _rc->midiSink.
@property (nonatomic, copy, nullable) AUMIDIOutputEventBlock capturedMIDIOut;
@end

@implementation PhaseRingsAudioUnit

@synthesize parameterTree = _parameterTree;

+ (AudioComponentDescription)componentDescription {
    AudioComponentDescription d = {0};
    d.componentType = PhaseRingsAUType;
    d.componentSubType = PhaseRingsAUSubType;
    d.componentManufacturer = PhaseRingsAUManufacturer;
    d.componentFlags = 0;
    d.componentFlagsMask = 0;
    return d;
}

+ (void)registerAUComponent {
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        [self registerSubclass:[PhaseRingsAudioUnit class]
        asComponentDescription:[self componentDescription]
                          name:@"Charles Martin: PhaseRings"
                       version:0x00020000];  // 2.0.0
    });
}

- (instancetype)initWithComponentDescription:(AudioComponentDescription)componentDescription
                                     options:(AudioComponentInstantiationOptions)options
                                       error:(NSError **)outError {
    self = [super initWithComponentDescription:componentDescription options:options error:outError];
    if (!self) return nil;

    _rc = new AURenderCtx();
    _instrumentSettingsState = @{};  // empty -> store falls back to defaults

    // Stereo, non-interleaved float32 — matches HeavyCore's split-channel out.
    AVAudioFormat *format = [[AVAudioFormat alloc] initStandardFormatWithSampleRate:48000.0
                                                                          channels:2];
    NSError *busErr = nil;
    _outputBus = [[AUAudioUnitBus alloc] initWithFormat:format error:&busErr];
    if (!_outputBus) {
        if (outError) *outError = busErr;
        return nil;
    }
    _outputBus.maximumChannelCount = 2;
    _outputBusArray = [[AUAudioUnitBusArray alloc] initWithAudioUnit:self
                                                            busType:AUAudioUnitBusTypeOutput
                                                             busses:@[_outputBus]];

    self.maximumFramesToRender = 4096;

    [self buildParameterTree];

    return self;
}

- (void)dealloc {
    [self freeScratch];
    delete _rc;
}

#pragma mark - Parameters

- (void)buildParameterTree {
    AUParameter *master = [AUParameterTree createParameterWithIdentifier:@"masterVolume"
        name:@"Master Volume" address:PhaseRingsParamMasterVolume
        min:0.0 max:1.0 unit:kAudioUnitParameterUnit_LinearGain unitName:nil
        flags:(kAudioUnitParameterFlag_IsReadable | kAudioUnitParameterFlag_IsWritable)
        valueStrings:nil dependentParameters:nil];
    master.value = 1.0;

    AUParameter *reverb = [AUParameterTree createParameterWithIdentifier:@"reverbVolume"
        name:@"Reverb" address:PhaseRingsParamReverbVolume
        min:0.0 max:1.0 unit:kAudioUnitParameterUnit_LinearGain unitName:nil
        flags:(kAudioUnitParameterFlag_IsReadable | kAudioUnitParameterFlag_IsWritable)
        valueStrings:nil dependentParameters:nil];
    reverb.value = 0.5;

    AUParameter *distort = [AUParameterTree createParameterWithIdentifier:@"distortLevel"
        name:@"Distortion" address:PhaseRingsParamDistortLevel
        min:0.0 max:1.0 unit:kAudioUnitParameterUnit_LinearGain unitName:nil
        flags:(kAudioUnitParameterFlag_IsReadable | kAudioUnitParameterFlag_IsWritable)
        valueStrings:nil dependentParameters:nil];
    distort.value = 0.0;

    AUParameter *effects = [AUParameterTree createParameterWithIdentifier:@"processEffects"
        name:@"Effects" address:PhaseRingsParamProcessEffects
        min:0.0 max:1.0 unit:kAudioUnitParameterUnit_Boolean unitName:nil
        flags:(kAudioUnitParameterFlag_IsReadable | kAudioUnitParameterFlag_IsWritable)
        valueStrings:nil dependentParameters:nil];
    effects.value = 0.0;

    AUParameter *sound = [AUParameterTree createParameterWithIdentifier:@"sound"
        name:@"Sound" address:PhaseRingsParamSound
        min:0.0 max:6.0 unit:kAudioUnitParameterUnit_Indexed unitName:nil
        flags:(kAudioUnitParameterFlag_IsReadable | kAudioUnitParameterFlag_IsWritable)
        valueStrings:@[@"Phase Synthesis", @"String Synthesis", @"Singing Bowls",
                       @"Gongs", @"Crotales", @"Terracotta Pots", @"Marimba"]
        dependentParameters:nil];
    sound.value = 0.0;

    self.parameterTree = [AUParameterTree createTreeWithChildren:@[master, reverb, distort, effects, sound]];

    // Apply parameter changes to the core. Called off the render thread (the
    // setter side); HeavyCore's send paths just enqueue, so this is safe.
    __weak PhaseRingsAudioUnit *weakSelf = self;
    self.parameterTree.implementorValueObserver = ^(AUParameter *param, AUValue value) {
        [weakSelf applyParameter:param.address value:value];
    };
}

- (void)applyParameter:(AUParameterAddress)address value:(AUValue)value {
    HeavyCore *core = self.core;
    if (!core) return;  // re-applied in full on allocateRenderResources
    if (address == PhaseRingsParamSound) {
        NSInteger scheme = lroundf(value);
        if (scheme < 0) scheme = 0;
        if (scheme > 6) scheme = 6;
        [core selectSynth:SynthForScheme(scheme)];
        [core sendFloat:(float)scheme toReceiver:@"selectsound"];
        return;
    }
    NSString *receiver = ReceiverForParam(address);
    if (receiver) {
        [core sendFloat:value toReceiver:receiver];
    }
}

- (void)pushAllParametersToCore {
    for (AUParameter *p in self.parameterTree.allParameters) {
        [self applyParameter:p.address value:p.value];
    }
}

#pragma mark - Full state (session save/restore)

// Carry the non-parameter instrument settings alongside the parameter tree
// that AUAudioUnit's default fullState already serialises. fullStateForDocument
// builds on fullState, so overriding here covers both.
- (NSDictionary<NSString *, id> *)fullState {
    NSMutableDictionary<NSString *, id> *state = [[super fullState] mutableCopy];
    if (!state) state = [NSMutableDictionary dictionary];
    state[kPhaseRingsInstrumentStateKey] = self.instrumentSettingsState ?: @{};
    return state;
}

- (void)setFullState:(NSDictionary<NSString *, id> *)fullState {
    [super setFullState:fullState];  // restores the parameter tree
    id inst = fullState[kPhaseRingsInstrumentStateKey];
    if ([inst isKindOfClass:[NSDictionary class]]) {
        self.instrumentSettingsState = inst;
    }
    void (^handler)(void) = self.instrumentStateRestoredHandler;
    if (handler) {
        dispatch_async(dispatch_get_main_queue(), ^{ handler(); });
    }
}

#pragma mark - Busses

- (AUAudioUnitBusArray *)outputBusses {
    return _outputBusArray;
}

#pragma mark - MIDI out (B3a)

// Advertise a single MIDI output port so hosts expose us as a MIDI source and
// install a MIDIOutputEventBlock.
- (NSArray<NSString *> *)MIDIOutputNames {
    return @[@"PhaseRings"];
}

// Main-thread producer: enqueue a 3-byte message for the render thread to emit.
// Drops the message if the FIFO is full (rather than block the UI).
- (void)sendMIDIOutBytes:(const uint8_t *)bytes length:(NSUInteger)length {
    if (length < 1 || !bytes) return;
    uint32_t head = _rc->midiHead.load(std::memory_order_relaxed);
    uint32_t next = (head + 1) & (kMidiOutCap - 1);
    if (next == _rc->midiTail.load(std::memory_order_acquire)) return;  // full
    _rc->midiOut[head][0] = bytes[0];
    _rc->midiOut[head][1] = (length > 1) ? bytes[1] : 0;
    _rc->midiOut[head][2] = (length > 2) ? bytes[2] : 0;
    _rc->midiHead.store(next, std::memory_order_release);
}

#pragma mark - Render resources

- (BOOL)allocateRenderResourcesAndReturnError:(NSError **)outError {
    if (![super allocateRenderResourcesAndReturnError:outError]) {
        return NO;
    }

    double sampleRate = self.outputBus.format.sampleRate;

    // (Re)build the core at the host's sample rate. Decodes the SoundScraper
    // samples — fine here, this is not the render thread.
    self.core = [[HeavyCore alloc] initWithSampleRate:sampleRate channels:2];

    // Fallback output buffers for hosts that hand us null buffer pointers.
    [self freeScratch];
    uint32_t frames = (uint32_t)self.maximumFramesToRender;
    _rc->scratchFrames = frames;
    _rc->scratch[0] = (float *)calloc(frames, sizeof(float));
    _rc->scratch[1] = (float *)calloc(frames, sizeof(float));

    // Select the synth for the chosen sound scheme, then push all current
    // param values, before publishing the refCon to the render block.
    AUParameter *soundParam = [self.parameterTree parameterWithAddress:PhaseRingsParamSound];
    NSInteger scheme = soundParam ? lroundf(soundParam.value) : 0;
    [self.core selectSynth:SynthForScheme(scheme)];
    [self pushAllParametersToCore];

    // Capture the host's MIDI-output block (set before render begins). The
    // strong property keeps it alive; the render block reads the bridged
    // pointer. Cleared in deallocateRenderResources.
    self.capturedMIDIOut = self.MIDIOutputEventBlock;
    _rc->midiSink.store((__bridge void *)self.capturedMIDIOut, std::memory_order_release);

    _rc->heavyRefCon.store(self.core.renderRefCon, std::memory_order_release);
    return YES;
}

- (void)deallocateRenderResources {
    _rc->heavyRefCon.store(nullptr, std::memory_order_release);
    _rc->midiSink.store(nullptr, std::memory_order_release);
    self.capturedMIDIOut = nil;
    self.core = nil;
    [self freeScratch];
    [super deallocateRenderResources];
}

- (void)freeScratch {
    free(_rc->scratch[0]);
    free(_rc->scratch[1]);
    _rc->scratch[0] = _rc->scratch[1] = nullptr;
    _rc->scratchFrames = 0;
}

#pragma mark - Render

- (AUInternalRenderBlock)internalRenderBlock {
    AURenderCtx *rc = _rc;  // captured by value (stable pointer for the AU's lifetime)
    return ^AUAudioUnitStatus(AudioUnitRenderActionFlags *actionFlags,
                              const AudioTimeStamp *timestamp,
                              AUAudioFrameCount frameCount,
                              NSInteger outputBusNumber,
                              AudioBufferList *outputData,
                              const AURenderEvent *realtimeEventListHead,
                              AURenderPullInputBlock pullInputBlock) {
        // Hosts may hand us a buffer list with null mData and expect us to
        // provide the memory. Point any null buffers at our scratch.
        for (UInt32 i = 0; i < outputData->mNumberBuffers; ++i) {
            if (outputData->mBuffers[i].mData == NULL && i < 2 && rc->scratch[i]) {
                outputData->mBuffers[i].mData = rc->scratch[i];
                outputData->mBuffers[i].mDataByteSize = frameCount * sizeof(float);
            }
        }

        // Emit any queued outgoing MIDI through the host's block (B3a). Drains
        // regardless of audio state so UI gestures still produce MIDI.
        AUMIDIOutputEventBlock midiSink =
            (__bridge AUMIDIOutputEventBlock)rc->midiSink.load(std::memory_order_acquire);
        if (midiSink) {
            uint32_t tail = rc->midiTail.load(std::memory_order_relaxed);
            uint32_t head = rc->midiHead.load(std::memory_order_acquire);
            while (tail != head) {
                midiSink((AUEventSampleTime)timestamp->mSampleTime, 0 /*cable*/, 3, rc->midiOut[tail]);
                tail = (tail + 1) & (kMidiOutCap - 1);
            }
            rc->midiTail.store(tail, std::memory_order_release);
        }

        void *refCon = rc->heavyRefCon.load(std::memory_order_acquire);
        if (refCon == NULL) {
            for (UInt32 i = 0; i < outputData->mNumberBuffers; ++i) {
                if (outputData->mBuffers[i].mData) {
                    memset(outputData->mBuffers[i].mData, 0, outputData->mBuffers[i].mDataByteSize);
                }
            }
            return noErr;
        }

        // Apply incoming MIDI note events to the active context, on this
        // thread, before the FIFO drain + process() in HeavyCoreRenderCallback.
        // Sub-block timing is ignored — fine for these decaying/sustained
        // voices. Legacy AURenderEventMIDI (MIDI 1.0); MIDIEventList (UMP) is
        // not handled.
        for (const AURenderEvent *e = realtimeEventListHead; e != NULL; e = e->head.next) {
            if (e->head.eventType != AURenderEventMIDI) continue;
            const AUMIDIEvent *m = &e->MIDI;
            if (m->length < 2) continue;
            const uint8_t status = m->data[0] & 0xF0;
            const int channel = (m->data[0] & 0x0F) + 1;  // 1-based, matches the app
            if (status == 0x90) {  // note on (velocity 0 == note off)
                const int vel = (m->length >= 3) ? m->data[2] : 0;
                HeavyCoreSendMIDINote(refCon, m->data[1], vel, channel);
            } else if (status == 0x80) {  // note off
                HeavyCoreSendMIDINote(refCon, m->data[1], 0, channel);
            }
        }

        return HeavyCoreRenderCallback(refCon, actionFlags, timestamp,
                                       (UInt32)outputBusNumber, frameCount, outputData);
    };
}

@end
