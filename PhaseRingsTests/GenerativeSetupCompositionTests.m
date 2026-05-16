//
//  GenerativeSetupCompositionTests.m
//  PhaseRingsTests
//

#import <XCTest/XCTest.h>
#import "GenerativeSetupComposition.h"

// Mirrors the private constants in GenerativeSetupComposition.m. Kept in
// sync with that file — these tests assert structural invariants of the
// generator, so they're a deliberate canary if those constants change.
static NSArray *ValidSetupSizes(void) {
    return @[@3, @5, @8, @11];
}
static const NSUInteger kNumberSetupsPerRoot = 2;

@interface GenerativeSetupCompositionTests : XCTestCase
@end

@implementation GenerativeSetupCompositionTests

- (GenerativeSetupComposition *)standardComposition {
    return [[GenerativeSetupComposition alloc]
            initWithRootNotes:@[@36, @40, @43]
                    andScales:@[@"IONIAN", @"DORIAN", @"MIXOLYDIAN"]];
}

- (void)testProducesTwoSetupsPerRoot {
    GenerativeSetupComposition *c = [self standardComposition];
    XCTAssertEqual([c numberOfSetups], 3 * kNumberSetupsPerRoot);
}

- (void)testFirstSetupNonEmpty {
    GenerativeSetupComposition *c = [self standardComposition];
    NSArray *first = [c firstSetup];
    XCTAssertNotNil(first);
    XCTAssertGreaterThan(first.count, 0u);
}

- (void)testEverySetupHasAValidPitchCount {
    GenerativeSetupComposition *c = [self standardComposition];
    NSArray *validSizes = ValidSetupSizes();
    for (int i = 0; i < [c numberOfSetups]; i++) {
        NSArray *setup = [c setupForState:i];
        XCTAssertNotNil(setup);
        XCTAssertTrue([validSizes containsObject:@(setup.count)],
                      @"setup %d had unexpected count %lu",
                      i, (unsigned long)setup.count);
    }
}

- (void)testSetupDescriptionsMatchSetupCount {
    GenerativeSetupComposition *c = [self standardComposition];
    XCTAssertEqual(c.setupDescriptions.count, (NSUInteger)[c numberOfSetups]);
}

- (void)testSetupsAreLooping {
    GenerativeSetupComposition *c = [self standardComposition];
    XCTAssertTrue(c.looping);
    // Walk past the end via nextSetup; with looping=YES we should land
    // back on the first setup eventually.
    NSArray *first = [c firstSetup];
    for (int i = 0; i < [c numberOfSetups]; i++) {
        [c nextSetup];
    }
    NSArray *afterWrap = [c setupForState:0];
    XCTAssertEqualObjects(first, afterWrap);
}

- (void)testSetupForStateOutOfRangeClampsHigh {
    GenerativeSetupComposition *c = [self standardComposition];
    NSArray *last     = [c setupForState:[c numberOfSetups] - 1];
    NSArray *waybeyond = [c setupForState:9999];
    XCTAssertEqualObjects(last, waybeyond);
}

- (void)testPitchesAreSortedAscending {
    GenerativeSetupComposition *c = [self standardComposition];
    for (int i = 0; i < [c numberOfSetups]; i++) {
        NSArray *setup = [c setupForState:i];
        for (NSUInteger j = 1; j < setup.count; j++) {
            int prev = [setup[j - 1] intValue];
            int cur  = [setup[j] intValue];
            XCTAssertLessThanOrEqual(prev, cur,
                                     @"setup %d not sorted at index %lu",
                                     i, (unsigned long)j);
        }
    }
}

@end
