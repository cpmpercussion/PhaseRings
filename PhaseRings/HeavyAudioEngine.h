//
//  HeavyAudioEngine.h
//  PhaseRings
//
//  Standalone-app audio driver. Owns the AVAudioSession + RemoteIO output
//  unit and drives a HeavyCore from its render callback. The host-agnostic
//  DSP lives in HeavyCore; this class is the part that does NOT move into
//  the AUv3 extension (the host owns the session and the output unit there).
//  See auv3-plan.md (Phase A).
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <PhaseRingsKit/HeavyCore.h>   // HeavySynth enum + HeavyCore (shared framework)

NS_ASSUME_NONNULL_BEGIN

@interface HeavyAudioEngine : NSObject

- (instancetype)initWithSampleRate:(double)sampleRate channels:(int)channels;

@property (nonatomic, readonly) double sampleRate;
@property (nonatomic, readonly) HeavySynth activeSynth;
@property (nonatomic, getter=isActive) BOOL active;

- (void)selectSynth:(HeavySynth)synth;

- (void)sendFloat:(float)value toReceiver:(NSString *)receiver;
- (void)sendBangToReceiver:(NSString *)receiver;
- (void)sendNoteOn:(int)channel pitch:(int)pitch velocity:(int)velocity;

@end

NS_ASSUME_NONNULL_END
