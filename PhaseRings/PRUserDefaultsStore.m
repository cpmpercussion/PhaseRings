//
//  PRUserDefaultsStore.m
//  PhaseRings
//

#import "PRUserDefaultsStore.h"
#import <PhaseRingsKit/PRSettingsObserverSet.h>

// Existing NSUserDefaults keys (see Settings.bundle + AppDelegate registerDefaults).
static NSString *const kSound          = @"sound";
static NSString *const kComposition    = @"composition";
static NSString *const kNoteLabels     = @"note_labels";
static NSString *const kSetupLabel     = @"setup_label";
static NSString *const kMasterVolume   = @"master_volume";
static NSString *const kReverbVolume   = @"reverb_volume";
static NSString *const kDistortLevel   = @"distort_level"; // not registered; defaults to 0
static NSString *const kProcessEffects = @"process_effects";
static NSString *const kNote1          = @"note_1";
static NSString *const kNote2          = @"note_2";
static NSString *const kNote3          = @"note_3";
static NSString *const kScale1         = @"scale_1";
static NSString *const kScale2         = @"scale_2";
static NSString *const kScale3         = @"scale_3";

@interface PRUserDefaultsStore ()
@property (nonatomic, strong) NSUserDefaults *defaults;
@property (nonatomic, strong) PRSettingsObserverSet *observers;
@end

@implementation PRUserDefaultsStore

- (instancetype)init {
    return [self initWithUserDefaults:[NSUserDefaults standardUserDefaults]];
}

- (instancetype)initWithUserDefaults:(NSUserDefaults *)defaults {
    self = [super init];
    if (self) {
        _defaults = defaults;
        _observers = [[PRSettingsObserverSet alloc] init];
    }
    return self;
}

- (id)addSettingsObserver:(void (^)(PRSettings *))observer {
    return [self.observers addObserver:observer];
}

- (void)removeSettingsObserver:(id)token {
    [self.observers removeObserver:token];
}

- (PRSettings *)currentSettings {
    NSUserDefaults *d = self.defaults;
    PRSettings *s = [[PRSettings alloc] init];
    s.sound          = [d integerForKey:kSound];
    s.composition    = [d integerForKey:kComposition];
    s.noteLabels     = [d boolForKey:kNoteLabels];
    s.setupLabel     = [d boolForKey:kSetupLabel];
    s.masterVolume   = [d floatForKey:kMasterVolume];
    s.reverbVolume   = [d floatForKey:kReverbVolume];
    s.distortLevel   = [d floatForKey:kDistortLevel];
    s.processEffects = [d boolForKey:kProcessEffects];
    s.note1          = [d integerForKey:kNote1];
    s.note2          = [d integerForKey:kNote2];
    s.note3          = [d integerForKey:kNote3];
    s.scale1         = [d integerForKey:kScale1];
    s.scale2         = [d integerForKey:kScale2];
    s.scale3         = [d integerForKey:kScale3];
    return s;
}

- (void)updateSettings:(void (^)(PRSettings *))mutations {
    PRSettings *s = [self currentSettings];
    if (mutations) {
        mutations(s);
    }
    NSUserDefaults *d = self.defaults;
    [d setInteger:s.sound          forKey:kSound];
    [d setInteger:s.composition    forKey:kComposition];
    [d setBool:s.noteLabels        forKey:kNoteLabels];
    [d setBool:s.setupLabel        forKey:kSetupLabel];
    [d setFloat:s.masterVolume     forKey:kMasterVolume];
    [d setFloat:s.reverbVolume     forKey:kReverbVolume];
    [d setFloat:s.distortLevel     forKey:kDistortLevel];
    [d setBool:s.processEffects    forKey:kProcessEffects];
    [d setInteger:s.note1          forKey:kNote1];
    [d setInteger:s.note2          forKey:kNote2];
    [d setInteger:s.note3          forKey:kNote3];
    [d setInteger:s.scale1         forKey:kScale1];
    [d setInteger:s.scale2         forKey:kScale2];
    [d setInteger:s.scale3         forKey:kScale3];

    [self.observers notifyAll:[s copy]];
}

@end
