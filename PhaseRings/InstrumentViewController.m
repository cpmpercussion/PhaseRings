//
//  InstrumentViewController.m
//  PhaseRingsKit
//
//  See InstrumentViewController.h and auv3-plan.md (Phase F). The touch/sing
//  logic mirrors the standalone ViewController, with networking + MIDI-out
//  removed (those stay app-only).
//

#import "InstrumentViewController.h"
#import "SingingBowlView.h"
#import "SingingBowlSetup.h"
#import "GenerativeSetupComposition.h"
#import "PRSettings.h"
#import "PRCompositionFactory.h"
#import "PRMemoryStore.h"
#import <PhaseRingsKit/PhaseRingsKit-Swift.h>   // PRSettingsHostingController

// Diagonal used to normalise swirl translation into Heavy's panTranslation,
// matching the standalone app.
static const CGFloat kScreenDiagonal = 1280.0;

@interface InstrumentViewController ()
@property (nonatomic, strong) SingingBowlView *bowlView;
@property (nonatomic, strong) SingingBowlSetup *bowlSetup;
@property (nonatomic, strong) GenerativeSetupComposition *composition;
@property (nonatomic) UInt8 currentlyPanningPitch;
@property (nonatomic) CGSize lastDrawnSize;
@property (nonatomic) NSInteger soundScheme;
@property (nonatomic) BOOL showNoteLabels;
@property (nonatomic) BOOL showSetupLabel;
@property (nonatomic) int setupState;
// On-screen control bar.
@property (nonatomic, strong) UIStepper *setupStepper;
@property (nonatomic, strong) UILabel *setupDescriptionLabel;
// Last settings applied, so a settings change only rebuilds what actually moved.
@property (nonatomic, strong) PRSettings *appliedSettings;
@end

@implementation InstrumentViewController

@synthesize settingsStore = _settingsStore;

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.multipleTouchEnabled = YES;
    self.showNoteLabels = YES;

    self.bowlView = [[SingingBowlView alloc] initWithFrame:self.view.bounds];
    self.bowlView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    self.bowlView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:self.bowlView];

    UIPanGestureRecognizer *pan =
        [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panGestureRecognized:)];
    [self.view addGestureRecognizer:pan];

    [self buildControlBar];
    [self reloadComposition];
}

#pragma mark - Settings store

- (id<PRSettingsStore>)settingsStore {
    if (!_settingsStore) {
        self.settingsStore = [[PRMemoryStore alloc] init];  // through setter -> wires onChange
    }
    return _settingsStore;
}

- (void)setSettingsStore:(id<PRSettingsStore>)settingsStore {
    _settingsStore = settingsStore;
    __weak typeof(self) weakSelf = self;
    settingsStore.onChange = ^(PRSettings *settings) {
        [weakSelf settingsDidChange:settings];
    };
    if (self.isViewLoaded) {
        [self reloadComposition];
    }
}

#pragma mark - Control bar

- (void)buildControlBar {
    // Setup stepper — steps through the composition's setups (replaces the old
    // "New Setup" pill; matches the standalone app's compositionStepper).
    self.setupStepper = [[UIStepper alloc] init];
    self.setupStepper.wraps = YES;
    self.setupStepper.minimumValue = 0;
    self.setupStepper.tintColor = [UIColor whiteColor];
    [self.setupStepper addTarget:self action:@selector(setupStepperChanged)
                forControlEvents:UIControlEventValueChanged];
    self.setupStepper.translatesAutoresizingMaskIntoConstraints = NO;

    // Settings gear — presents the shared PhaseRingsKit settings screen. Sound
    // scheme + note labels now live there rather than as on-screen pills.
    UIButton *settingsButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [settingsButton setImage:[UIImage systemImageNamed:@"gearshape"] forState:UIControlStateNormal];
    settingsButton.tintColor = [UIColor whiteColor];
    [settingsButton addTarget:self action:@selector(showSettingsTapped)
             forControlEvents:UIControlEventTouchUpInside];
    settingsButton.translatesAutoresizingMaskIntoConstraints = NO;

    UIStackView *bar = [[UIStackView alloc] initWithArrangedSubviews:@[self.setupStepper, settingsButton]];
    bar.axis = UILayoutConstraintAxisHorizontal;
    bar.spacing = 12;
    bar.alignment = UIStackViewAlignmentCenter;
    bar.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:bar];

    // Setup description label — shown when the setup_label setting is on.
    self.setupDescriptionLabel = [[UILabel alloc] init];
    self.setupDescriptionLabel.textColor = [UIColor colorWithWhite:1.0 alpha:0.85];
    self.setupDescriptionLabel.font = [UIFont systemFontOfSize:15 weight:UIFontWeightMedium];
    self.setupDescriptionLabel.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.setupDescriptionLabel];

    UILayoutGuide *safe = self.view.safeAreaLayoutGuide;
    [NSLayoutConstraint activateConstraints:@[
        [bar.topAnchor constraintEqualToAnchor:safe.topAnchor constant:8],
        [bar.leadingAnchor constraintEqualToAnchor:safe.leadingAnchor constant:12],
        [self.setupDescriptionLabel.centerYAnchor constraintEqualToAnchor:bar.centerYAnchor],
        [self.setupDescriptionLabel.leadingAnchor constraintEqualToAnchor:bar.trailingAnchor constant:12],
        [self.setupDescriptionLabel.trailingAnchor constraintLessThanOrEqualToAnchor:safe.trailingAnchor constant:-12],
    ]];
}

- (void)showSettingsTapped {
    // Edits flow through the store live (onChange -> -settingsDidChange:), so no
    // reload-on-dismiss is needed here.
    PRSettingsHostingController *settings =
        [[PRSettingsHostingController alloc] initWithStore:self.settingsStore];
    __weak typeof(self) weakSelf = self;
    settings.onDone = ^{ [weakSelf dismissViewControllerAnimated:YES completion:nil]; };
    [self presentViewController:settings animated:YES completion:nil];
}

#pragma mark - Sound scheme

- (void)applySoundScheme:(NSInteger)scheme {
    [self setDisplayedSoundScheme:scheme];
    if (self.soundSchemeHandler) {
        self.soundSchemeHandler(scheme);
    } else {
        // No host wiring: drive the core directly.
        id<HeavyEventSink> core = [self core];
        HeavySynth synth = (scheme == 0) ? HeavySynthPhase
                         : (scheme == 1) ? HeavySynthCircleStrings
                                         : HeavySynthSoundScraper;
        [core selectSynth:synth];
        [core sendFloat:(float)scheme toReceiver:@"selectsound"];
    }
}

- (void)setDisplayedSoundScheme:(NSInteger)scheme {
    if (scheme < 0) scheme = 0;
    if (scheme > 6) scheme = 6;
    self.soundScheme = scheme;
}

#pragma mark - Setups

- (void)setupStepperChanged {
    [self applySetupForState:(int)lround(self.setupStepper.value)];
}

- (void)applySetupForState:(int)state {
    NSArray *pitches = [self.composition setupForState:state];
    if (pitches.count == 0) return;
    self.setupState = state;
    self.bowlSetup = [[SingingBowlSetup alloc] initWithPitches:[NSMutableArray arrayWithArray:pitches]];
    self.lastDrawnSize = CGSizeZero;  // force redraw at current size
    [self.view setNeedsLayout];
    [self updateSetupDescription];
}

- (void)updateSetupDescription {
    NSArray *descriptions = self.composition.setupDescriptions;
    NSString *text = (self.setupState >= 0 && self.setupState < (int)descriptions.count)
                   ? descriptions[self.setupState] : @"";
    self.setupDescriptionLabel.text = text;
    self.setupDescriptionLabel.hidden = !self.showSetupLabel;
}

// drawSetup: lays the rings out for the view size at call time, so (re)draw
// once the host has given us a real size, and again whenever it changes.
- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    self.bowlView.frame = self.view.bounds;
    CGSize size = self.view.bounds.size;
    if (self.bowlSetup && size.width > 0 && size.height > 0 &&
        !CGSizeEqualToSize(size, self.lastDrawnSize)) {
        // drawSetup: reads note_labels from NSUserDefaults; drive it from our
        // setting (the extension has its own defaults domain).
        [[NSUserDefaults standardUserDefaults] setBool:self.showNoteLabels forKey:@"note_labels"];
        [self.bowlView setSelectedColourScheme];
        [self.bowlView drawSetup:self.bowlSetup];
        self.lastDrawnSize = size;
    }
}

- (void)reloadComposition {
    if (!self.isViewLoaded) return;
    PRSettings *settings = [self.settingsStore currentSettings];
    self.appliedSettings = settings;
    self.composition = [PRCompositionFactory compositionForSettings:settings];
    self.showNoteLabels = settings.noteLabels;
    self.showSetupLabel = settings.setupLabel;
    [self setDisplayedSoundScheme:settings.sound];  // reflect only; caller applies

    int count = [self.composition numberOfSetups];
    self.setupStepper.maximumValue = MAX(0, count - 1);
    self.setupStepper.value = 0;

    [self applySetupForState:0];
}

// Apply only what changed between the last-applied settings and the new ones,
// so e.g. toggling a label doesn't reset the player back to the first setup.
- (void)settingsDidChange:(PRSettings *)settings {
    PRSettings *prev = self.appliedSettings;
    BOOL compositionChanged = !prev
        || prev.composition != settings.composition
        || prev.note1 != settings.note1 || prev.note2 != settings.note2 || prev.note3 != settings.note3
        || prev.scale1 != settings.scale1 || prev.scale2 != settings.scale2 || prev.scale3 != settings.scale3;
    BOOL soundChanged  = !prev || prev.sound != settings.sound;
    BOOL labelsChanged = !prev || prev.noteLabels != settings.noteLabels
        || prev.setupLabel != settings.setupLabel;

    self.appliedSettings = settings;

    if (compositionChanged) {
        [self reloadComposition];  // rebuilds + re-reads labels/sound display
    } else if (labelsChanged) {
        self.showNoteLabels = settings.noteLabels;
        self.showSetupLabel = settings.setupLabel;
        self.lastDrawnSize = CGSizeZero;
        [self.view setNeedsLayout];
        [self updateSetupDescription];
    }
    if (soundChanged) {
        [self applySoundScheme:settings.sound];
    }
}

#pragma mark - Geometry

- (CGFloat)maximumRadius {
    CGFloat halfW = CGRectGetWidth(self.view.bounds) / 2.0;
    CGFloat halfH = CGRectGetHeight(self.view.bounds) / 2.0;
    return sqrt((halfW * halfW) + (halfH * halfH));
}

- (CGFloat)distanceFromCenter:(CGPoint)point {
    CGFloat dx = point.x - CGRectGetMidX(self.view.bounds);
    CGFloat dy = point.y - CGRectGetMidY(self.view.bounds);
    return sqrt((dx * dx) + (dy * dy));
}

- (int)noteFromPosition:(CGPoint)point {
    CGFloat radius = [self distanceFromCenter:point] / [self maximumRadius];
    return [self.bowlSetup pitchAtRadius:radius];
}

- (id<HeavyEventSink>)core {
    return self.coreProvider ? self.coreProvider() : nil;
}

#pragma mark - Tap (note on)

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    id<HeavyEventSink> core = [self core];
    for (UITouch *touch in touches) {
        CGPoint point = [touch locationInView:self.view];
        int velocity = floorf(15 + (110 * (touch.majorRadius / 125.0)));
        if (velocity > 127) velocity = 127;
        if (velocity < 0) velocity = 0;
        [core sendNoteOn:1 pitch:[self noteFromPosition:point] velocity:velocity];
        // SingingBowlView animates the tapped ring in its own touchesBegan; we
        // only send the note. (Calling animate here too double-triggered the
        // CATransaction and made the tap flash/disappear.)
    }
}

#pragma mark - Pan (continuous "sing")

- (void)panGestureRecognized:(UIPanGestureRecognizer *)sender {
    id<HeavyEventSink> core = [self core];
    CGPoint point = [sender locationInView:self.view];

    CGFloat xVel = [sender velocityInView:self.view].x;
    CGFloat yVel = [sender velocityInView:self.view].y;
    CGFloat velHyp = sqrt((xVel * xVel) + (yVel * yVel));
    CGFloat velocity = log(velHyp) / 10.0;
    if (velocity < 0) velocity = 0;
    if (velocity > 1) velocity = 1;

    [core sendFloat:velocity toReceiver:@"singlevel"];
    [self.bowlView changeBowlVolumeTo:velocity];

    if (sender.state == UIGestureRecognizerStateBegan) {
        [core sendFloat:1 toReceiver:@"sing"];
        [core sendFloat:(float)[self noteFromPosition:point] toReceiver:@"singpitch"];
        self.currentlyPanningPitch = (UInt8)[self noteFromPosition:point];
        [self.bowlView continuouslyAnimateBowlAtRadius:[self distanceFromCenter:point]];

    } else if (sender.state == UIGestureRecognizerStateChanged) {
        CGFloat angle = (velHyp > 0) ? yVel / velHyp : 0;
        [core sendFloat:angle toReceiver:@"sinPanAngle"];
        [self.bowlView changeContinuousColour:angle forRadius:[self distanceFromCenter:point]];

        CGFloat xTrans = [sender translationInView:self.view].x;
        CGFloat yTrans = [sender translationInView:self.view].y;
        CGFloat trans = sqrt((xTrans * xTrans) + (yTrans * yTrans)) / kScreenDiagonal;
        [core sendFloat:trans toReceiver:@"panTranslation"];
        [self.bowlView changeContinuousAnimationSpeed:(3 * trans) + 0.1];

    } else if (sender.state == UIGestureRecognizerStateEnded ||
               sender.state == UIGestureRecognizerStateCancelled) {
        [core sendFloat:0 toReceiver:@"singlevel"];
        [core sendFloat:0 toReceiver:@"sing"];
        [self.bowlView stopAnimatingBowl];
    }
}

@end
