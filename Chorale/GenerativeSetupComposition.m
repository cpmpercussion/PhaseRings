//
//  GenerativeSetupComposition.m
//  SingingBowls
//
//  Created by Charles Martin on 19/06/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#import "GenerativeSetupComposition.h"
#import "ScaleMaker.h"
#import "SingingBowlSetup.h"

#define SETUP_SIZE @[@3,@5,@8,@11]
#define NUMBER_SETUPS_PER_ROOT 2
#define RANGE 36
#define DEFAULT_ROOTS @[@34,@36,@37]
#define DEFAULT_SCALES @[@"LYDIAN",@"MIXOFLATSIX",@"OCTATONIC"]

@implementation GenerativeSetupComposition

- (GenerativeSetupComposition *) initWithRootNotes:(NSArray *)roots andScales:(NSArray *)scales {
    self = [super init];
    self.looping = YES;
    self.rootNotes = roots;
    self.scales = scales;
    self.contents = [self generateSetups];
    self.setupDescriptions = [self generateDescriptions];
    return self;
}


- (GenerativeSetupComposition *) init {
    self = [super init];
    self.looping = YES;
    self.rootNotes = DEFAULT_ROOTS;
    self.scales = DEFAULT_SCALES;
    self.contents = [self generateSetups];
    self.setupDescriptions = [self generateDescriptions];
    return self;
}

-(NSArray *) generateDescriptions {
    NSMutableArray *result = [[NSMutableArray alloc] init];
    for (int i = 0; i<[self.rootNotes count]; i++) {
        NSString *note = [SingingBowlSetup noteNameForMidiNumber:[[self.rootNotes objectAtIndex:i] intValue]];
        NSString *scale = [ScaleMaker prettyScaleString:[self.scales objectAtIndex:i]];
        for (int j = 0; j< NUMBER_SETUPS_PER_ROOT; j++) {
            [result addObject: [NSString stringWithFormat:@"%@ %@",note,scale]];
        }
    }
    return [NSArray arrayWithArray:result];
}

-(NSArray *) generateSetups {
    NSMutableArray *result = [[NSMutableArray alloc] init];
    for (int i = 0; i<[self.rootNotes count]; i++) {
        NSArray *setupSizes = [self randomSubsetOfNumbers:NUMBER_SETUPS_PER_ROOT fromArray:SETUP_SIZE];
        NSArray *scale = [self generateScale:[self.scales objectAtIndex:i] fromRoot:[[self.rootNotes objectAtIndex:i] intValue] toRange:RANGE];
        scale = [self randomSubsetOfNumbers:[[self largestNumberInArray:setupSizes] intValue] fromArray:scale];
        for (NSNumber *pitches in setupSizes) {
            NSArray *setup = [self randomSubsetOfNumbers:[pitches intValue] fromArray:scale];
            [result addObject:setup];
        }
    }
    return [NSArray arrayWithArray:result];
}

- (NSArray *) randomSubsetOfNumbers:(int)k fromArray:(NSArray *)array {
    NSMutableArray *input = [NSMutableArray arrayWithArray:array];
    NSMutableArray *result = [[NSMutableArray alloc] init];
    for (int i = 0; i < k; i++) {
        NSNumber *pickedObject = (NSNumber *)[input objectAtIndex:arc4random_uniform((int)[input count])];
        [result addObject:pickedObject];
        [input removeObject:pickedObject];
    }
    return  [result sortedArrayUsingSelector: @selector(compare:)];
}

- (NSNumber *) largestNumberInArray:(NSArray *)array {
    NSArray *newArray = [array sortedArrayUsingSelector:@selector(compare:)];
    return (NSNumber *)[newArray objectAtIndex:[array count] -1];
}


- (NSArray *) generateScale:(NSString *)scaleName fromRoot:(int)root toRange:(int)range {
    NSMutableArray *result = [[NSMutableArray alloc] init];
    for (int i = 0; i<range; i++) {
        int note = [ScaleMaker noteForScale:scaleName withBase:root withNote:i];
        [result addObject:[NSNumber numberWithInt:note]];
    }
    return [NSArray arrayWithArray:result];
}

@end
