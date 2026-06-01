//
//  PRAudioUnitStore.h
//  PhaseRingsKit
//
//  Issue #23 (Phase F.4): PRSettingsStore backed by a PhaseRingsAudioUnit. The
//  five audio params (master/reverb/distort volumes, process-effects, sound)
//  read and write through the AU parameter tree — so host automation and
//  session state stay consistent — while the non-parameter settings
//  (composition / notes / scales / labels) live in the AU's
//  `instrumentSettingsState` and round-trip through `fullState`.
//
//  The AUv3 view controller injects one of these as the shared
//  InstrumentViewController's settingsStore, replacing the default in-memory
//  PRMemoryStore used before F.4.
//

#import <Foundation/Foundation.h>
#import "PRSettingsStore.h"

NS_ASSUME_NONNULL_BEGIN

@class PhaseRingsAudioUnit;

@interface PRAudioUnitStore : NSObject <PRSettingsStore>

- (instancetype)initWithAudioUnit:(PhaseRingsAudioUnit *)audioUnit NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
