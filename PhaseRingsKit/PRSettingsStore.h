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
/// settings; whatever it leaves is persisted by the host and then broadcast to
/// every registered observer.
- (void)updateSettings:(void (^)(PRSettings *settings))mutations;

/// Register to be notified after the settings change (whether via
/// `updateSettings:` or an external edit the host detects). The block carries a
/// snapshot of the new state. Returns an opaque token for
/// `removeSettingsObserver:`. Multiple observers may be registered at once
/// (issue #37 — the instrument surface and the settings sheet's model observe
/// concurrently; the old single-slot `onChange` let one clobber the other).
- (id)addSettingsObserver:(void (^)(PRSettings *settings))observer;

/// Unregister a token from `addSettingsObserver:`. `nil` is a no-op.
- (void)removeSettingsObserver:(nullable id)token;

@end

NS_ASSUME_NONNULL_END
