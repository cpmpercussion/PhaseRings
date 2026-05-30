//
//  PhaseRingsAudioUnit.h
//  PhaseRingsKit
//
//  The PhaseRings instrument as an AUv3 audio unit
//  (kAudioUnitType_MusicDevice, 'aumu'). Wraps a HeavyCore: the
//  internalRenderBlock drains the core's control-event FIFO and runs the
//  active Heavy context. Lives in the shared framework so both the
//  standalone app and the AUv3 app extension instantiate the same unit.
//  See auv3-plan.md (Phase C).
//

#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <PhaseRingsKit/HeavyCore.h>

NS_ASSUME_NONNULL_BEGIN

/// Component identity. Kept in one place so the extension Info.plist and the
/// in-process registration agree. Type 'aumu' = music device (instrument).
extern const OSType PhaseRingsAUType;          // 'aumu'
extern const OSType PhaseRingsAUSubType;       // 'phrg'
extern const OSType PhaseRingsAUManufacturer;  // 'CPMa'

@interface PhaseRingsAudioUnit : AUAudioUnit

/// The DSP core driving this unit. nil until render resources are allocated.
/// The host UI routes touch / note events here (same FIFO the render block
/// drains).
@property (nonatomic, readonly, nullable) HeavyCore *core;

/// AudioComponentDescription for this unit ('aumu' / 'phrg' / 'CPMa').
+ (AudioComponentDescription)componentDescription;

/// Register the subclass in-process so the standalone app can instantiate it
/// without the app extension. Idempotent. The extension registers via its
/// Info.plist instead.
+ (void)registerAUComponent;

@end

NS_ASSUME_NONNULL_END
