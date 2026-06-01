//
//  PRCompositionFactory.m
//  PhaseRingsKit
//

#import "PRCompositionFactory.h"
#import "GenerativeSetupComposition.h"

// A below two-below-middle-C; custom note offsets (0..11) are added to this.
// Matches the legacy BASE_A in ViewController.
static const NSInteger PRBaseA = 33;

@implementation PRCompositionFactory

+ (GenerativeSetupComposition *)compositionForSettings:(PRSettings *)settings {
    NSArray *scalesList = @[@"IONIAN", @"DORIAN", @"PHRYGIAN", @"LYDIAN",
                            @"MIXOLYDIAN", @"AEOLIAN", @"LOCHRIAN",
                            @"LYDIANSHARPFIVE", @"MIXOFLATSIX", @"OCTATONIC",
                            @"WHOLETONE"];

    NSArray *notes;
    NSArray *scales;
    switch (settings.composition) {
        case 1: // Study in Bowls
            notes = @[@41, @42, @48];
            scales = @[@"MIXOLYDIAN", @"LYDIAN", @"LYDIANSHARPFIVE"];
            break;
        case 2: // Amores
            notes = @[@36, @37, @41];
            scales = @[@"MIXOFLATSIX", @"OCTATONIC", @"WHOLETONE"];
            break;
        case 3: // MixoSteps
            notes = @[@36, @38, @41];
            scales = @[@"MIXOLYDIAN", @"MIXOLYDIAN", @"MIXOLYDIAN"];
            break;
        case 4: // Scheimpflug Principle
            notes = @[@36, @38, @40];
            scales = @[@"WHOLETONE", @"MIXOFLATSIX", @"LOCHRIAN"];
            break;
        default: { // 0 = custom composition
            NSInteger note1 = PRBaseA + settings.note1;
            NSInteger note2 = PRBaseA + settings.note2;
            NSInteger note3 = PRBaseA + settings.note3;
            notes = @[@(note1), @(note2), @(note3)];
            scales = @[scalesList[settings.scale1],
                       scalesList[settings.scale2],
                       scalesList[settings.scale3]];
            break;
        }
    }
    return [[GenerativeSetupComposition alloc] initWithRootNotes:notes andScales:scales];
}

@end
