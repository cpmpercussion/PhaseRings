//
//  HeavyCore.h
//  PhaseRings
//
//  Host-agnostic Heavy DSP core. Owns the three Heavy contexts (Phase,
//  CircleStrings, SoundScraper), decodes/loads the SoundScraper samples,
//  routes control messages to the active context, and provides the
//  realtime-safe render entry point.
//
//  This class makes NO assumptions about who drives audio: it neither
//  touches AVAudioSession nor creates an output unit. The standalone app
//  wraps it in HeavyAudioEngine (RemoteIO + session); the forthcoming AUv3
//  extension will drive it from an AUAudioUnit render block. See
//  auv3-plan.md (Phase A).
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

typedef NS_ENUM(NSInteger, HeavySynth) {
    HeavySynthPhase = 0,
    HeavySynthCircleStrings,
    HeavySynthSoundScraper,
};

NS_ASSUME_NONNULL_BEGIN

@interface HeavyCore : NSObject

- (instancetype)initWithSampleRate:(double)sampleRate channels:(int)channels;

@property (nonatomic, readonly) double sampleRate;
@property (nonatomic, readonly) HeavySynth activeSynth;

/// Swap the active synth. Heavy contexts are constructed lazily and kept
/// live; the active one is published through an atomic so an in-flight
/// render block never tears down under itself.
- (void)selectSynth:(HeavySynth)synth;

- (void)sendFloat:(float)value toReceiver:(NSString *)receiver;
- (void)sendBangToReceiver:(NSString *)receiver;
- (void)sendNoteOn:(int)channel pitch:(int)pitch velocity:(int)velocity;

/// Opaque pointer to the internal atomic active-context slot, to be passed
/// as the `inRefCon` of HeavyCoreRenderCallback. Stable for the lifetime of
/// the receiver.
@property (nonatomic, readonly) void *renderRefCon;

@end

NS_ASSUME_NONNULL_END

/// Realtime-safe render callback. `inRefCon` must be a HeavyCore's
/// `renderRefCon`. Writes non-interleaved float32, one buffer per channel.
/// Wire this directly as an AURenderCallback (standalone RemoteIO) or call
/// it from an AUAudioUnit internalRenderBlock (AUv3). No ObjC, locks, or
/// allocation on this path.
#ifdef __cplusplus
extern "C" {
#endif
OSStatus HeavyCoreRenderCallback(void *inRefCon,
                                 AudioUnitRenderActionFlags *ioActionFlags,
                                 const AudioTimeStamp *inTimeStamp,
                                 UInt32 inBusNumber,
                                 UInt32 inNumberFrames,
                                 AudioBufferList *ioData);

/// Send a MIDI note to the active context's [notein] (note-off = velocity 0).
/// Realtime-safe: loads the context and enqueues into Heavy's message queue
/// with no lock or allocation of our own. Call ONLY from the render thread,
/// before HeavyCoreRenderCallback. `inRefCon` must be a HeavyCore's
/// `renderRefCon`.
void HeavyCoreSendMIDINote(void *inRefCon, int pitch, int velocity, int channel);
#ifdef __cplusplus
}
#endif
