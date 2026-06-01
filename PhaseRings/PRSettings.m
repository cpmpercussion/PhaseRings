//
//  PRSettings.m
//  PhaseRingsKit
//

#import "PRSettings.h"

@implementation PRSettings

+ (instancetype)defaultSettings {
    PRSettings *s = [[PRSettings alloc] init];
    // Mirrors AppDelegate -application:didFinishLaunchingWithOptions: registerDefaults.
    s.sound = 2;            // Singing Bowls
    s.composition = 1;      // Study in Bowls
    s.noteLabels = YES;
    s.setupLabel = YES;
    s.masterVolume = 1.0f;
    s.reverbVolume = 0.5f;
    s.distortLevel = 0.0f;  // AUv3 param default; not persisted by the app
    s.processEffects = YES;
    s.note1 = 1;
    s.note2 = 3;
    s.note3 = 4;
    s.scale1 = 3;
    s.scale2 = 8;
    s.scale3 = 9;
    return s;
}

- (id)copyWithZone:(NSZone *)zone {
    PRSettings *c = [[PRSettings allocWithZone:zone] init];
    c.sound = self.sound;
    c.composition = self.composition;
    c.noteLabels = self.noteLabels;
    c.setupLabel = self.setupLabel;
    c.masterVolume = self.masterVolume;
    c.reverbVolume = self.reverbVolume;
    c.distortLevel = self.distortLevel;
    c.processEffects = self.processEffects;
    c.note1 = self.note1;
    c.note2 = self.note2;
    c.note3 = self.note3;
    c.scale1 = self.scale1;
    c.scale2 = self.scale2;
    c.scale3 = self.scale3;
    return c;
}

@end
