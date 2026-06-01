//
//  PRMemoryStore.m
//  PhaseRingsKit
//

#import "PRMemoryStore.h"

@implementation PRMemoryStore {
    PRSettings *_settings;
}

@synthesize onChange = _onChange;

- (instancetype)init {
    self = [super init];
    if (self) {
        _settings = [PRSettings defaultSettings];
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
    if (self.onChange) {
        self.onChange([_settings copy]);
    }
}

@end
