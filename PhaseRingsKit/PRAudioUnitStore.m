//
//  PRAudioUnitStore.m
//  PhaseRingsKit
//

#import "PRAudioUnitStore.h"
#import "PRSettings.h"
#import "PhaseRingsAudioUnit.h"
#import <AudioToolbox/AudioToolbox.h>

// Parameter addresses — must match PhaseRingsAudioUnit's parameter tree.
typedef NS_ENUM(AUParameterAddress, PRAUParam) {
    PRAUParamMasterVolume = 0,
    PRAUParamReverbVolume,
    PRAUParamDistortLevel,
    PRAUParamProcessEffects,
    PRAUParamSound,
};

// Keys for the non-parameter settings persisted in the AU's
// instrumentSettingsState dictionary.
static NSString *const kComposition = @"composition";
static NSString *const kNoteLabels  = @"noteLabels";
static NSString *const kSetupLabel  = @"setupLabel";
static NSString *const kNote1       = @"note1";
static NSString *const kNote2       = @"note2";
static NSString *const kNote3       = @"note3";
static NSString *const kScale1      = @"scale1";
static NSString *const kScale2      = @"scale2";
static NSString *const kScale3      = @"scale3";

@interface PRAudioUnitStore ()
@property (nonatomic, weak) PhaseRingsAudioUnit *audioUnit;
@end

@implementation PRAudioUnitStore

@synthesize onChange = _onChange;

- (instancetype)initWithAudioUnit:(PhaseRingsAudioUnit *)audioUnit {
    self = [super init];
    if (self) {
        _audioUnit = audioUnit;
        // Rebroadcast host state restores (fullState) to the UI.
        __weak typeof(self) weakSelf = self;
        audioUnit.instrumentStateRestoredHandler = ^{
            typeof(self) strongSelf = weakSelf;
            if (strongSelf.onChange) {
                strongSelf.onChange([strongSelf currentSettings]);
            }
        };
    }
    return self;
}

- (float)param:(AUParameterAddress)address {
    return [self.audioUnit.parameterTree parameterWithAddress:address].value;
}

- (void)setParam:(AUParameterAddress)address to:(float)value {
    [self.audioUnit.parameterTree parameterWithAddress:address].value = (AUValue)value;
}

- (PRSettings *)currentSettings {
    // Base on the instrument defaults so any key the AU hasn't stored yet (a
    // fresh session, or an older saved state) gets a sensible value.
    PRSettings *s = [PRSettings defaultSettings];

    s.masterVolume   = [self param:PRAUParamMasterVolume];
    s.reverbVolume   = [self param:PRAUParamReverbVolume];
    s.distortLevel   = [self param:PRAUParamDistortLevel];
    s.processEffects = [self param:PRAUParamProcessEffects] >= 0.5f;
    s.sound          = lroundf([self param:PRAUParamSound]);

    NSDictionary<NSString *, NSNumber *> *st = self.audioUnit.instrumentSettingsState;
    if (st[kComposition]) s.composition = st[kComposition].integerValue;
    if (st[kNoteLabels])  s.noteLabels  = st[kNoteLabels].boolValue;
    if (st[kSetupLabel])  s.setupLabel  = st[kSetupLabel].boolValue;
    if (st[kNote1])       s.note1       = st[kNote1].integerValue;
    if (st[kNote2])       s.note2       = st[kNote2].integerValue;
    if (st[kNote3])       s.note3       = st[kNote3].integerValue;
    if (st[kScale1])      s.scale1      = st[kScale1].integerValue;
    if (st[kScale2])      s.scale2      = st[kScale2].integerValue;
    if (st[kScale3])      s.scale3      = st[kScale3].integerValue;
    return s;
}

- (void)updateSettings:(void (^)(PRSettings *))mutations {
    PRSettings *s = [self currentSettings];
    if (mutations) {
        mutations(s);
    }

    // Audio params -> the tree (fires the AU's implementorValueObserver, which
    // applies them to the core; keeps host automation / state consistent).
    [self setParam:PRAUParamMasterVolume   to:s.masterVolume];
    [self setParam:PRAUParamReverbVolume   to:s.reverbVolume];
    [self setParam:PRAUParamDistortLevel   to:s.distortLevel];
    [self setParam:PRAUParamProcessEffects to:(s.processEffects ? 1.0f : 0.0f)];
    [self setParam:PRAUParamSound          to:(float)s.sound];

    // Non-parameter settings -> the AU's serialisable dictionary.
    self.audioUnit.instrumentSettingsState = @{
        kComposition: @(s.composition),
        kNoteLabels:  @(s.noteLabels),
        kSetupLabel:  @(s.setupLabel),
        kNote1:       @(s.note1),
        kNote2:       @(s.note2),
        kNote3:       @(s.note3),
        kScale1:      @(s.scale1),
        kScale2:      @(s.scale2),
        kScale3:      @(s.scale3),
    };

    if (self.onChange) {
        self.onChange([s copy]);
    }
}

@end
