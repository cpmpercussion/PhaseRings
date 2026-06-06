//
//  PRSettingsObserverSet.h
//  PhaseRingsKit
//
//  Issue #37: shared observer bookkeeping for PRSettingsStore implementations.
//  Replaces the protocol's old single-slot `onChange` callback, which a second
//  observer silently clobbered (the settings sheet's PRSettingsModel stole the
//  instrument surface's slot, permanently disconnecting it).
//

#import <Foundation/Foundation.h>
#import "PRSettings.h"

NS_ASSUME_NONNULL_BEGIN

/// Token-keyed collection of settings observers. Each store owns one and
/// forwards its add/remove/notify. Observers are notified in registration
/// order. Not thread-safe — stores fire on the main thread.
@interface PRSettingsObserverSet : NSObject

/// Register an observer block; returns an opaque token for `removeObserver:`.
- (id)addObserver:(void (^)(PRSettings *settings))observer;

/// Unregister a token from `addObserver:`. `nil` or an unknown token is a no-op.
- (void)removeObserver:(nullable id)token;

/// Invoke every registered observer with `settings`.
- (void)notifyAll:(PRSettings *)settings;

@end

NS_ASSUME_NONNULL_END
