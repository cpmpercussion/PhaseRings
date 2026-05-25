//
//  HeavyAudioEngine.mm
//

#import "HeavyAudioEngine.h"
#import <AVFoundation/AVFoundation.h>
#import <atomic>

#import "Heavy_PhaseRing.hpp"
#import "Heavy_CircleStrings.hpp"
#import "Heavy_SoundScraper.hpp"
#import "Heavy_SoundScraper.h"  // table enums

// Names match `read -resize <file> <table>` in the original
// load_sound_files.pd. The table-side names are what hvcc hashes; the file
// names are what AVAudioFile opens.
typedef struct {
    Hv_SoundScraper_Table table;
    NSString *filename;
} HeavySampleMapping;

static const HeavySampleMapping kSoundScraperSamples[] = {
    { HV_SOUNDSCRAPER_TABLE_BOWL,       @"bowl.wav" },
    { HV_SOUNDSCRAPER_TABLE_GONG,       @"gong.wav" },
    { HV_SOUNDSCRAPER_TABLE_CROTALE,    @"crotale.wav" },
    { HV_SOUNDSCRAPER_TABLE_ALMGLOCKEN, @"almglockenC.wav" },
    { HV_SOUNDSCRAPER_TABLE_MARIMBA,    @"marimba.wav" },
    { HV_SOUNDSCRAPER_TABLE_XYLO,       @"xylo.wav" },
};
static const int kNumSoundScraperSamples =
    sizeof(kSoundScraperSamples) / sizeof(kSoundScraperSamples[0]);

@interface HeavyAudioEngine () {
    // Three preconstructed contexts; the render callback consults the atomic
    // pointer below. We keep them all live so synth switches never tear down
    // an in-flight render block.
    HeavyContextInterface *_phase;
    HeavyContextInterface *_strings;
    HeavyContextInterface *_soundscraper;
    std::atomic<HeavyContextInterface *> _current;

    AudioUnit _audioUnit;
    int _channels;

    // Decoded mono float32 PCM at engine sample rate, keyed by table enum.
    NSMutableDictionary<NSNumber *, NSData *> *_sampleCache;
}
@end

#pragma mark - C glue

static OSStatus HeavyRenderCallback(void *inRefCon,
                                    AudioUnitRenderActionFlags *ioActionFlags,
                                    const AudioTimeStamp *inTimeStamp,
                                    UInt32 inBusNumber,
                                    UInt32 inNumberFrames,
                                    AudioBufferList *ioData) {
    auto *slot = (std::atomic<HeavyContextInterface *> *)inRefCon;
    HeavyContextInterface *ctx = slot->load(std::memory_order_acquire);
    if (!ctx || !ioData || ioData->mNumberBuffers == 0) {
        for (UInt32 i = 0; i < (ioData ? ioData->mNumberBuffers : 0); ++i) {
            memset(ioData->mBuffers[i].mData, 0, ioData->mBuffers[i].mDataByteSize);
        }
        return noErr;
    }
    // Non-interleaved float32, one buffer per channel.
    float *outs[2] = { nullptr, nullptr };
    for (UInt32 i = 0; i < ioData->mNumberBuffers && i < 2; ++i) {
        outs[i] = (float *)ioData->mBuffers[i].mData;
    }
    ctx->process(nullptr, outs, (int)inNumberFrames);
    return noErr;
}

static void HeavyPrintHook(HeavyContextInterface *ctx,
                           const char *receiverName,
                           const char *message,
                           const HvMessage *m) {
    NSLog(@"Heavy[%s]: %s", receiverName ?: "?", message ?: "");
}

#pragma mark -

@implementation HeavyAudioEngine

- (instancetype)initWithSampleRate:(double)sampleRate channels:(int)channels {
    self = [super init];
    if (!self) return nil;

    _sampleRate = sampleRate;
    _channels = channels;
    _activeSynth = (HeavySynth)-1;  // forces a real switch on first selectSynth:
    _current.store(nullptr, std::memory_order_release);
    _sampleCache = [NSMutableDictionary dictionary];

    [self configureSession];
    [self buildAudioUnit];
    [self decodeSoundScraperSamples];

    return self;
}

- (void)dealloc {
    if (_audioUnit) {
        AudioOutputUnitStop(_audioUnit);
        AudioUnitUninitialize(_audioUnit);
        AudioComponentInstanceDispose(_audioUnit);
    }
    delete _phase;
    delete _strings;
    delete _soundscraper;
}

#pragma mark - Audio session

- (void)configureSession {
    AVAudioSession *session = [AVAudioSession sharedInstance];
    NSError *err = nil;
    // Match what PdAudioController used: Playback + MixWithOthers (the latter
    // is required for IAA hosts to coexist with us). On hardware iPads since
    // iOS 17 the session is sometimes pre-touched by other subsystems, so we
    // best-effort and log any failure rather than asserting.
    if (![session setCategory:AVAudioSessionCategoryPlayback
                  withOptions:AVAudioSessionCategoryOptionMixWithOthers
                        error:&err]) {
        NSLog(@"HeavyAudioEngine: setCategory failed: %@", err);
    }
    err = nil;
    if (![session setPreferredSampleRate:_sampleRate error:&err]) {
        NSLog(@"HeavyAudioEngine: setPreferredSampleRate failed: %@", err);
    }
    err = nil;
    if (![session setActive:YES error:&err]) {
        NSLog(@"HeavyAudioEngine: session activate failed: %@", err);
    }
}

#pragma mark - AudioUnit setup

- (void)buildAudioUnit {
    AudioComponentDescription desc = {0};
    desc.componentType = kAudioUnitType_Output;
    desc.componentSubType = kAudioUnitSubType_RemoteIO;
    desc.componentManufacturer = kAudioUnitManufacturer_Apple;

    AudioComponent comp = AudioComponentFindNext(NULL, &desc);
    NSAssert(comp, @"RemoteIO component not found");
    OSStatus err = AudioComponentInstanceNew(comp, &_audioUnit);
    NSAssert(err == noErr, @"AudioComponentInstanceNew: %d", (int)err);

    // Non-interleaved float32 so Heavy's split-channel output maps directly
    // to the AudioBufferList we hand it.
    AudioStreamBasicDescription fmt = {0};
    fmt.mSampleRate = _sampleRate;
    fmt.mFormatID = kAudioFormatLinearPCM;
    fmt.mFormatFlags = kAudioFormatFlagIsFloat
                    | kAudioFormatFlagIsNonInterleaved
                    | kAudioFormatFlagsNativeEndian
                    | kAudioFormatFlagIsPacked;
    fmt.mBytesPerPacket = sizeof(float);
    fmt.mFramesPerPacket = 1;
    fmt.mBytesPerFrame = sizeof(float);
    fmt.mChannelsPerFrame = _channels;
    fmt.mBitsPerChannel = 32;

    err = AudioUnitSetProperty(_audioUnit,
                               kAudioUnitProperty_StreamFormat,
                               kAudioUnitScope_Input, 0,
                               &fmt, sizeof(fmt));
    NSAssert(err == noErr, @"set stream format: %d", (int)err);

    AURenderCallbackStruct cb = { HeavyRenderCallback, &_current };
    err = AudioUnitSetProperty(_audioUnit,
                               kAudioUnitProperty_SetRenderCallback,
                               kAudioUnitScope_Input, 0,
                               &cb, sizeof(cb));
    NSAssert(err == noErr, @"set render callback: %d", (int)err);

    err = AudioUnitInitialize(_audioUnit);
    NSAssert(err == noErr, @"AudioUnitInitialize: %d", (int)err);
}

#pragma mark - Sample decoding (SoundScraper)

- (void)decodeSoundScraperSamples {
    for (int i = 0; i < kNumSoundScraperSamples; ++i) {
        HeavySampleMapping m = kSoundScraperSamples[i];
        NSData *pcm = [self decodeWavToMonoFloat32:m.filename];
        if (pcm) {
            _sampleCache[@(m.table)] = pcm;
        } else {
            NSLog(@"HeavyAudioEngine: failed to decode sample %@", m.filename);
        }
    }
}

- (NSData *)decodeWavToMonoFloat32:(NSString *)filename {
    NSURL *url = [[NSBundle mainBundle] URLForResource:[filename stringByDeletingPathExtension]
                                         withExtension:[filename pathExtension]];
    if (!url) return nil;

    NSError *err = nil;
    AVAudioFile *file = [[AVAudioFile alloc] initForReading:url
                                                      error:&err];
    if (!file) {
        NSLog(@"HeavyAudioEngine: open %@ failed: %@", filename, err);
        return nil;
    }

    AVAudioFormat *outFmt = [[AVAudioFormat alloc]
        initWithCommonFormat:AVAudioPCMFormatFloat32
                  sampleRate:_sampleRate
                    channels:1
                 interleaved:NO];

    AVAudioConverter *converter = [[AVAudioConverter alloc]
        initFromFormat:file.processingFormat toFormat:outFmt];
    if (!converter) return nil;

    AVAudioFrameCount inFrames = (AVAudioFrameCount)file.length;
    AVAudioPCMBuffer *inBuf = [[AVAudioPCMBuffer alloc]
        initWithPCMFormat:file.processingFormat frameCapacity:inFrames];
    if (![file readIntoBuffer:inBuf error:&err]) {
        NSLog(@"HeavyAudioEngine: read %@ failed: %@", filename, err);
        return nil;
    }

    double ratio = _sampleRate / file.processingFormat.sampleRate;
    AVAudioFrameCount outCap = (AVAudioFrameCount)ceil(inBuf.frameLength * ratio) + 16;
    AVAudioPCMBuffer *outBuf = [[AVAudioPCMBuffer alloc]
        initWithPCMFormat:outFmt frameCapacity:outCap];

    __block BOOL consumed = NO;
    AVAudioConverterInputBlock input = ^AVAudioBuffer *(AVAudioPacketCount inNumberOfPackets,
                                                        AVAudioConverterInputStatus *outStatus) {
        if (consumed) {
            *outStatus = AVAudioConverterInputStatus_EndOfStream;
            return nil;
        }
        consumed = YES;
        *outStatus = AVAudioConverterInputStatus_HaveData;
        return inBuf;
    };
    AVAudioConverterOutputStatus status = [converter convertToBuffer:outBuf
                                                                error:&err
                                                   withInputFromBlock:input];
    if (status == AVAudioConverterOutputStatus_Error) {
        NSLog(@"HeavyAudioEngine: convert %@ failed: %@", filename, err);
        return nil;
    }

    NSUInteger byteCount = outBuf.frameLength * sizeof(float);
    return [NSData dataWithBytes:outBuf.floatChannelData[0] length:byteCount];
}

- (void)loadSamplesIntoContext:(HeavyContextInterface *)ctx {
    // The tables are declared [table NAME 200000 @hv_table] in the patch and
    // the percsampler ramps a line~ across the full allocation with hard-coded
    // sample-rate constants. Shrinking the table via setLengthForTable made
    // tabread4~ read past the new (smaller) bound and trip its assert in
    // debug builds. Keep the 200k allocation; just memcpy the decoded PCM
    // into the head of the buffer and leave the tail zeroed.
    for (int i = 0; i < kNumSoundScraperSamples; ++i) {
        Hv_SoundScraper_Table tbl = kSoundScraperSamples[i].table;
        NSData *pcm = _sampleCache[@(tbl)];
        if (!pcm) continue;
        float *dst = ctx->getBufferForTable((hv_uint32_t)tbl);
        if (!dst) {
            NSLog(@"HeavyAudioEngine: getBufferForTable nil for 0x%X", tbl);
            continue;
        }
        int allocFrames = ctx->getLengthForTable((hv_uint32_t)tbl);
        NSUInteger bytes = pcm.length;
        if ((int)(bytes / sizeof(float)) > allocFrames) {
            bytes = allocFrames * sizeof(float);
        }
        memcpy(dst, pcm.bytes, bytes);
    }
}

#pragma mark - Synth selection

- (void)selectSynth:(HeavySynth)synth {
    if (synth == _activeSynth && _current.load(std::memory_order_relaxed) != nullptr) return;

    HeavyContextInterface *ctx = nullptr;
    switch (synth) {
        case HeavySynthPhase:
            if (!_phase) {
                _phase = new Heavy_PhaseRing(_sampleRate);
                _phase->setPrintHook(HeavyPrintHook);
            }
            ctx = _phase;
            break;
        case HeavySynthCircleStrings:
            if (!_strings) {
                _strings = new Heavy_CircleStrings(_sampleRate);
                _strings->setPrintHook(HeavyPrintHook);
            }
            ctx = _strings;
            break;
        case HeavySynthSoundScraper:
            if (!_soundscraper) {
                _soundscraper = new Heavy_SoundScraper(_sampleRate);
                _soundscraper->setPrintHook(HeavyPrintHook);
                [self loadSamplesIntoContext:_soundscraper];
            }
            ctx = _soundscraper;
            break;
    }
    if (!ctx) return;

    _activeSynth = synth;
    _current.store(ctx, std::memory_order_release);
}

#pragma mark - Active state

- (BOOL)isActive {
    UInt32 running = 0, size = sizeof(running);
    AudioUnitGetProperty(_audioUnit,
                         kAudioOutputUnitProperty_IsRunning,
                         kAudioUnitScope_Global, 0,
                         &running, &size);
    return running != 0;
}

- (void)setActive:(BOOL)active {
    OSStatus err = active ? AudioOutputUnitStart(_audioUnit) : AudioOutputUnitStop(_audioUnit);
    if (err != noErr) {
        NSLog(@"HeavyAudioEngine: %@ failed: %d", active ? @"start" : @"stop", (int)err);
    }
}

#pragma mark - Message sends

- (HeavyContextInterface *)currentForSend {
    return _current.load(std::memory_order_acquire);
}

- (void)sendFloat:(float)value toReceiver:(NSString *)receiver {
    HeavyContextInterface *ctx = [self currentForSend];
    if (!ctx) return;
    ctx->sendFloatToReceiver(hv_stringToHash(receiver.UTF8String), value);
}

- (void)sendBangToReceiver:(NSString *)receiver {
    HeavyContextInterface *ctx = [self currentForSend];
    if (!ctx) return;
    ctx->sendBangToReceiver(hv_stringToHash(receiver.UTF8String));
}

- (void)sendNoteOn:(int)channel pitch:(int)pitch velocity:(int)velocity {
    HeavyContextInterface *ctx = [self currentForSend];
    if (!ctx) return;
    // Heavy routes [notein] through the __hv_notein receiver, expecting
    // (pitch, velocity, channel) as a 3-float message.
    static const hv_uint32_t kNoteinHash = 0x67E37CA3;
    ctx->sendMessageToReceiverV(kNoteinHash, 0.0, "fff",
                                (float)pitch, (float)velocity, (float)channel);
}

@end
