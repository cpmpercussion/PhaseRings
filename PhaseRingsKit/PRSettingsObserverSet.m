//
//  PRSettingsObserverSet.m
//  PhaseRingsKit
//

#import "PRSettingsObserverSet.h"

@implementation PRSettingsObserverSet {
    NSMutableArray<NSUUID *> *_tokens;   // registration order
    NSMutableDictionary<NSUUID *, void (^)(PRSettings *)> *_observers;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _tokens = [NSMutableArray array];
        _observers = [NSMutableDictionary dictionary];
    }
    return self;
}

- (id)addObserver:(void (^)(PRSettings *))observer {
    NSUUID *token = [NSUUID UUID];
    [_tokens addObject:token];
    _observers[token] = [observer copy];
    return token;
}

- (void)removeObserver:(id)token {
    if (!token) {
        return;
    }
    [_tokens removeObject:token];
    [_observers removeObjectForKey:token];
}

- (void)notifyAll:(PRSettings *)settings {
    // Snapshot first so an observer adding/removing during notification
    // doesn't mutate the collection mid-iteration.
    for (NSUUID *token in [_tokens copy]) {
        void (^observer)(PRSettings *) = _observers[token];
        if (observer) {
            observer(settings);
        }
    }
}

@end
