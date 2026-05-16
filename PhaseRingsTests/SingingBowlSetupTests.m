//
//  SingingBowlSetupTests.m
//  PhaseRingsTests
//

#import <XCTest/XCTest.h>
#import "SingingBowlSetup.h"

@interface SingingBowlSetupTests : XCTestCase
@end

@implementation SingingBowlSetupTests

- (SingingBowlSetup *)setupWithPitches:(NSArray *)pitches {
    return [[SingingBowlSetup alloc]
            initWithPitches:[NSMutableArray arrayWithArray:pitches]];
}

- (void)testNumberOfPitchesMatchesInit {
    SingingBowlSetup *s = [self setupWithPitches:@[@60, @62, @64, @65]];
    XCTAssertEqual([s numberOfPitches], 4);
}

- (void)testPitchAtIndex {
    SingingBowlSetup *s = [self setupWithPitches:@[@36, @40, @43, @48]];
    XCTAssertEqual([s pitchAtIndex:0], 36);
    XCTAssertEqual([s pitchAtIndex:1], 40);
    XCTAssertEqual([s pitchAtIndex:2], 43);
    XCTAssertEqual([s pitchAtIndex:3], 48);
}

- (void)testPitchAtRadiusZeroReturnsFirstPitch {
    SingingBowlSetup *s = [self setupWithPitches:@[@36, @40, @43, @48]];
    XCTAssertEqual([s pitchAtRadius:0.0], 36);
}

- (void)testPitchAtRadiusOneIsClampedToLastPitch {
    SingingBowlSetup *s = [self setupWithPitches:@[@36, @40, @43, @48]];
    // radius * 4 = 4, but MIN clamps to count-1 = 3 → pitch index 3 = 48
    XCTAssertEqual([s pitchAtRadius:1.0], 48);
}

- (void)testPitchAtRadiusJustOverOneIsClampedToLastPitch {
    SingingBowlSetup *s = [self setupWithPitches:@[@36, @40, @43, @48]];
    XCTAssertEqual([s pitchAtRadius:1.5], 48);
}

- (void)testPitchAtRadiusBoundariesAreInclusiveLow {
    // With 4 pitches, ring widths are 0.25 each. radius < 0.25 → index 0,
    // radius in [0.25, 0.5) → index 1, etc.
    SingingBowlSetup *s = [self setupWithPitches:@[@36, @40, @43, @48]];
    XCTAssertEqual([s pitchAtRadius:0.24], 36);
    XCTAssertEqual([s pitchAtRadius:0.25], 40);
    XCTAssertEqual([s pitchAtRadius:0.49], 40);
    XCTAssertEqual([s pitchAtRadius:0.50], 43);
    XCTAssertEqual([s pitchAtRadius:0.75], 48);
}

- (void)testPitchAtRadiusMidpoint {
    SingingBowlSetup *s = [self setupWithPitches:@[@10, @20, @30, @40, @50, @60]];
    // 6 pitches, midpoint radius=0.5 → floor(0.5 * 6) = 3 → pitch index 3 = 40
    XCTAssertEqual([s pitchAtRadius:0.5], 40);
}

- (void)testSinglePitchAlwaysReturnsSamePitch {
    SingingBowlSetup *s = [self setupWithPitches:@[@72]];
    XCTAssertEqual([s pitchAtRadius:0.0], 72);
    XCTAssertEqual([s pitchAtRadius:0.5], 72);
    XCTAssertEqual([s pitchAtRadius:1.0], 72);
}

- (void)testNoteNameForMidiNumber {
    XCTAssertEqualObjects([SingingBowlSetup noteNameForMidiNumber:60], @"C");   // C4
    XCTAssertEqualObjects([SingingBowlSetup noteNameForMidiNumber:62], @"D");
    XCTAssertEqualObjects([SingingBowlSetup noteNameForMidiNumber:69], @"A");   // A4
    XCTAssertEqualObjects([SingingBowlSetup noteNameForMidiNumber:71], @"B");
    XCTAssertEqualObjects([SingingBowlSetup noteNameForMidiNumber:72], @"C");   // C5 wraps
    XCTAssertEqualObjects([SingingBowlSetup noteNameForMidiNumber:61], @"C♯");
}

@end
