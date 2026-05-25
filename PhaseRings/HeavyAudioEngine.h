//
//  HeavyAudioEngine.h
//  PhaseRings
//
//  Replaces PdAudioController. Owns the RemoteIO unit and three Heavy
//  contexts (Phase, CircleStrings, SoundScraper); the active synth is
//  selected at runtime. See hvcc-migration-plan.md.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

typedef NS_ENUM(NSInteger, HeavySynth) {
    HeavySynthPhase = 0,
    HeavySynthCircleStrings,
    HeavySynthSoundScraper,
};

NS_ASSUME_NONNULL_BEGIN

@interface HeavyAudioEngine : NSObject

- (instancetype)initWithSampleRate:(double)sampleRate channels:(int)channels;

@property (nonatomic, readonly) AudioUnit audioUnit;
@property (nonatomic, readonly) double sampleRate;
@property (nonatomic, readonly) HeavySynth activeSynth;
@property (nonatomic, getter=isActive) BOOL active;

- (void)selectSynth:(HeavySynth)synth;

- (void)sendFloat:(float)value toReceiver:(NSString *)receiver;
- (void)sendBangToReceiver:(NSString *)receiver;
- (void)sendNoteOn:(int)channel pitch:(int)pitch velocity:(int)velocity;

@end

NS_ASSUME_NONNULL_END
