//
//  PRSettingsStore.h
//  PhaseRingsKit
//
//  Issue #23 (Phase F.1): host-agnostic persistence seam. The shared instrument
//  surface and settings UI read/write through this protocol and never know
//  whether they're in the standalone app (NSUserDefaults) or the AUv3 extension
//  (AU parameter tree + fullState).
//

#import <Foundation/Foundation.h>
#import "PRSettings.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PRSettingsStore <NSObject>

/// A snapshot of the current settings. Always a fresh copy the caller may mutate
/// without affecting the store.
- (PRSettings *)currentSettings;

/// Mutate-and-persist. The block receives a mutable copy of the current
/// settings; whatever it leaves is persisted by the host and then broadcast via
/// `onChange`.
- (void)updateSettings:(void (^)(PRSettings *settings))mutations;

/// Fired after the settings change (whether via `updateSettings:` or an external
/// edit the host detects). Carries a snapshot of the new state.
@property (nonatomic, copy, nullable) void (^onChange)(PRSettings *settings);

@end

NS_ASSUME_NONNULL_END
