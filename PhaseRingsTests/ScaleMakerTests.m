//
//  ScaleMakerTests.m
//  PhaseRingsTests
//

#import <XCTest/XCTest.h>
#import "ScaleMaker.h"

@interface ScaleMakerTests : XCTestCase
@end

@implementation ScaleMakerTests

- (void)assertScale:(NSString *)scale base:(int)base expected:(NSArray<NSNumber *> *)expected {
    for (int i = 0; i < (int)expected.count; i++) {
        int got = [ScaleMaker noteForScale:scale withBase:base withNote:i];
        int want = [expected[i] intValue];
        XCTAssertEqual(got, want,
                       @"%@ note %d from base %d: expected %d, got %d",
                       scale, i, base, want, got);
    }
}

- (void)testIonianFromC60 {
    [self assertScale:@"IONIAN" base:60
             expected:@[@60, @62, @64, @65, @67, @69, @71, @72, @74]];
}

- (void)testDorianFromD62 {
    [self assertScale:@"DORIAN" base:62
             expected:@[@62, @64, @65, @67, @69, @71, @72, @74]];
}

- (void)testPhrygianFromE64 {
    [self assertScale:@"PHRYGIAN" base:64
             expected:@[@64, @65, @67, @69, @71, @72, @74, @76]];
}

- (void)testLydianFromF65 {
    [self assertScale:@"LYDIAN" base:65
             expected:@[@65, @67, @69, @71, @72, @74, @76, @77]];
}

- (void)testMixolydianFromG67 {
    [self assertScale:@"MIXOLYDIAN" base:67
             expected:@[@67, @69, @71, @72, @74, @76, @77, @79]];
}

- (void)testAeolianFromA69 {
    [self assertScale:@"AEOLIAN" base:69
             expected:@[@69, @71, @72, @74, @76, @77, @79, @81]];
}

- (void)testLochrianFromB71 {
    [self assertScale:@"LOCHRIAN" base:71
             expected:@[@71, @72, @74, @76, @77, @79, @81, @83]];
}

- (void)testLydianSharpFiveFromC60 {
    [self assertScale:@"LYDIANSHARPFIVE" base:60
             expected:@[@60, @62, @64, @66, @68, @69, @71, @72]];
}

- (void)testMixoFlatSixFromC60 {
    [self assertScale:@"MIXOFLATSIX" base:60
             expected:@[@60, @62, @64, @65, @67, @68, @70, @72]];
}

- (void)testOctatonicFromC60 {
    // 8-note scale: 0 2 3 5 6 8 9 11, then wraps to next octave
    [self assertScale:@"OCTATONIC" base:60
             expected:@[@60, @62, @63, @65, @66, @68, @69, @71, @72, @74]];
}

- (void)testWholeToneFromC60 {
    // 6-note scale: 0 2 4 6 8 10, wraps every 6 indices
    [self assertScale:@"WHOLETONE" base:60
             expected:@[@60, @62, @64, @66, @68, @70, @72, @74]];
}

- (void)testOctaveWrapIonian {
    // Index 7 should be one octave above index 0 for a 7-note diatonic scale.
    int low  = [ScaleMaker noteForScale:@"IONIAN" withBase:60 withNote:0];
    int high = [ScaleMaker noteForScale:@"IONIAN" withBase:60 withNote:7];
    XCTAssertEqual(high - low, 12);
}

- (void)testUnknownScaleFallsBackToIonian {
    int got      = [ScaleMaker noteForScale:@"NOT_A_SCALE" withBase:60 withNote:3];
    int expected = [ScaleMaker noteForScale:@"IONIAN" withBase:60 withNote:3];
    XCTAssertEqual(got, expected);
}

- (void)testPrettyScaleString {
    XCTAssertEqualObjects([ScaleMaker prettyScaleString:@"IONIAN"], @"Ionian");
    XCTAssertEqualObjects([ScaleMaker prettyScaleString:@"LYDIANSHARPFIVE"], @"Lydian ♯5");
    XCTAssertEqualObjects([ScaleMaker prettyScaleString:@"MIXOFLATSIX"], @"Mixo ♭6");
    XCTAssertEqualObjects([ScaleMaker prettyScaleString:@"WHOLETONE"], @"Whole Tone");
    XCTAssertEqualObjects([ScaleMaker prettyScaleString:@"NOT_A_SCALE"], @"Ionian");
}

@end
