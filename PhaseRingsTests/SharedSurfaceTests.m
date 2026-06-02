//
//  SharedSurfaceTests.m
//  PhaseRingsTests
//
//  Programmatic coverage for the ensemble / OSC / MIDI paths that #27 reworked
//  but that have no device-level automated test:
//
//   1. InstrumentSurfaceTests  — the shared surface's seams: local input →
//      audio + MIDI + OSC-delegate, remote-OSC playback, remote setup state.
//   2. MetatoneOSCMessageTests — the OSC wire format the ensemble depends on,
//      tested by recording outgoing packets and feeding constructed messages
//      into the parse path (no sockets).
//   3. SharedSurfaceWiringTests — the app shell glue: instrument delegate →
//      network broadcast, and incoming network callbacks → instrument.
//

#import <XCTest/XCTest.h>
#import <PhaseRingsKit/PhaseRingsKit.h>     // InstrumentViewController, PRSettings, PRMemoryStore
#import "ViewController.h"                   // app shell
#import "MetatoneNetworkManager.h"
#import "F53OSCClient.h"
#import "F53OSCMessage.h"

#pragma mark - Test access to the surface's input seams

@interface InstrumentViewController (Testing)
- (void)inputTapAtPoint:(CGPoint)point velocity:(int)velocity;
- (void)inputMoveAtPoint:(CGPoint)point pixelVelocity:(CGFloat)pixelVelocity;
- (void)inputEndAtPoint:(CGPoint)point;
- (void)inputSwirlState:(UIGestureRecognizerState)state
                atPoint:(CGPoint)point
               velocity:(CGFloat)velocity
                  angle:(CGFloat)angle
            translation:(CGFloat)translation;
- (void)setupStepperChanged;
@end

#pragma mark - Recording doubles

// Records every HeavyEventSink call so tests can assert what the surface sent.
@interface RecordingEventSink : NSObject <HeavyEventSink>
@property (nonatomic, strong) NSMutableArray<NSDictionary *> *floats;   // @{@"r":receiver, @"v":@(value)}
@property (nonatomic, strong) NSMutableArray<NSDictionary *> *noteOns;  // @{@"p":@(pitch), @"v":@(vel)}
@property (nonatomic, strong) NSMutableArray<NSNumber *> *synths;
@end
@implementation RecordingEventSink
- (instancetype)init {
    if ((self = [super init])) {
        _floats = [NSMutableArray array];
        _noteOns = [NSMutableArray array];
        _synths = [NSMutableArray array];
    }
    return self;
}
- (void)selectSynth:(HeavySynth)synth { [self.synths addObject:@(synth)]; }
- (void)sendFloat:(float)value toReceiver:(NSString *)receiver {
    [self.floats addObject:@{@"r": receiver, @"v": @(value)}];
}
- (void)sendBangToReceiver:(NSString *)receiver {}
- (void)sendNoteOn:(int)channel pitch:(int)pitch velocity:(int)velocity {
    [self.noteOns addObject:@{@"p": @(pitch), @"v": @(velocity)}];
}
// Most-recent value sent to a receiver, or nil.
- (NSNumber *)lastFloatFor:(NSString *)receiver {
    for (NSDictionary *f in self.floats.reverseObjectEnumerator) {
        if ([f[@"r"] isEqualToString:receiver]) return f[@"v"];
    }
    return nil;
}
@end

// Records InstrumentViewControllerDelegate callbacks.
@interface RecordingInstrumentDelegate : NSObject <InstrumentViewControllerDelegate>
@property (nonatomic, strong) NSMutableArray<NSValue *> *began;
@property (nonatomic, strong) NSMutableArray<NSNumber *> *beganPitches;
@property (nonatomic, strong) NSMutableArray<NSValue *> *moved;
@property (nonatomic) NSInteger endedCount;
@property (nonatomic, strong) NSMutableArray<NSNumber *> *setupChanges;
@end
@implementation RecordingInstrumentDelegate
- (instancetype)init {
    if ((self = [super init])) {
        _began = [NSMutableArray array];
        _beganPitches = [NSMutableArray array];
        _moved = [NSMutableArray array];
        _setupChanges = [NSMutableArray array];
    }
    return self;
}
- (void)instrument:(InstrumentViewController *)vc touchBeganAtPoint:(CGPoint)point pitch:(int)pitch velocity:(int)velocity {
    [self.began addObject:[NSValue valueWithCGPoint:point]];
    [self.beganPitches addObject:@(pitch)];
}
- (void)instrument:(InstrumentViewController *)vc touchMovedToPoint:(CGPoint)point velocity:(CGFloat)pixelVelocity {
    [self.moved addObject:[NSValue valueWithCGPoint:point]];
}
- (void)instrumentTouchEnded:(InstrumentViewController *)vc { self.endedCount++; }
- (void)instrument:(InstrumentViewController *)vc didChangeSetupState:(int)state {
    [self.setupChanges addObject:@(state)];
}
@end

#pragma mark - 1. Instrument surface seams

@interface InstrumentSurfaceTests : XCTestCase
@end
@implementation InstrumentSurfaceTests {
    InstrumentViewController *_vc;
    RecordingEventSink *_sink;
    RecordingInstrumentDelegate *_delegate;
    NSMutableArray<NSData *> *_midi;
}

- (void)setUp {
    [super setUp];
    _sink = [[RecordingEventSink alloc] init];
    _delegate = [[RecordingInstrumentDelegate alloc] init];
    _midi = [NSMutableArray array];

    _vc = [[InstrumentViewController alloc] init];
    _vc.settingsStore = [[PRMemoryStore alloc] init];
    RecordingEventSink *sink = _sink;
    _vc.coreProvider = ^id<HeavyEventSink> _Nullable { return sink; };
    _vc.delegate = _delegate;
    NSMutableArray<NSData *> *midi = _midi;
    _vc.midiOutSink = ^(const uint8_t *bytes, NSUInteger length) {
        [midi addObject:[NSData dataWithBytes:bytes length:length]];
    };
    (void)_vc.view;                              // force viewDidLoad → builds the composition
    _vc.view.frame = CGRectMake(0, 0, 400, 400); // a real size so geometry resolves
}

- (void)assertMidi:(NSData *)d status:(uint8_t)s data1:(uint8_t)d1 data2:(uint8_t)d2 {
    const uint8_t *b = d.bytes;
    XCTAssertEqual(d.length, (NSUInteger)3);
    XCTAssertEqual(b[0], s);
    XCTAssertEqual(b[1], d1);
    XCTAssertEqual(b[2], d2);
}

- (void)testTapDrivesAudioMidiAndDelegate {
    CGPoint p = CGPointMake(200, 120);
    int pitch = [_vc pitchAtPoint:p];
    [_vc inputTapAtPoint:p velocity:100];

    XCTAssertEqual(_sink.noteOns.count, (NSUInteger)1);
    XCTAssertEqualObjects(_sink.noteOns[0][@"p"], @(pitch));
    XCTAssertEqualObjects(_sink.noteOns[0][@"v"], @100);

    // Momentary MIDI note: on then off, same pitch + velocity.
    XCTAssertEqual(_midi.count, (NSUInteger)2);
    [self assertMidi:_midi[0] status:0x90 data1:(uint8_t)pitch data2:100];
    [self assertMidi:_midi[1] status:0x80 data1:(uint8_t)pitch data2:100];

    // OSC mirror.
    XCTAssertEqual(_delegate.began.count, (NSUInteger)1);
    XCTAssertEqualObjects(_delegate.beganPitches[0], @(pitch));
}

- (void)testMoveMirrorsToDelegateOnly {
    [_vc inputMoveAtPoint:CGPointMake(10, 20) pixelVelocity:7.0];
    XCTAssertEqual(_delegate.moved.count, (NSUInteger)1);
    XCTAssertEqual(_midi.count, (NSUInteger)0);          // no audio / MIDI on move
    XCTAssertEqual(_sink.noteOns.count, (NSUInteger)0);
}

- (void)testTouchEndedEmitsNoteOffAndDelegate {
    CGPoint p = CGPointMake(200, 120);
    int pitch = [_vc pitchAtPoint:p];
    [_vc inputEndAtPoint:p];
    XCTAssertEqual(_midi.count, (NSUInteger)1);
    [self assertMidi:_midi[0] status:0x80 data1:(uint8_t)pitch data2:0];
    XCTAssertEqual(_delegate.endedCount, 1);
}

- (void)testSwirlBeganChangedEndedDriveAudioAndMidi {
    CGPoint p = CGPointMake(200, 100);
    int pitch = [_vc pitchAtPoint:p];

    [_vc inputSwirlState:UIGestureRecognizerStateBegan atPoint:p velocity:0.5 angle:0.3 translation:0.1];
    XCTAssertEqualObjects([_sink lastFloatFor:@"sing"], @1);
    XCTAssertEqualObjects([_sink lastFloatFor:@"singpitch"], @((float)pitch));
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"singlevel"].floatValue, 0.5, 0.0001);
    [self assertMidi:_midi.lastObject status:0x90 data1:(uint8_t)pitch data2:(uint8_t)(0.5 * 127)];

    [_vc inputSwirlState:UIGestureRecognizerStateChanged atPoint:p velocity:0.5 angle:0.3 translation:0.2];
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"sinPanAngle"].floatValue, 0.3, 0.0001);
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"panTranslation"].floatValue, 0.2, 0.0001);
    [self assertMidi:_midi.lastObject status:0xA0 data1:(uint8_t)pitch data2:(uint8_t)(0.5 * 127)];

    [_vc inputSwirlState:UIGestureRecognizerStateEnded atPoint:p velocity:0.5 angle:0 translation:0];
    XCTAssertEqualObjects([_sink lastFloatFor:@"sing"], @0);
    XCTAssertEqualObjects([_sink lastFloatFor:@"singlevel"], @0);
    [self assertMidi:_midi.lastObject status:0x80 data1:(uint8_t)pitch data2:(uint8_t)(0.5 * 127)];
}

- (void)testPlaybackTapStruckNote {
    CGPoint p = CGPointMake(200, 80);
    int pitch = [_vc pitchAtPoint:p];
    [_vc playbackTapAtPoint:p];
    XCTAssertEqual(_sink.noteOns.count, (NSUInteger)1);
    XCTAssertEqualObjects(_sink.noteOns[0][@"p"], @(pitch));
    XCTAssertEqualObjects(_sink.noteOns[0][@"v"], @110);   // playback uses a fixed velocity
    XCTAssertEqual(_midi.count, (NSUInteger)0);             // remote playback does not emit MIDI
}

- (void)testPlaybackSwirlThenStop {
    [_vc playbackSwirlAtPoint:CGPointMake(200, 100) velocity:50.0];
    XCTAssertEqualObjects([_sink lastFloatFor:@"sing"], @1);
    XCTAssertNotNil([_sink lastFloatFor:@"singpitch"]);
    XCTAssertGreaterThan([_sink lastFloatFor:@"singlevel"].floatValue, 0.0);

    [_vc stopPlayback];
    XCTAssertEqualObjects([_sink lastFloatFor:@"sing"], @0);
    XCTAssertEqualObjects([_sink lastFloatFor:@"singlevel"], @0);
}

#pragma mark - MIDI-in (ring lights + sing performance)

- (void)testMidiNoteInWithoutPedalDoesNotSing {
    [_vc midiNoteIn:60 velocity:100];
    XCTAssertNil([_sink lastFloatFor:@"sing"]);          // a bare note-on only flashes a ring
    XCTAssertNil([_sink lastFloatFor:@"singpitch"]);
    XCTAssertEqual(_sink.noteOns.count, (NSUInteger)0);  // the struck note is the host's job, not the surface
}

- (void)testSustainPedalGatesSingVoice {
    [_vc midiSustainPedal:YES];
    [_vc midiNoteIn:62 velocity:100];
    XCTAssertEqualObjects([_sink lastFloatFor:@"sing"], @1);
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"singpitch"].floatValue, 62.0, 0.0001);
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"singlevel"].floatValue, 100.0 / 127.0, 0.0001);

    [_vc midiSustainPedal:NO];
    XCTAssertEqualObjects([_sink lastFloatFor:@"sing"], @0);   // pedal up ends the voice
}

- (void)testFirstNoteAfterPedalSingsAndLaterNotesDoNotResing {
    [_vc midiSustainPedal:YES];
    [_vc midiNoteIn:62 velocity:100];   // first note: captured as the sing pitch
    [_vc midiNoteIn:67 velocity:100];   // later note while held: must not re-pitch the voice
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"singpitch"].floatValue, 62.0, 0.0001);
}

- (void)testControlChangeMapsToSingReceivers {
    [_vc midiControlChange:11 value:64];   // expression → singlevel
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"singlevel"].floatValue, 64.0 / 127.0, 0.0001);

    [_vc midiControlChange:1 value:127];   // mod wheel → sinPanAngle (bipolar)
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"sinPanAngle"].floatValue, 1.0, 0.0001);
    [_vc midiControlChange:1 value:0];
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"sinPanAngle"].floatValue, -1.0, 0.0001);

    [_vc midiControlChange:74 value:127];  // brightness → panTranslation
    XCTAssertEqualWithAccuracy([_sink lastFloatFor:@"panTranslation"].floatValue, 1.0, 0.0001);
}

- (void)testShowSetupStateClamps {
    NSInteger n = _vc.numberOfSetups;
    XCTAssertGreaterThan(n, 0);
    [_vc showSetupState:1000];
    XCTAssertEqual(_vc.currentSetupState, (int)(n - 1));
    [_vc showSetupState:-5];
    XCTAssertEqual(_vc.currentSetupState, 0);
    [_vc showSetupState:0];
    XCTAssertEqual(_vc.currentSetupState, 0);
}

- (void)testStepperChangeBroadcastsSetupState {
    UIStepper *stepper = [_vc valueForKey:@"setupStepper"];
    XCTAssertNotNil(stepper);
    stepper.value = 1;
    [_vc setupStepperChanged];
    XCTAssertEqualObjects(_delegate.setupChanges, (@[@1]));
    XCTAssertEqual(_vc.currentSetupState, 1);
}

- (void)testPitchAtPointVariesWithRadius {
    int center = [_vc pitchAtPoint:CGPointMake(200, 200)];
    int edge   = [_vc pitchAtPoint:CGPointMake(200, 0)];
    XCTAssertNotEqual(center, edge);   // inner vs outer ring → different pitch
}

@end

#pragma mark - 2. OSC message wire format

@interface RecordingOSCClient : F53OSCClient
@property (nonatomic, strong) NSMutableArray<F53OSCMessage *> *sent;
@end
@implementation RecordingOSCClient
- (instancetype)init {
    if ((self = [super init])) { _sent = [NSMutableArray array]; }
    return self;
}
- (void)sendPacket:(F53OSCPacket *)packet toHost:(NSString *)host onPort:(UInt16)port {
    if ([packet isKindOfClass:[F53OSCMessage class]]) {
        [self.sent addObject:(F53OSCMessage *)packet];
    }
}
@end

// Implements the (required) network delegate, recording the callbacks under test
// and fulfilling an expectation so the async main-queue dispatch can be awaited.
@interface RecordingNetworkDelegate : NSObject <MetatoneNetworkManagerDelegate>
@property (nonatomic, strong) XCTestExpectation *expectation;
@property (nonatomic, copy) NSString *appFrom, *appName, *appState;
@property (nonatomic, copy) NSString *playDevice, *ensembleEvent, *perfEvent;
@property (nonatomic, strong) NSNumber *playX, *playY, *playVel, *perfType, *perfComp;
@end
@implementation RecordingNetworkDelegate
- (void)didReceiveMetatoneMessageFrom:(NSString *)device withName:(NSString *)name andState:(NSString *)state {
    self.appFrom = device; self.appName = name; self.appState = state; [self.expectation fulfill];
}
- (void)didReceiveTouchPlayMessageFor:(NSString *)device X:(NSNumber *)x Y:(NSNumber *)y vel:(NSNumber *)vel {
    self.playDevice = device; self.playX = x; self.playY = y; self.playVel = vel; [self.expectation fulfill];
}
- (void)didReceivePerformanceStartEvent:(NSString *)event forDevice:(NSString *)device withType:(NSNumber *)type andComposition:(NSNumber *)composition {
    self.perfEvent = event; self.perfType = type; self.perfComp = composition; [self.expectation fulfill];
}
- (void)didReceiveEnsembleEvent:(NSString *)event forDevice:(NSString *)device withMeasure:(NSNumber *)measure {
    self.ensembleEvent = event; [self.expectation fulfill];
}
// Remaining required methods — unused here.
- (void)searchingForLoggingServer {}
- (void)loggingServerFoundWithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {}
- (void)stoppedSearchingForLoggingServer {}
- (void)didReceiveGestureMessageFor:(NSString *)device withClass:(NSString *)class {}
- (void)didReceiveEnsembleState:(NSString *)state withSpread:(NSNumber *)spread withRatio:(NSNumber *)ratio {}
- (void)didReceivePerformanceEndEvent:(NSString *)event forDevice:(NSString *)device {}
- (void)metatoneClientFoundWithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {}
- (void)metatoneClientRemovedwithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {}
- (void)didReceiveGesturePlayMessageFor:(NSString *)device withClass:(NSString *)cla {}
@end

@interface MetatoneOSCMessageTests : XCTestCase
@end
@implementation MetatoneOSCMessageTests {
    MetatoneNetworkManager *_mgr;
    RecordingOSCClient *_client;
    RecordingNetworkDelegate *_delegate;
}

- (void)setUp {
    [super setUp];
    _delegate = [[RecordingNetworkDelegate alloc] init];
    _mgr = [[MetatoneNetworkManager alloc] init];   // plain init: no Bonjour searches
    _mgr.delegate = _delegate;
    _mgr.deviceID = @"this-device";
    _client = [[RecordingOSCClient alloc] init];
    _mgr.oscClient = _client;
    _mgr.loggingIPAddress = @"127.0.0.1";
    _mgr.loggingPort = 9000;
}

// --- outgoing wire format ---

- (void)testSendTouchMessage {
    [_mgr sendMessageWithTouch:CGPointMake(12, 34) Velocity:0.0];
    XCTAssertEqual(_client.sent.count, (NSUInteger)1);
    F53OSCMessage *m = _client.sent[0];
    XCTAssertEqualObjects(m.addressPattern, @"/metatone/touch");
    XCTAssertEqualObjects(m.arguments[0], @"this-device");
    XCTAssertEqualWithAccuracy([m.arguments[1] floatValue], 12.0, 0.001);
    XCTAssertEqualWithAccuracy([m.arguments[2] floatValue], 34.0, 0.001);
}

- (void)testSendTouchEnded {
    [_mgr sendMessageTouchEnded];
    F53OSCMessage *m = _client.sent.firstObject;
    XCTAssertEqualObjects(m.addressPattern, @"/metatone/touch/ended");
    XCTAssertEqualObjects(m.arguments[0], @"this-device");
}

- (void)testSendMetatoneMessage {
    [_mgr sendMetatoneMessage:@"CompositionStep" withState:@"3"];
    F53OSCMessage *m = _client.sent.firstObject;
    XCTAssertEqualObjects(m.addressPattern, @"/metatone/app");
    XCTAssertEqualObjects(m.arguments[1], @"CompositionStep");
    XCTAssertEqualObjects(m.arguments[2], @"3");
}

// --- incoming parse path (delegate dispatched async on main queue) ---

- (void)deliver:(NSString *)address args:(NSArray *)args {
    _delegate.expectation = [self expectationWithDescription:address];
    [_mgr takeMessage:[F53OSCMessage messageWithAddressPattern:address arguments:args]];
    [self waitForExpectations:@[_delegate.expectation] timeout:1.0];
}

- (void)testParseTouchPlayback {
    [self deliver:@"/metatone/playback/touch" args:@[@"peer", @100.0f, @200.0f, @0.5f]];
    XCTAssertEqualWithAccuracy(_delegate.playX.floatValue, 100.0, 0.001);
    XCTAssertEqualWithAccuracy(_delegate.playY.floatValue, 200.0, 0.001);
    XCTAssertEqualWithAccuracy(_delegate.playVel.floatValue, 0.5, 0.001);
}

- (void)testParseCompositionStep {
    [self deliver:@"/metatone/app" args:@[@"peer", @"CompositionStep", @"2"]];
    XCTAssertEqualObjects(_delegate.appName, @"CompositionStep");
    XCTAssertEqualObjects(_delegate.appState, @"2");
}

- (void)testParsePerformanceStart {
    [self deliver:@"/metatone/performance/start" args:@[@"start", @"peer", @1, @3]];
    XCTAssertEqualObjects(_delegate.perfComp, @3);
}

- (void)testParseNewIdea {
    [self deliver:@"/metatone/classifier/ensemble/event/new_idea" args:@[@"peer", @4]];
    XCTAssertEqualObjects(_delegate.ensembleEvent, @"new_idea");
}

@end

#pragma mark - 3. App shell wiring (delegate → network, network → instrument)

// Records the instrument calls the shell makes in response to network events.
@interface FakeInstrument : InstrumentViewController
@property (nonatomic) int playbackTaps;
@property (nonatomic) CGPoint lastPlaybackTapPoint;
@property (nonatomic) int playbackSwirls;
@property (nonatomic) CGFloat lastPlaybackSwirlVel;
@property (nonatomic) int lastShownSetup;
@property (nonatomic) int fakeSetupState;
@property (nonatomic) NSInteger fakeNumberOfSetups;
@end
@implementation FakeInstrument
- (void)playbackTapAtPoint:(CGPoint)point { self.playbackTaps++; self.lastPlaybackTapPoint = point; }
- (void)playbackSwirlAtPoint:(CGPoint)point velocity:(CGFloat)velocity { self.playbackSwirls++; self.lastPlaybackSwirlVel = velocity; }
- (void)showSetupState:(int)state { self.lastShownSetup = state; self.fakeSetupState = state; }
- (int)currentSetupState { return self.fakeSetupState; }
- (NSInteger)numberOfSetups { return self.fakeNumberOfSetups; }
@end

// Records the OSC broadcasts the shell makes in response to local input.
@interface FakeNetworkManager : MetatoneNetworkManager
@property (nonatomic) CGPoint lastTouch;
@property (nonatomic) CGFloat lastTouchVel;
@property (nonatomic) int touchSends;
@property (nonatomic) int touchEndeds;
@property (nonatomic, copy) NSString *lastMsgName;
@property (nonatomic, copy) NSString *lastMsgState;
@end
@implementation FakeNetworkManager
- (void)sendMessageWithTouch:(CGPoint)point Velocity:(CGFloat)vel { self.touchSends++; self.lastTouch = point; self.lastTouchVel = vel; }
- (void)sendMessageTouchEnded { self.touchEndeds++; }
- (void)sendMetatoneMessage:(NSString *)name withState:(NSString *)state { self.lastMsgName = name; self.lastMsgState = state; }
@end

@interface SharedSurfaceWiringTests : XCTestCase
@end
@implementation SharedSurfaceWiringTests {
    ViewController *_vc;
    FakeInstrument *_instrument;
    FakeNetworkManager *_net;
}

- (void)setUp {
    [super setUp];
    // Construct the shell without loading its view, so viewDidLoad (audio
    // session, real network manager) never runs; inject fakes into its private
    // slots via KVC.
    _vc = [[ViewController alloc] init];
    _instrument = [[FakeInstrument alloc] init];
    _net = [[FakeNetworkManager alloc] init];
    [_vc setValue:_instrument forKey:@"instrument"];
    [_vc setValue:_net forKey:@"networkManager"];
}

- (id<InstrumentViewControllerDelegate>)surfaceDelegate { return (id<InstrumentViewControllerDelegate>)_vc; }

- (void)testLocalTapBroadcastsOSC {
    [[self surfaceDelegate] instrument:_instrument touchBeganAtPoint:CGPointMake(5, 6) pitch:60 velocity:100];
    XCTAssertEqual(_net.touchSends, 1);
    XCTAssertEqualWithAccuracy(_net.lastTouch.x, 5.0, 0.001);
    XCTAssertEqualWithAccuracy(_net.lastTouchVel, 0.0, 0.001);   // taps broadcast at velocity 0
}

- (void)testLocalMoveBroadcastsOSC {
    [[self surfaceDelegate] instrument:_instrument touchMovedToPoint:CGPointMake(7, 8) velocity:9.0];
    XCTAssertEqual(_net.touchSends, 1);
    XCTAssertEqualWithAccuracy(_net.lastTouchVel, 9.0, 0.001);
}

- (void)testLocalEndBroadcastsOSC {
    [[self surfaceDelegate] instrumentTouchEnded:_instrument];
    XCTAssertEqual(_net.touchEndeds, 1);
}

- (void)testLocalSetupChangeBroadcasts {
    [[self surfaceDelegate] instrument:_instrument didChangeSetupState:4];
    XCTAssertEqualObjects(_net.lastMsgName, @"CompositionStep");
    XCTAssertEqualObjects(_net.lastMsgState, @"4");
}

- (void)testRemoteCompositionStepDrivesInstrument {
    [_vc didReceiveMetatoneMessageFrom:@"peer" withName:@"CompositionStep" andState:@"2"];
    XCTAssertEqual(_instrument.lastShownSetup, 2);
}

- (void)testRemoteTouchPlaybackTap {
    [_vc didReceiveTouchPlayMessageFor:@"peer" X:@100 Y:@200 vel:@0];
    XCTAssertEqual(_instrument.playbackTaps, 1);
    XCTAssertEqual(_instrument.playbackSwirls, 0);
    XCTAssertEqualWithAccuracy(_instrument.lastPlaybackTapPoint.x, 100.0, 0.001);
}

- (void)testRemoteTouchPlaybackSwirl {
    [_vc didReceiveTouchPlayMessageFor:@"peer" X:@100 Y:@200 vel:@0.7];
    XCTAssertEqual(_instrument.playbackSwirls, 1);
    XCTAssertEqual(_instrument.playbackTaps, 0);
    XCTAssertEqualWithAccuracy(_instrument.lastPlaybackSwirlVel, 0.7, 0.001);
}

- (void)testRemoteNewIdeaAdvancesSetupWithWrap {
    _vc.listenToMetatoneClassifierMessages = YES;
    [_vc setValue:[NSDate dateWithTimeIntervalSinceNow:-100] forKey:@"timeOfLastNewIdea"];
    _instrument.fakeNumberOfSetups = 3;
    _instrument.fakeSetupState = 2;
    [_vc didReceiveEnsembleEvent:@"new_idea" forDevice:@"peer" withMeasure:@1];
    XCTAssertEqual(_instrument.lastShownSetup, 0);   // 2 → wraps to 0
}

- (void)testRemotePerformanceStartSetsComposition {
    PRMemoryStore *store = [[PRMemoryStore alloc] init];
    [_vc setValue:store forKey:@"settingsStore"];
    [_vc didReceivePerformanceStartEvent:@"start" forDevice:@"peer" withType:@1 andComposition:@3];
    XCTAssertEqual([store currentSettings].composition, 3);
}

@end
