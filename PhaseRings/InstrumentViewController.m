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

// Diagonal used to normalise swirl translation into Heavy's panTranslation,
// matching the standalone app.
static const CGFloat kScreenDiagonal = 1280.0;

// Sound schemes, matching the standalone app's Settings (Root.plist `sound`).
// 0..1 are the Phase / String synths; 2..6 are SoundScraper samples.
static NSArray<NSString *> *SoundSchemeNames(void) {
    return @[@"Phase Synthesis", @"String Synthesis", @"Singing Bowls",
             @"Gongs", @"Crotales", @"Terracotta Pots", @"Marimba"];
}

@interface InstrumentViewController ()
@property (nonatomic, strong) SingingBowlView *bowlView;
@property (nonatomic, strong) SingingBowlSetup *bowlSetup;
@property (nonatomic, strong) GenerativeSetupComposition *composition;
@property (nonatomic) UInt8 currentlyPanningPitch;
@property (nonatomic) CGSize lastDrawnSize;
@property (nonatomic, strong) UIButton *soundButton;
@property (nonatomic) NSInteger soundScheme;
@property (nonatomic) BOOL showNoteLabels;
@end

@implementation InstrumentViewController

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

#pragma mark - Control bar

- (UIButton *)pillButtonWithTitle:(NSString *)title {
    UIButton *b = [UIButton buttonWithType:UIButtonTypeSystem];
    [b setTitle:title forState:UIControlStateNormal];
    [b setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    b.titleLabel.font = [UIFont systemFontOfSize:15 weight:UIFontWeightMedium];
    b.backgroundColor = [UIColor colorWithWhite:1.0 alpha:0.12];
    b.contentEdgeInsets = UIEdgeInsetsMake(6, 12, 6, 12);
    b.layer.cornerRadius = 14;
    b.translatesAutoresizingMaskIntoConstraints = NO;
    return b;
}

- (void)buildControlBar {
    // Sound scheme picker — a menu so all seven schemes are reachable without
    // crowding the bar; performance stays on the rings.
    self.soundButton = [self pillButtonWithTitle:SoundSchemeNames()[0]];
    self.soundButton.showsMenuAsPrimaryAction = YES;
    [self rebuildSoundMenu];

    UIButton *setupButton = [self pillButtonWithTitle:@"New Setup"];
    [setupButton addTarget:self action:@selector(newSetupTapped) forControlEvents:UIControlEventTouchUpInside];

    UIButton *labelsButton = [self pillButtonWithTitle:@"Labels"];
    [labelsButton addTarget:self action:@selector(toggleLabelsTapped) forControlEvents:UIControlEventTouchUpInside];

    UIStackView *bar = [[UIStackView alloc] initWithArrangedSubviews:@[self.soundButton, setupButton, labelsButton]];
    bar.axis = UILayoutConstraintAxisHorizontal;
    bar.spacing = 8;
    bar.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:bar];

    UILayoutGuide *safe = self.view.safeAreaLayoutGuide;
    [NSLayoutConstraint activateConstraints:@[
        [bar.topAnchor constraintEqualToAnchor:safe.topAnchor constant:8],
        [bar.leadingAnchor constraintEqualToAnchor:safe.leadingAnchor constant:12],
    ]];
}

- (void)rebuildSoundMenu {
    NSArray<NSString *> *names = SoundSchemeNames();
    NSMutableArray<UIAction *> *actions = [NSMutableArray array];
    for (NSInteger i = 0; i < (NSInteger)names.count; i++) {
        NSInteger scheme = i;
        UIAction *a = [UIAction actionWithTitle:names[i] image:nil identifier:nil
                                        handler:^(__kindof UIAction *action) {
            [self selectSoundScheme:scheme];
        }];
        a.state = (i == self.soundScheme) ? UIMenuElementStateOn : UIMenuElementStateOff;
        [actions addObject:a];
    }
    self.soundButton.menu = [UIMenu menuWithTitle:@"Sound" children:actions];
}

- (void)selectSoundScheme:(NSInteger)scheme {
    [self setDisplayedSoundScheme:scheme];
    if (self.soundSchemeHandler) {
        self.soundSchemeHandler(scheme);
    } else {
        // No host wiring: drive the core directly.
        HeavyCore *core = [self core];
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
    [self.soundButton setTitle:SoundSchemeNames()[scheme] forState:UIControlStateNormal];
    [self rebuildSoundMenu];
}

- (void)newSetupTapped {
    NSArray *pitches = [self.composition nextSetup];
    if (pitches.count == 0) return;
    self.bowlSetup = [[SingingBowlSetup alloc] initWithPitches:[NSMutableArray arrayWithArray:pitches]];
    self.lastDrawnSize = CGSizeZero;  // force redraw at current size
    [self.view setNeedsLayout];
}

- (void)toggleLabelsTapped {
    self.showNoteLabels = !self.showNoteLabels;
    self.lastDrawnSize = CGSizeZero;
    [self.view setNeedsLayout];
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
        // toggle (the extension has its own defaults domain).
        [[NSUserDefaults standardUserDefaults] setBool:self.showNoteLabels forKey:@"note_labels"];
        [self.bowlView setSelectedColourScheme];
        [self.bowlView drawSetup:self.bowlSetup];
        self.lastDrawnSize = size;
    }
}

- (void)reloadComposition {
    // A pleasant default spread; the standalone app reads NSUserDefaults, but
    // the plugin just ships a sensible generative composition.
    NSArray *notes = @[@45, @50, @57];
    NSArray *scales = @[@"IONIAN", @"MIXOLYDIAN", @"AEOLIAN"];
    self.composition = [[GenerativeSetupComposition alloc] initWithRootNotes:notes andScales:scales];
    NSArray *pitches = [self.composition firstSetup];
    self.bowlSetup = [[SingingBowlSetup alloc] initWithPitches:[NSMutableArray arrayWithArray:pitches]];
    // Force a redraw at the next layout pass (when the real size is known).
    self.lastDrawnSize = CGSizeZero;
    [self.view setNeedsLayout];
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

- (HeavyCore *)core {
    return self.coreProvider ? self.coreProvider() : nil;
}

#pragma mark - Tap (note on)

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    HeavyCore *core = [self core];
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
    HeavyCore *core = [self core];
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
