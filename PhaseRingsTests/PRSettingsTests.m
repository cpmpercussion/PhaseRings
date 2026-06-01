//
//  PRSettingsTests.m
//  PhaseRingsTests
//
//  Issue #23 (Phase F.1): pins the shared settings stack so the app refactor is
//  provably behaviour-identical:
//   - PRCompositionFactory reproduces the exact notes/scales of the old
//     ViewController -openComposition switch (presets 1..4 + custom).
//   - PRUserDefaultsStore round-trips every key through NSUserDefaults.
//

#import <XCTest/XCTest.h>
#import <PhaseRingsKit/PhaseRingsKit.h>
#import "GenerativeSetupComposition.h"
#import "PRUserDefaultsStore.h"

// BASE_A from the legacy ViewController / PRCompositionFactory.
static const NSInteger kBaseA = 33;

@interface PRSettingsTests : XCTestCase
@end

@implementation PRSettingsTests

- (PRSettings *)settingsWithComposition:(NSInteger)comp {
    PRSettings *s = [PRSettings defaultSettings];
    s.composition = comp;
    return s;
}

#pragma mark - PRCompositionFactory presets

- (void)testPresetStudyInBowls {
    GenerativeSetupComposition *c =
        [PRCompositionFactory compositionForSettings:[self settingsWithComposition:1]];
    XCTAssertEqualObjects(c.rootNotes, (@[@41, @42, @48]));
    XCTAssertEqualObjects(c.scales, (@[@"MIXOLYDIAN", @"LYDIAN", @"LYDIANSHARPFIVE"]));
}

- (void)testPresetAmores {
    GenerativeSetupComposition *c =
        [PRCompositionFactory compositionForSettings:[self settingsWithComposition:2]];
    XCTAssertEqualObjects(c.rootNotes, (@[@36, @37, @41]));
    XCTAssertEqualObjects(c.scales, (@[@"MIXOFLATSIX", @"OCTATONIC", @"WHOLETONE"]));
}

- (void)testPresetMixoSteps {
    GenerativeSetupComposition *c =
        [PRCompositionFactory compositionForSettings:[self settingsWithComposition:3]];
    XCTAssertEqualObjects(c.rootNotes, (@[@36, @38, @41]));
    XCTAssertEqualObjects(c.scales, (@[@"MIXOLYDIAN", @"MIXOLYDIAN", @"MIXOLYDIAN"]));
}

- (void)testPresetScheimpflug {
    GenerativeSetupComposition *c =
        [PRCompositionFactory compositionForSettings:[self settingsWithComposition:4]];
    XCTAssertEqualObjects(c.rootNotes, (@[@36, @38, @40]));
    XCTAssertEqualObjects(c.scales, (@[@"WHOLETONE", @"MIXOFLATSIX", @"LOCHRIAN"]));
}

#pragma mark - PRCompositionFactory custom composition

- (void)testCustomCompositionAppliesBaseAAndScaleList {
    PRSettings *s = [self settingsWithComposition:0];
    s.note1 = 1; s.note2 = 3; s.note3 = 4;     // default offsets
    s.scale1 = 3; s.scale2 = 8; s.scale3 = 9;  // LYDIAN, MIXOFLATSIX, OCTATONIC
    GenerativeSetupComposition *c = [PRCompositionFactory compositionForSettings:s];
    XCTAssertEqualObjects(c.rootNotes, (@[@(kBaseA + 1), @(kBaseA + 3), @(kBaseA + 4)]));
    XCTAssertEqualObjects(c.scales, (@[@"LYDIAN", @"MIXOFLATSIX", @"OCTATONIC"]));
}

#pragma mark - PRUserDefaultsStore round-trip

- (void)testUserDefaultsStoreRoundTrips {
    NSString *suite = @"PRSettingsTests.roundtrip";
    NSUserDefaults *d = [[NSUserDefaults alloc] initWithSuiteName:suite];
    [d removePersistentDomainForName:suite];

    PRUserDefaultsStore *store = [[PRUserDefaultsStore alloc] initWithUserDefaults:d];
    [store updateSettings:^(PRSettings *s) {
        s.sound = 5;
        s.composition = 2;
        s.noteLabels = NO;
        s.setupLabel = NO;
        s.masterVolume = 1.25f;
        s.reverbVolume = 0.33f;
        s.distortLevel = 0.7f;
        s.processEffects = NO;
        s.note1 = 2; s.note2 = 6; s.note3 = 10;
        s.scale1 = 1; s.scale2 = 4; s.scale3 = 10;
    }];

    PRSettings *r = [[[PRUserDefaultsStore alloc] initWithUserDefaults:d] currentSettings];
    XCTAssertEqual(r.sound, 5);
    XCTAssertEqual(r.composition, 2);
    XCTAssertFalse(r.noteLabels);
    XCTAssertFalse(r.setupLabel);
    XCTAssertEqualWithAccuracy(r.masterVolume, 1.25f, 0.0001);
    XCTAssertEqualWithAccuracy(r.reverbVolume, 0.33f, 0.0001);
    XCTAssertEqualWithAccuracy(r.distortLevel, 0.7f, 0.0001);
    XCTAssertFalse(r.processEffects);
    XCTAssertEqual(r.note1, 2);
    XCTAssertEqual(r.note3, 10);
    XCTAssertEqual(r.scale3, 10);

    [d removePersistentDomainForName:suite];
}

- (void)testUpdateSettingsFiresOnChange {
    NSString *suite = @"PRSettingsTests.onchange";
    NSUserDefaults *d = [[NSUserDefaults alloc] initWithSuiteName:suite];
    [d removePersistentDomainForName:suite];
    PRUserDefaultsStore *store = [[PRUserDefaultsStore alloc] initWithUserDefaults:d];

    XCTestExpectation *fired = [self expectationWithDescription:@"onChange"];
    store.onChange = ^(PRSettings *s) {
        XCTAssertEqual(s.sound, 4);
        [fired fulfill];
    };
    [store updateSettings:^(PRSettings *s) { s.sound = 4; }];
    [self waitForExpectations:@[fired] timeout:1.0];

    [d removePersistentDomainForName:suite];
}

@end
