//
//  PRMemoryStore.m
//  PhaseRingsKit
//

#import "PRMemoryStore.h"
#import "PRSettingsObserverSet.h"

@implementation PRMemoryStore {
    PRSettings *_settings;
    PRSettingsObserverSet *_observers;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _settings = [PRSettings defaultSettings];
        _observers = [[PRSettingsObserverSet alloc] init];
    }
    return self;
}

- (PRSettings *)currentSettings {
    return [_settings copy];
}

- (void)updateSettings:(void (^)(PRSettings *))mutations {
    PRSettings *s = [_settings copy];
    if (mutations) {
        mutations(s);
    }
    _settings = [s copy];
    [_observers notifyAll:[_settings copy]];
}

- (id)addSettingsObserver:(void (^)(PRSettings *))observer {
    return [_observers addObserver:observer];
}

- (void)removeSettingsObserver:(id)token {
    [_observers removeObserver:token];
}

@end
