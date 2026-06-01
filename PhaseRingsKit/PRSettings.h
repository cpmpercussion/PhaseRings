//
//  PRSettings.h
//  PhaseRingsKit
//
//  Issue #23 (Phase F.1): host-agnostic value object holding the instrument-
//  relevant settings that today live split across the iOS Settings bundle
//  (app) and hardcoded constants (AUv3). Network / MIDI keys stay app-only and
//  are deliberately excluded.
//
//  Note offsets (note1..3) and scale indices (scale1..3) are the raw 0-based
//  values stored under the `note_N` / `scale_N` defaults keys; the absolute
//  MIDI root (BASE_A) is applied by PRCompositionFactory, not stored here.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSettings : NSObject <NSCopying>

@property (nonatomic) NSInteger sound;          // 0..6  (sound scheme)
@property (nonatomic) NSInteger composition;    // 0..4  (0 = custom)
@property (nonatomic) BOOL noteLabels;          // show note labels
@property (nonatomic) BOOL setupLabel;          // show setup description
@property (nonatomic) float masterVolume;       // 0..1.5
@property (nonatomic) float reverbVolume;       // 0..1
@property (nonatomic) float distortLevel;       // 0..1  (AUv3 param; app default 0)
@property (nonatomic) BOOL processEffects;      // process audio effects

// Custom-composition fields (only consulted when composition == 0).
@property (nonatomic) NSInteger note1;          // 0..11 semitone offset from A
@property (nonatomic) NSInteger note2;
@property (nonatomic) NSInteger note3;
@property (nonatomic) NSInteger scale1;         // 0..10 index into the scale list
@property (nonatomic) NSInteger scale2;
@property (nonatomic) NSInteger scale3;

/// Effective defaults, matching the app's -registerDefaults (sound = Singing
/// Bowls, composition = Study in Bowls), used as the baseline for any host that
/// has no persisted value yet.
+ (instancetype)defaultSettings;

@end

NS_ASSUME_NONNULL_END
