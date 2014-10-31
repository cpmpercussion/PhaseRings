//
//  ViewController.m
//  Chorale
//
//  Created by Charles Martin on 20/01/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#define TEST_PITCHES @[@36,@39,@43,@47,@51,@58,@62,@76,@80]
#define METATONE_NEWSECTION_MESSAGE @"NEWSECTION"
#define METATONE_NEWIDEA_MESSAGE @"new_idea"
#define IPAD_SCREEN_DIAGONAL_LENGTH 1280
#define ENSEMBLE_STATUS_MODE NO

#define PHASE_SYNTH_PATCH @"PhaseRingSynthEnvironment.pd"
#define STRING_SYNTH_PATCH @"CircleStringsSynthEnvironment.pd"
#define BOWL_SYNTH_PATCH @"SoundScraperSynthEnvironment.pd"
#define GONG_SYNTH_PATCH @"SoundScraperSynthEnvironment.pd"
#define CROTALES_SYNTH_PATCH @"SoundScraperSynthEnvironment.pd"
#define POT_SYNTH_PATCH @"SoundScraperSynthEnvironment.pd"
#define MARIMBA_SYNTH_PATCH @"SoundScraperSynthEnvironment.pd"
#define SOUND_SCHEMES @[PHASE_SYNTH_PATCH,STRING_SYNTH_PATCH,BOWL_SYNTH_PATCH,GONG_SYNTH_PATCH,CROTALES_SYNTH_PATCH,POT_SYNTH_PATCH,MARIMBA_SYNTH_PATCH]
#define BASE_A 33

#import "ViewController.h"
#import "ScaleMaker.h"
#import "SingingBowlSetup.h"
#import "SingingBowlView.h"
#import "MetatoneEnsembleView.h"
#import "SingingBowlComposition.h"
//#import "TestChoraleComposition.h"
//#import "StudyInBowls1.h"
#import "GenerativeSetupComposition.h"

@interface ViewController ()
// Audio
@property (strong,nonatomic) PdAudioController *audioController;
@property (strong,nonatomic) PdFile *openFile;
@property (strong, nonatomic) SingingBowlSetup *bowlSetup;
// Network
@property (strong,nonatomic) MetatoneNetworkManager *networkManager;
@property (strong,nonatomic) NSMutableDictionary *metatoneClients;
//UI
@property (weak, nonatomic) IBOutlet SingingBowlView *bowlView;
@property (weak, nonatomic) IBOutlet MetatoneEnsembleView *ensembleView;

@property (nonatomic) CGFloat viewRadius;
@property (weak, nonatomic) IBOutlet UISlider *distortSlider;
@property (weak, nonatomic) IBOutlet UILabel *oscStatusLabel;
@property (weak, nonatomic) IBOutlet UIStepper *compositionStepper;
@property (weak, nonatomic) IBOutlet UIButton *settingsButton;
@property (weak, nonatomic) IBOutlet UILabel *playerStatusLabel;
@property (weak, nonatomic) IBOutlet UILabel *gestureStatusLabel;
@property (weak, nonatomic) IBOutlet UILabel *ensembleStatusLabel;
// Composition
@property (strong,nonatomic) SingingBowlComposition *composition;
@property (strong, nonatomic) NSDate* timeOfLastNewIdea;
@end

@implementation ViewController
#pragma mark - Setup

- (PdAudioController *) audioController
{
    if (!_audioController) _audioController = [[PdAudioController alloc] init];
    return _audioController;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self.distortSlider setHidden:YES];
    [self.compositionStepper setHidden:NO];
    [self.oscStatusLabel setHidden:NO];
    
    // Setup Pd
    if([self.audioController configurePlaybackWithSampleRate:44100 numberChannels:2 inputEnabled:NO mixingEnabled:YES] != PdAudioOK) {
        NSLog(@"LIBPD: failed to initialise audioController");
    } else { NSLog(@"LIBPD: audioController initialised."); }
    
    [self openPdPatch];
    [self.audioController setActive:YES];
    [self.audioController print];
    [PdBase setDelegate:self];
    self.midiManager = [[MetatoneMidiManager alloc] init];
    
    // Setup composition
    [self openComposition];
    
    // Setup Network
    self.metatoneClients = [[NSMutableDictionary alloc] init];
    self.networkManager = [[MetatoneNetworkManager alloc] initWithDelegate:self shouldOscLog:YES];
    self.timeOfLastNewIdea = [NSDate date];
    
    // Ensemble Heads Up Display
    if (ENSEMBLE_STATUS_MODE) {
        NSLog(@"Displaying Ensemble Status UI");
        [self.ensembleStatusLabel setHidden:NO];
        [self.playerStatusLabel setHidden:NO];
        [self.gestureStatusLabel setHidden:NO];
        [self.ensembleView setHidden:NO];
    } else {
        NSLog(@"Hiding Ensemble Status UI");
        [self.ensembleStatusLabel setHidden:YES];
        [self.playerStatusLabel setHidden:YES];
        [self.gestureStatusLabel setHidden:YES];
        [self.ensembleView setHidden:YES];
    }
    
    // Hide settings button until it really really works.
    [self.settingsButton setHidden:YES];
    
}

- (void) openComposition {
    #pragma mark TODO - add some more interesting way to specify octave for each base note.
    [[NSUserDefaults standardUserDefaults] synchronize];
    // 36 -- C two below middle C
    // 33 - A below that.
    NSInteger note1 = BASE_A + [[NSUserDefaults standardUserDefaults] integerForKey:@"note_1"];
    NSInteger note2 = BASE_A + [[NSUserDefaults standardUserDefaults] integerForKey:@"note_2"];
    NSInteger note3 = BASE_A + [[NSUserDefaults standardUserDefaults] integerForKey:@"note_3"];
    NSInteger scale_1 = [[NSUserDefaults standardUserDefaults] integerForKey:@"scale_1"];
    NSInteger scale_2 = [[NSUserDefaults standardUserDefaults] integerForKey:@"scale_2"];
    NSInteger scale_3 = [[NSUserDefaults standardUserDefaults] integerForKey:@"scale_3"];
    
    NSArray *scalesList = @[@"IONIAN",@"DORIAN",@"PHRYGIAN",@"LYDIAN",@"MIXOLYDIAN",@"AEOLIAN",@"LOCHRIAN",@"LYDIANSHARPFIVE",@"MIXOFLATSIX",@"OCTATONIC",@"WHOLETONE"];
    
    NSArray *notes = @[[NSNumber numberWithInteger:note1],[NSNumber numberWithInteger:note2],[NSNumber numberWithInteger:note3]];
    NSArray *scales = @[[scalesList objectAtIndex:scale_1],[scalesList objectAtIndex:scale_2],[scalesList objectAtIndex:scale_3]];
    
    NSLog(@"COMPOSITION OPENING: Base notes will be: %@",notes);
    NSLog(@"COMPOSITION OPENING: Scales will be %@",scales);
    NSLog(@"COMPOSITION OPENING: Opening composition");
    
    self.composition = [[GenerativeSetupComposition alloc] initWithRootNotes:notes andScales:scales];
    
    [self.compositionStepper setMinimumValue:0];
    [self.compositionStepper setMaximumValue:[self.composition numberOfSetups]];
    [self.compositionStepper setWraps:YES];
    
    // Update bowl view.
    self.bowlSetup = [[SingingBowlSetup alloc] initWithPitches:[NSMutableArray arrayWithArray:[self.composition firstSetup]]];
    self.viewRadius = [self calculateMaximumRadius];
    self.bowlView.displayNoteNames = [[NSUserDefaults standardUserDefaults] boolForKey:@"note_labels"];
    [self.bowlView drawSetup:self.bowlSetup];
}


// Checks settings to which sound scheme is selected. If it's different from what
// is currently open or nothing is open, the new scheme's Pd patch is opened.
- (void) openPdPatch {
    [[NSUserDefaults standardUserDefaults] synchronize];
    NSInteger soundScheme = [[NSUserDefaults standardUserDefaults] integerForKey:@"sound"];
    NSLog(@"PATCH OPENING: Sound Scheme value: %ld", (long) soundScheme);
    NSString *patchName = [SOUND_SCHEMES objectAtIndex:soundScheme];
    if (patchName) {
        NSLog(@"PATCH OPENING: Patch found: %@",patchName);
    } else {
        patchName = PHASE_SYNTH_PATCH;
        NSLog(@"PATCH OPENING: Patch not found, defaulting to %@",PHASE_SYNTH_PATCH);
    }
    //    [PdBase openFile:patchName path:[[NSBundle mainBundle] bundlePath]];
    
    if (![self.openFile.baseName isEqualToString:patchName]) {
        NSLog(@"PATCH OPENING: Patch not open, opening now.");
        [self.openFile closeFile];
        self.openFile = [PdFile openFileNamed:patchName path:[[NSBundle mainBundle] bundlePath]];
    } else {
        NSLog(@"PATCH OPENING: Patch already open, doing nothing.");
    }
    [PdBase sendFloat:[[NSUserDefaults standardUserDefaults] integerForKey:@"sound"] toReceiver:@"selectsound"];
}

- (void) applyNewSetup: (NSArray *) setup {
    NSLog(@"Drawing new setup.");
    self.bowlSetup = [[SingingBowlSetup alloc] initWithPitches:[NSMutableArray arrayWithArray:setup]];
    [self.bowlView drawSetup:self.bowlSetup];
}

- (void) viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    NSLog(@"View is changing size!! Do something about it."); // Doesn't work yet!
}

- (void) viewWillAppear:(BOOL)animated {
    NSLog(@"View will appear.");
}

- (void) viewDidLayoutSubviews {
    NSLog(@"View Will layout subviews.");
    [self.bowlView drawSetup:self.bowlSetup];
}

#pragma mark - Touch Methods
-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    for (UITouch * touch in [touches objectEnumerator]) {
        CGPoint point = [touch locationInView:self.view];
        int velocity = floorf(15 + (110*((touch.majorRadius)/125)));
        if (velocity > 127) velocity = 127;
        if (velocity < 0) velocity = 0;
        [PdBase sendNoteOn:1 pitch:[self noteFromPosition:point] velocity:velocity];
        [self.networkManager sendMessageWithTouch:point Velocity:0.0];
    }
}

-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    for (UITouch *touch in [touches objectEnumerator]) {
        CGFloat xVelocity = [touch locationInView:self.view].x - [touch previousLocationInView:self.view].x;
        CGFloat yVelocity = [touch locationInView:self.view].y - [touch previousLocationInView:self.view].y;
        CGFloat velocity = sqrt((xVelocity * xVelocity) + (yVelocity * yVelocity));
        [self.networkManager sendMessageWithTouch:[touch locationInView:self.view] Velocity:velocity];
    }
}

-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    for (UITouch *touch in [touches objectEnumerator]) {
        [self.networkManager sendMessageTouchEnded];
    }
}

- (IBAction)panGestureRecognized:(UIPanGestureRecognizer *)sender {
    CGFloat xVelocity = [sender velocityInView:self.view].x;
    CGFloat yVelocity = [sender velocityInView:self.view].y;
    CGFloat velHyp = sqrt((xVelocity * xVelocity) + (yVelocity * yVelocity));
    CGFloat velocity = log(velHyp)/10;
    if (velocity < 0) velocity = 0;
    if (velocity > 1) velocity = 1;
    [PdBase sendFloat:velocity toReceiver:@"singlevel" ];
    [self.bowlView changeBowlVolumeTo:velocity];
    
    if ([sender state] == UIGestureRecognizerStateBegan) { // pan began
        [PdBase sendFloat:1 toReceiver:@"sing"];
        [PdBase sendFloat:(float) [self noteFromPosition:[sender locationInView:self.view]] toReceiver:@"singpitch"];
        
        [self.bowlView continuouslyAnimateBowlAtRadius:[self calculateDistanceFromCenter:[sender locationInView:self.view]]];
        
    } else if ([sender state] == UIGestureRecognizerStateChanged) { // pan changed
        [PdBase sendFloat:velocity toReceiver:@"singlevel" ]; // Send Velocity
//        NSLog(@"Sing Velocity: %f",velocity);

        
        // send angle message to PD.
        CGFloat angle = [sender velocityInView:self.view].y/velHyp;
        [PdBase sendFloat:angle toReceiver:@"sinPanAngle"];
        [self.bowlView changeContinuousColour:angle forRadius:[self calculateDistanceFromCenter:[sender locationInView:self.view]]];
        //NSLog(@"%f",[sender velocityInView:self.view].y/velHyp);
        // send distance var to PD.
        CGFloat xTrans = [sender translationInView:self.view].x;
        CGFloat yTrans = [sender translationInView:self.view].y;
        CGFloat trans = sqrt((xTrans * xTrans) + (yTrans * yTrans)) / IPAD_SCREEN_DIAGONAL_LENGTH;
        //NSLog(@"%f",trans);
        [PdBase sendFloat:trans toReceiver:@"panTranslation"];
        [self.bowlView changeContinuousAnimationSpeed:(3*trans) + 0.1];
        
    } else if (([sender state] == UIGestureRecognizerStateEnded) || ([sender state] == UIGestureRecognizerStateCancelled)) { // panended
        [PdBase sendFloat:0 toReceiver:@"singlevel"];
        [PdBase sendFloat:0 toReceiver:@"sing"];
        [self.bowlView stopAnimatingBowl];
    }
}

- (IBAction)steppedMoved:(UIStepper *)sender {
    int state = (int) sender.value;
    NSArray *newSetup = [self.composition setupForState:state];
    [self applyNewSetup:newSetup];
    //    [PdBase sendFloat:(float) arc4random_uniform(6) toReceiver:@"changesound"];
}
- (IBAction)sliderMoved:(UISlider *)sender {
    [self setDistortion:[sender value]];
}

#pragma mark TODO: Make the settings button work somehow.
- (IBAction)settingsPressed:(UIButton *)sender {
    NSLog(@"Settings Pressed!");
}

-(void)setDistortion:(float)level {
    [PdBase sendFloat:level toReceiver:@"distortlevel"];
}


#pragma mark - Utils
-(CGFloat)calculateMaximumRadius {
    CGFloat xDist = (self.view.center.x);
    CGFloat yDist = (self.view.center.y);
    return sqrt((xDist * xDist) + (yDist * yDist));
}


-(CGFloat)calculateDistanceFromCenter:(CGPoint)touchPoint {
    CGFloat xDist = (touchPoint.x - self.view.center.x);
    CGFloat yDist = (touchPoint.y - self.view.center.y);
    return sqrt((xDist * xDist) + (yDist * yDist));
}

-(int)noteFromPosition:(CGPoint) point
{
    CGFloat distance = [self calculateDistanceFromCenter:point];
    CGFloat radius = distance/self.viewRadius;
    int note = [self.bowlSetup pitchAtRadius:radius];
    return note;
}

#pragma mark - Metatone Network Methods
-(void)searchingForLoggingServer {
//    [self.oscStatusLabel setText:@"searching for classifier 😒"];
    [self.oscStatusLabel setText:@""];
}

-(void)stoppedSearchingForLoggingServer {
    [self.oscStatusLabel setText:@"classifier not found! 😰"];
}

-(void)metatoneClientFoundWithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {
    [self.metatoneClients setObject:address forKey:hostname];
    NSString *clientNames = @"";
    for (NSString* name in [self.metatoneClients keyEnumerator]) {
        clientNames = [clientNames stringByAppendingString:name];
        clientNames = [clientNames stringByAppendingString:@"\n"];
    }
    [self.playerStatusLabel setText:clientNames];
    [self.ensembleView drawEnsemble:self.metatoneClients];
}

-(void)metatoneClientRemovedwithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {}

-(void)loggingServerFoundWithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {
    [self.oscStatusLabel setText:[NSString stringWithFormat:@"connected to %@ 👍", hostname]];
    // cancel manual mode.
    [self.distortSlider setHidden:YES];
    [self.compositionStepper setHidden:YES];
    [self.oscStatusLabel setHidden:NO];
}

-(void)didReceiveMetatoneMessageFrom:(NSString *)device withName:(NSString *)name andState:(NSString *)state {
    //NSLog([NSString stringWithFormat:@"METATONE: Received app message from:%@ with state:%@",device,state]);
}

-(void)didReceiveEnsembleEvent:(NSString *)event forDevice:(NSString *)device withMeasure:(NSNumber *)measure {
    NSLog(@"EnsembleEvent: %@ \n",event);
    if ([event isEqualToString:METATONE_NEWIDEA_MESSAGE] && ([self.timeOfLastNewIdea timeIntervalSinceNow] < -10.0)) {
        NSArray *newSetup = [self.composition nextSetup];
        [self applyNewSetup:newSetup];
        //[self.compositionStepper setValue:(self.compositionStepper.value + 1)];
        self.timeOfLastNewIdea = [NSDate date];
    } else {
        NSLog(@"Ensemble Event Received: Too soon after last event!");
    }
}

-(void)didReceiveGestureMessageFor:(NSString *)device withClass:(NSString *)class {
    NSLog(@"Gesture: %@",class);
    [self.gestureStatusLabel setText:class];
}

-(void)didReceiveEnsembleState:(NSString *)state withSpread:(NSNumber *)spread withRatio:(NSNumber*) ratio{
    NSLog(@"Ensemble State: %@",state);
    [self.ensembleStatusLabel setText:state];
    if ([state isEqualToString:@"divergence"] && [spread floatValue] < 10.0 && [spread floatValue] > -10.0) {
        float newDistort = [spread floatValue];
        [self.distortSlider setValue:newDistort animated:YES];
        [self setDistortion:newDistort];
        NSLog(@"Distortion Reduced to %f",newDistort);
    } else {
        float oldDistort = [self.distortSlider value];
        float newDistort = oldDistort * 0.5;
        if (newDistort <= 1 && newDistort >= 0) {
            [self.distortSlider setValue:newDistort animated:YES];
            [self setDistortion:newDistort];
            NSLog(@"Distortion Reduced to %f",newDistort);
        }
    }
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}


-(void) receivePrint:(NSString *)message {
    NSLog(@"Pd: %@",message);
}

@end
