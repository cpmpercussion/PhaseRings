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

#define METATONE_EXPERIMENT_BOTH @"/metatone/experiment/both"
#define METATONE_EXPERIMENT_BUTTON @"/metatone/experiment/button"
#define METATONE_EXPERIMENT_SERVER @"/metatone/experiment/server"
#define METATONE_EXPERIMENT_NONE @"/metatone/experiment/none"

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
#define NUMBER_COMPOSITIONS_AVAILABLE 5
#define BASE_A 33
// Audiobus API Key v1.1.
//#define AUDIOBUS_API_KEY @"MCoqKlBoYXNlUmluZ3MqKipQaGFzZVJpbmdzLTEuMS5hdWRpb2J1czovLw==:jTpvhuIUrdRrePgvcT7+ZUXZwsDApvArFO7iOO5+91PWD6l9brvWT8lZu3Jxq85v0uK10mdzragYHbm+1K7rvB0G6FnkVrvC/WjQ4ELkA40s+idjVA7fgnaRu3csGFy4"
// Audiobus API Key v1.2.
#define AUDIOBUS_API_KEY @"MCoqKlBoYXNlUmluZ3MqKipQaGFzZVJpbmdzLTEuMi5hdWRpb2J1czovLyoqKlthdXJnLmNtcGMuc3ludC4yXQ==:iKMBjau2P6z7AzkLUJ6nwJmdDOMO3FZV5PYqKqnJAykOb+r16NrbWRJEZSW0gsgOtndbwCKdeRgO95BkDgE4JIUIUY3t/BH5RsXuR7bO/nx84WSmqIVW8OTNet0XiDRJ"
#define BACKGROUND_SOUND_ALWAYS_ON YES
#define SAMPLE_RATE 44100
#define SOUND_OUTPUT_CHANNELS 2
#define TICKS_PER_BUFFER 4

#import "ViewController.h"
#import "ScaleMaker.h"
#import "SingingBowlSetup.h"
#import "SingingBowlView.h"
#import "MetatoneEnsembleView.h"
#import "SingingBowlComposition.h"
#import "GenerativeSetupComposition.h"

#define CLOUD_SERVER_TESTING_MODE YES

#define PERFORMANCE_TYPE_LOCAL 0
#define PERFORMANCE_TYPE_REMOTE 1
#define EXPERIMENT_TYPE_BOTH 2
#define EXPERIMENT_TYPE_NONE 3
#define EXPERIMENT_TYPE_BUTTON 4
#define EXPERIMENT_TYPE_SERVER 5
#define EXPERIMENT_TYPE_BUTTON_FADE 6

@interface ViewController ()
// Audio
@property (strong,nonatomic) PdAudioController *audioController;
@property (strong,nonatomic) PdFile *openFile;
@property (strong, nonatomic) SingingBowlSetup *bowlSetup;
@property (nonatomic) UInt8 currentlyPanningPitch;
@property (nonatomic) int playbackPanGestureState;
@property (nonatomic) CGPoint lastPlaybackTouchPoint;
@property (nonatomic) CGFloat lastPlaybackTouchVelocity;

// Network
@property (strong,nonatomic) MetatoneNetworkManager *networkManager;
@property (strong,nonatomic) NSMutableDictionary *metatoneClients;
//UI
@property (weak, nonatomic) IBOutlet SingingBowlView *bowlView;
@property (weak, nonatomic) IBOutlet MetatoneEnsembleView *ensembleView;

//@property (nonatomic) CGFloat viewRadius;
@property (weak, nonatomic) IBOutlet UISlider *distortSlider;
@property (weak, nonatomic) IBOutlet UILabel *oscStatusLabel;
@property (weak, nonatomic) IBOutlet UILabel *setupDescription;
@property (weak, nonatomic) IBOutlet UIStepper *compositionStepper;
@property (weak, nonatomic) IBOutlet UIButton *settingsButton;

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
    [self.experimentNewSetupButton setHidden:YES];
    [self.compositionStepper setHidden:NO];
    [self updateUITextLabels];
    [self startAudioEngine];
    [self setupAudioBus];
    
    [PdBase setDelegate:self];
    self.midiManager = [[MetatoneMidiManager alloc] init];
    
    // Setup composition
    [self openComposition];
    
    // Setup Network
    [self setupOSCLogging];
    self.timeOfLastNewIdea = [NSDate date];
    
    // Ensemble Heads Up Display
    #pragma mark TODO What is Ensemble Status Mode and is it necessary anymore? Consider removing.
    if (ENSEMBLE_STATUS_MODE) {
        NSLog(@"Displaying Ensemble Status UI");
        [self.ensembleView setHidden:NO];
    } else {
        NSLog(@"Hiding Ensemble Status UI");
        [self.ensembleView setHidden:YES];
    }
    [self.experimentNewSetupButton setHidden:YES];
    self.experimentMode = NO;
    self.listenToMetatoneClassifierMessages = YES;
}


#pragma mark - Audio Setup Methods.
-(void) setupAudioBus {
    //Set Audio Session Properties
    NSString *category = AVAudioSessionCategoryPlayAndRecord;
    // Should the category be: AVAudioSessionCategoryPlayback
    AVAudioSessionCategoryOptions options = AVAudioSessionCategoryOptionAllowBluetoothA2DP|AVAudioSessionCategoryOptionMixWithOthers|AVAudioSessionCategoryOptionDefaultToSpeaker;
    NSError *error = nil;
    if ( ![[AVAudioSession sharedInstance] setCategory:category withOptions:options error:&error] ) {
        NSLog(@"Couldn't set audio session category: %@", error);
    } else {
        NSLog(@"Audio Session Properties seem to be saved.");
    }
    self.audiobusController = [[ABAudiobusController alloc] initWithApiKey:AUDIOBUS_API_KEY];
    [self.audiobusController setConnectionPanelPosition:ABConnectionPanelPositionRight];
    self.senderport = [[ABSenderPort alloc] initWithName:@"PhaseRings"
                                                   title:@"Audio Output"
                               audioComponentDescription:(AudioComponentDescription) {
                                   .componentType = kAudioUnitType_RemoteGenerator,
                                   .componentSubType = 'synt',
                                   .componentManufacturer = 'cmpc'
                               }
                                               audioUnit:self.audioController.audioUnit.audioUnit];
    [self.audiobusController addSenderPort:self.senderport];
    // Set the AudioBus StateIO Delegate Here.
    [self.audiobusController setStateIODelegate:self];
}

- (void) startAudioEngine {
    [self.audioController configurePlaybackWithSampleRate:SAMPLE_RATE numberChannels:SOUND_OUTPUT_CHANNELS inputEnabled:NO mixingEnabled:YES];
    [self.audioController configureTicksPerBuffer:TICKS_PER_BUFFER];
    [self openPdPatch];
    [self.audioController setActive:YES];
    [self.audioController print];
    NSLog(@"Ticks Per Buffer: %d",self.audioController.ticksPerBuffer);
}

- (void) shutdownSoundProcessing {
    if (!BACKGROUND_SOUND_ALWAYS_ON) {
        [self.audioController setActive:YES];
    }
}

- (void) restartSoundProcessing {
    if (!self.audioController.isActive) {
        [self openPdPatch];
        [self.audioController setActive:YES];
    }
}


#pragma mark - Pd Send/Receive Methods
-(void) receivePrint:(NSString *)message {
    NSLog(@"Pd: %@",message);
}

- (void) openComposition {
    #pragma mark TODO - add some more interesting way to specify octave for each base note.
    [[NSUserDefaults standardUserDefaults] synchronize];
    // 36 -- C two below middle C
    // 33 - A below that.
    NSInteger compositionSetting = [[NSUserDefaults standardUserDefaults] integerForKey:@"composition"];
    NSInteger note1 = BASE_A + [[NSUserDefaults standardUserDefaults] integerForKey:@"note_1"];
    NSInteger note2 = BASE_A + [[NSUserDefaults standardUserDefaults] integerForKey:@"note_2"];
    NSInteger note3 = BASE_A + [[NSUserDefaults standardUserDefaults] integerForKey:@"note_3"];
    NSInteger scale_1 = [[NSUserDefaults standardUserDefaults] integerForKey:@"scale_1"];
    NSInteger scale_2 = [[NSUserDefaults standardUserDefaults] integerForKey:@"scale_2"];
    NSInteger scale_3 = [[NSUserDefaults standardUserDefaults] integerForKey:@"scale_3"];
    NSArray *scalesList = @[@"IONIAN",@"DORIAN",@"PHRYGIAN",@"LYDIAN",@"MIXOLYDIAN",@"AEOLIAN",@"LOCHRIAN",@"LYDIANSHARPFIVE",@"MIXOFLATSIX",@"OCTATONIC",@"WHOLETONE"];
    
    NSArray *notes = @[[NSNumber numberWithInteger:note1],[NSNumber numberWithInteger:note2],[NSNumber numberWithInteger:note3]];
    NSArray *scales = @[[scalesList objectAtIndex:scale_1],[scalesList objectAtIndex:scale_2],[scalesList objectAtIndex:scale_3]];
    switch (compositionSetting) {
        case 1:
            NSLog(@"COMPOSITION OPENING: Study in Bowls");
            notes = @[@41,@42,@48];
            scales = @[@"MIXOLYDIAN",@"LYDIAN",@"LYDIANSHARPFIVE"];
            break;
        case 2:
            NSLog(@"COMPOSITION OPENING: Amores");
            notes = @[@36,@37,@41];
            scales = @[@"MIXOFLATSIX",@"OCTATONIC",@"WHOLETONE"];
            break;
        case 3:
            NSLog(@"COMPOSITION OPENING: MixoSteps");
            notes = @[@36,@38,@41];
            scales = @[@"MIXOLYDIAN",@"MIXOLYDIAN",@"MIXOLYDIAN"];
            break;
        case 4:
            NSLog(@"COMPOSITION OPENING: Scheimpflug Principle");
            notes = @[@36,@38,@40];
            scales = @[@"WHOLETONE",@"MIXOFLATSIX",@"LOCHRIAN"];
            break;
        default:
            NSLog(@"COMPOSITION OPENING: Custom composition");
            notes = @[[NSNumber numberWithInteger:note1],[NSNumber numberWithInteger:note2],[NSNumber numberWithInteger:note3]];
            scales = @[[scalesList objectAtIndex:scale_1],[scalesList objectAtIndex:scale_2],[scalesList objectAtIndex:scale_3]];
            break;
    }
    NSLog(@"COMPOSITION OPENING: Base notes will be: %@, %@, %@",notes[0],notes[1],notes[2]);
    NSLog(@"COMPOSITION OPENING: Scales will be %@, %@, %@",scales[0],scales[1],scales[2]);
    
    self.composition = [[GenerativeSetupComposition alloc] initWithRootNotes:notes andScales:scales];
    [self.compositionStepper setMinimumValue:0];
    [self.compositionStepper setMaximumValue:[self.composition numberOfSetups] - 1];
    [self.compositionStepper setWraps:YES];
    [self updateSetupDescription:0];

    // Update bowl view.
    self.bowlSetup = [[SingingBowlSetup alloc] initWithPitches:[NSMutableArray arrayWithArray:[self.composition firstSetup]]];
//    self.viewRadius = [self calculateMaximumRadius];
    [self.bowlView drawSetup:self.bowlSetup];
}

-(void) updateUITextLabels {
    // Setup Description Label
    if ([[NSUserDefaults standardUserDefaults] boolForKey:@"setup_label"]) {
        [self.setupDescription setHidden:NO];
    } else {
        [self.setupDescription setHidden:YES];
    }
    // Setup OSC Status Label:
    if (self.experimentMode) {
//        NSLog(@"EXPERIMENT MODE: Showing OSC Status!");
        [self.oscStatusLabel setHidden:NO];
    } else if ([[NSUserDefaults standardUserDefaults] boolForKey:@"display_classifier_information"]) {
        [self.oscStatusLabel setHidden:NO];
    } else {
        [self.oscStatusLabel setHidden:YES];
    }
}

- (void) updateBowlViewColourScheme {
    if ([self.networkManager isClassifierConnected]) {
        [self.bowlView setServerColourScheme]; // Server Colours
    } else {
        [self.bowlView setSelectedColourScheme]; // Settings-Selected Colours
    }
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
    
    if (![self.openFile.baseName isEqualToString:patchName]) {
        NSLog(@"PATCH OPENING: Patch not open, opening now.");
        [self.openFile closeFile];
        self.openFile = [PdFile openFileNamed:patchName path:[[NSBundle mainBundle] bundlePath]];
    } else {
        NSLog(@"PATCH OPENING: Patch already open, doing nothing.");
    }
    [PdBase sendFloat:[[NSUserDefaults standardUserDefaults] integerForKey:@"sound"] toReceiver:@"selectsound"];
    [PdBase sendFloat:[[NSUserDefaults standardUserDefaults] floatForKey:@"master_volume"] toReceiver:@"mastervolume"];
    [PdBase sendFloat:[[NSUserDefaults standardUserDefaults] floatForKey:@"reverb_volume"] toReceiver:@"reverbvolume"];
    if ([[NSUserDefaults standardUserDefaults] boolForKey:@"process_effects"]) {
        [PdBase sendFloat:1 toReceiver:@"processeffects"];
    } else {
        [PdBase sendFloat:0 toReceiver:@"processeffects"];
    }
}


#pragma mark - UI Methods

- (void) applyNewSetup: (NSArray *) setup {
    NSLog(@"VC: Drawing new setup.");
    self.bowlSetup = [[SingingBowlSetup alloc] initWithPitches:[NSMutableArray arrayWithArray:setup]];
    [self.bowlView drawSetup:self.bowlSetup];
}

- (void) updateSetupDescription:(int)state {
    NSString *newDescription = [[(GenerativeSetupComposition *) self.composition setupDescriptions] objectAtIndex:state];
    [self.setupDescription setText:newDescription];
    NSLog(@"VC: SETUP DESCRIPTION: %@",newDescription);
}

- (void) viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
}

- (void) viewWillAppear:(BOOL)animated {
}

- (void) viewDidLayoutSubviews {
#pragma mark TODO is drawing the setup necessary each time the subviews are laid out? maybe for rotation.
    // Laying out the subviews -- better draw the setup again?? Really?
    // Maybe this protects agains issues with rotation.
    [self.bowlView drawSetup:self.bowlSetup];
}

#pragma mark - Touch and Performance Methods

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    for (UITouch * touch in [touches objectEnumerator]) {
        CGPoint point = [touch locationInView:self.view];
        int velocity = floorf(15 + (110*((touch.majorRadius)/125)));
        if (velocity > 127) velocity = 127;
        if (velocity < 0) velocity = 0;
        [PdBase sendNoteOn:1 pitch:[self noteFromPosition:point] velocity:velocity];
        
        if ([[NSUserDefaults standardUserDefaults] boolForKey:@"midi_out"]) {
            [self.networkManager sendMessageWithTouch:point Velocity:0.0];
            const UInt8 noteOn[]  = { 0x90, [self noteFromPosition:point], velocity };
            [self.midiManager.midi sendBytes:noteOn size:sizeof(noteOn)];
            // TODO delay noteOff message by a short amount - say 20ms.
            const UInt8 noteOff[]  = { 0x80, [self noteFromPosition:point], velocity };
            [self.midiManager.midi sendBytes:noteOff size:sizeof(noteOff)];
        }
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
        CGPoint touchFirstPoint = [touch locationInView:self.view];
        // Maybe handle noteOff here for ending touches.
        // TODO delay noteOff message by a short amount - say 20ms.
        #pragma mark TODO: make sure note off is working properly.
        const UInt8 noteOff[]  = { 0x80, [self noteFromPosition:touchFirstPoint], 0 };
        [self.midiManager.midi sendBytes:noteOff size:sizeof(noteOff)];
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
        self.currentlyPanningPitch = (UInt8) [self noteFromPosition:[sender locationInView:self.view]];
        
        if ([[NSUserDefaults standardUserDefaults] boolForKey:@"midi_out"]) {
            const UInt8 noteOn[] = {0x90,self.currentlyPanningPitch,(UInt8) (velocity * 127)};
            [self.midiManager.midi sendBytes:noteOn size:sizeof(noteOn)];
        }
        
        [self.bowlView continuouslyAnimateBowlAtRadius:[self calculateDistanceFromCenter:[sender locationInView:self.view]]];
        
    } else if ([sender state] == UIGestureRecognizerStateChanged) { // pan changed
        [PdBase sendFloat:velocity toReceiver:@"singlevel" ]; // Send Velocity
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
        // Send Translation as MIDI CC
        // UInt8 translation[] = {0x00,(UInt8) (trans * 127)};
        // Send Angle as MIDI CC
        // Send Velocity as note aftertouch.
        if ([[NSUserDefaults standardUserDefaults] boolForKey:@"midi_out"]) {
            const UInt8 aftertouch[] = {0xA0,self.currentlyPanningPitch,(UInt8) (velocity * 127)};
            [self.midiManager.midi sendBytes:aftertouch size:sizeof(aftertouch)];
        }
        
    } else if (([sender state] == UIGestureRecognizerStateEnded) || ([sender state] == UIGestureRecognizerStateCancelled)) { // panended
        [PdBase sendFloat:0 toReceiver:@"singlevel"];
        [PdBase sendFloat:0 toReceiver:@"sing"];
        [self.bowlView stopAnimatingBowl];
        if ([[NSUserDefaults standardUserDefaults] boolForKey:@"midi_out"]) {
            const UInt8 noteOff[] = {0x80,self.currentlyPanningPitch,(UInt8) (velocity * 127)};
            [self.midiManager.midi sendBytes:noteOff size:sizeof(noteOff)];
        }
    }
}

#pragma mark OSC Playback Methods

/*! Playback a single tapped note */
-(void)playbackTappedNote:(CGPoint) point {
    int velocity = 110;
    [PdBase sendNoteOn:1 pitch:[self noteFromPosition:point] velocity:velocity];
    [self.bowlView animateBowlAtRadius:[self calculateDistanceFromCenter:point]];
}

#define PAN_STATE_NOTHING 0
#define PAN_STATE_MOVING 1

/*! Playback a moving note */
-(void)playbackMovingNote:(CGPoint) point Vel:(CGFloat)vel {
    CGFloat angle = 0.5; //[sender velocityInView:self.view].y/velHyp;
    CGFloat velHyp = vel;
    CGFloat velocity = log(velHyp)/10;
    if (velocity < 0) velocity = 0;
    if (velocity > 1) velocity = 1;
    CGFloat trans = velocity / IPAD_SCREEN_DIAGONAL_LENGTH;
    // Always do these:
    [PdBase sendFloat:velocity toReceiver:@"singlevel" ];
    [self.bowlView changeBowlVolumeTo:velocity];
    
    if (self.playbackPanGestureState == PAN_STATE_NOTHING) {
        // Starting a Pan Gesture
        // TODO some kind of check to start the pan.
        [PdBase sendFloat:1 toReceiver:@"sing"];
        [PdBase sendFloat:(float) [self noteFromPosition:point] toReceiver:@"singpitch"];
        self.currentlyPanningPitch = (UInt8) [self noteFromPosition:point];
        [self.bowlView continuouslyAnimateBowlAtRadius:[self calculateDistanceFromCenter:point]];
        self.playbackPanGestureState = PAN_STATE_MOVING;
        // start timer
        self.playbackPanGestureTimeout = [NSTimer scheduledTimerWithTimeInterval:1.0f target:self selector:@selector(playbackStopContinuousNotes) userInfo:nil repeats:NO];
    } else {
        // Continuing a Pan Gesture
        [PdBase sendFloat:velocity toReceiver:@"singlevel" ]; // Send Velocity
        [PdBase sendFloat:angle toReceiver:@"sinPanAngle"];
        [self.bowlView changeContinuousColour:angle forRadius:[self calculateDistanceFromCenter:point]];
        [self.bowlView changeContinuousAnimationSpeed:(3*trans) + 0.1];
        [PdBase sendFloat:trans toReceiver:@"panTranslation"];
        [self.playbackPanGestureTimeout invalidate];
        self.playbackPanGestureTimeout = [NSTimer scheduledTimerWithTimeInterval:1.0f target:self selector:@selector(playbackStopContinuousNotes) userInfo:nil repeats:NO];
        // extend timer
    }
}

/*! Stop continuous notes in playback mode */
-(void)playbackStopContinuousNotes {
    // Stopping a pan gesture
    [PdBase sendFloat:0 toReceiver:@"singlevel"];
    [PdBase sendFloat:0 toReceiver:@"sing"];
    [self.bowlView stopAnimatingBowl];
    self.playbackPanGestureState = PAN_STATE_NOTHING;
    [self.playbackPanGestureTimeout invalidate];
}

/*! Process playback touches to tapped and moving notes. */
-(void)processPlaybackTouchWithX:(NSNumber *)x Y:(NSNumber *)y Vel:(NSNumber *)vel {
    CGPoint point = CGPointMake(x.floatValue, y.floatValue);
    CGFloat velocity = vel.floatValue;
    if (vel.floatValue > 0.0) {
        [self playbackMovingNote:point Vel:velocity];
    } else {
        [self playbackTappedNote:point];
        [self playbackStopContinuousNotes]; // any tap stops a swipe.
    }
}

#pragma mark UI Element Methods

- (IBAction)steppedMoved:(UIStepper *)sender {
    int state = (int) sender.value;
    NSArray *newSetup = [self.composition setupForState:state];
    [self applyNewSetup:newSetup];
    [self updateSetupDescription:state];
    [self.networkManager sendMetatoneMessage:@"CompositionStep" withState:[NSString stringWithFormat:@"%d",state]];
}
- (IBAction)sliderMoved:(UISlider *)sender {
    [self setDistortion:[sender value]];
}
-(void)setDistortion:(float)level {
    [PdBase sendFloat:level toReceiver:@"distortlevel"];
}

// New Setup Button just for Experiment Mode!
- (IBAction)experimentNewSetupButtonPressed:(UIButton *)sender {
    NSLog(@"New Setup Button Pressed!");
    int state = (int) (self.compositionStepper.value + 1) % (int) (self.compositionStepper.maximumValue + 1);
    NSLog(@"New Setup Number is: %d",state);
    [self.compositionStepper setValue:state];
    NSArray *newSetup = [self.composition setupForState:state];
    [self applyNewSetup:newSetup];
    [self updateSetupDescription:state];
    // Now randomise sound!
    [self randomiseSound];
    // Send to everyone in the network.
    [self.networkManager sendMetatoneMessageViaServer:@"CompositionStep" withState:[NSString stringWithFormat:@"%d",state]];
    if (self.buttonFadingMode) {
        // Fading out the button.
        [self fadeOutNewSetupButton];
    }
}

#define BUTTON_FADING_ANIMATION_TIME 2.0
- (void) fadeInNewSetupButton {
    //[self.experimentNewSetupButton setHidden:NO];
    NSLog(@"Fading in the button");
    [UIView animateWithDuration:BUTTON_FADING_ANIMATION_TIME animations:^{
        self.experimentNewSetupButton.alpha = 1;
    }];
}
- (void) fadeOutNewSetupButton {
    //[self.experimentNewSetupButton setHidden:YES];
    NSLog(@"Fading out the button");
    [UIView animateWithDuration:BUTTON_FADING_ANIMATION_TIME animations:^{
        self.experimentNewSetupButton.alpha = 0;
    }];
}

- (void) setVolumeReverbToDefault {
    [PdBase sendFloat:1.0 toReceiver:@"mastervolume"];
    [PdBase sendFloat:0.5 toReceiver:@"reverbvolume"];
}

- (void) randomiseSound {
    int newSound = arc4random_uniform((u_int32_t) [SOUND_SCHEMES count] -2 ) + 2;
    [[NSUserDefaults standardUserDefaults] setValue:[NSNumber numberWithInt:newSound] forKey:@"sound"];
}

#pragma mark - For note calculation.
-(CGFloat)calculateMaximumRadius {
    CGPoint cent = self.view.center;
    return sqrt((cent.x * cent.x) + (cent.y * cent.y));
}

-(CGFloat)calculateDistanceFromCenter:(CGPoint)touchPoint {
    CGFloat xDist = (touchPoint.x - self.view.center.x);
    CGFloat yDist = (touchPoint.y - self.view.center.y);
    return sqrt((xDist * xDist) + (yDist * yDist));
}

-(int)noteFromPosition:(CGPoint) point
{
    CGFloat distance = [self calculateDistanceFromCenter:point];
    CGFloat radius = distance / [self calculateMaximumRadius];
    int note = [self.bowlSetup pitchAtRadius:radius];
    return note;
}

#pragma mark - Metatone Classifier and Network Methods
#pragma mark TODO: clean up these methods to simplify the situation.
-(void)stopOSCLogging
{
    NSLog(@"VC: stopOSCLogging was called");
    [self.networkManager closeClassifierWebSocket];
}

-(void)setupOSCLogging {
    NSLog(@"VC: setupOSCLogging was called");
    self.metatoneClients = [[NSMutableDictionary alloc] init];
    self.networkManager = [[MetatoneNetworkManager alloc] initWithDelegate:self shouldOscLog:YES shouldConnectToWebClassifier:[[NSUserDefaults standardUserDefaults] boolForKey:@"web_classifier"]];
}

-(void)updateClassifierConnections {
    NSLog(@"VC: updateClassifierConnections was called.");
    if ([[NSUserDefaults standardUserDefaults] boolForKey:@"web_classifier"]) {
        [self.networkManager startConnectingToWebClassifier];
    } else {
        [self.networkManager stopConnectingToWebClassifier];
    }
}

-(void)searchingForLoggingServer {
    NSLog(@"VC: Searching for logging server.");
    [self.oscStatusLabel setText:@"classifier not connected"];
    [self updateBowlViewColourScheme];
}

-(void)stoppedSearchingForLoggingServer {
    NSLog(@"VC: Stopped searching for logging server.");
    [self.oscStatusLabel setText:@"classifier not connected"];
    [self updateBowlViewColourScheme];
}

-(void)metatoneClientFoundWithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {
    [self.metatoneClients setObject:address forKey:hostname];
    NSString *clientNames = @"";
    for (NSString* name in [self.metatoneClients keyEnumerator]) {
        clientNames = [clientNames stringByAppendingString:name];
        clientNames = [clientNames stringByAppendingString:@"\n"];
    }
    //    [self.playerStatusLabel setText:clientNames];
    [self.ensembleView drawEnsemble:self.metatoneClients];
}

-(void)metatoneClientRemovedwithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {}

-(void)loggingServerFoundWithAddress:(NSString *)address andPort:(int)port andHostname:(NSString *)hostname {
    NSLog(@"VC: Connected to logging server.");
    [self.oscStatusLabel setText:[NSString stringWithFormat:@"connected to %@", hostname]];
    [self updateBowlViewColourScheme];
    [self.bowlView drawSetup:self.bowlSetup];
    // Check whether to send remote control message to server.
    if ([[NSUserDefaults standardUserDefaults] boolForKey:@"remote_control_enabled"]) {
        [self.networkManager sendMessageRemoteControl];
    }
}

-(void)didReceiveMetatoneMessageFrom:(NSString *)device withName:(NSString *)name andState:(NSString *)state {
    NSLog(@"METATONE: Received app message from:%@ with state:%@",device,state);
//        [self.networkManager sendMetatoneMessage:@"CompositionStep" withState:[NSString stringWithFormat:@"%d",state]];
    if ([name isEqualToString:@"CompositionStep"]) {
        int newSetupNumber = [state intValue];
        if (newSetupNumber > self.compositionStepper.maximumValue) {
                    NSLog(@"METATONE: Can't set composition to state %d, above maximum value: %f", newSetupNumber,self.compositionStepper.maximumValue);
                    newSetupNumber = self.compositionStepper.maximumValue;
        }
        NSLog(@"METATONE: Setting composition to state %d",newSetupNumber);
        [self.compositionStepper setValue:newSetupNumber];
        NSArray *newSetup = [self.composition setupForState:newSetupNumber];
        [self applyNewSetup:newSetup];
        [self updateSetupDescription:newSetupNumber];
        if (self.experimentMode) [self randomiseSound];
        if (self.buttonFadingMode) [self fadeOutNewSetupButton]; // fade out after somebody presses the button.
    }
}

-(void)didReceiveEnsembleEvent:(NSString *)event forDevice:(NSString *)device withMeasure:(NSNumber *)measure {
    NSLog(@"EnsembleEvent: %@ \n",event);
    if (self.listenToMetatoneClassifierMessages) {
        if ([event isEqualToString:METATONE_NEWIDEA_MESSAGE] && ([self.timeOfLastNewIdea timeIntervalSinceNow] < -10.0)) {
            if (!self.buttonFadingMode) {
                // Change the setup and update the sound.
                NSArray *newSetup = [self.composition nextSetup];
                [self applyNewSetup:newSetup];
                if (self.experimentMode) [self randomiseSound];
            } else {
                // Fade in the button and wait for it to be pressed.
                [self fadeInNewSetupButton];
            }
            //[self.compositionStepper setValue:(self.compositionStepper.value + 1)];
            self.timeOfLastNewIdea = [NSDate date];
        } else {
            NSLog(@"Ensemble Event Received: Too soon after last event!");
        }
    }
}

-(void)didReceiveGestureMessageFor:(NSString *)device withClass:(NSString *)class {
    NSLog(@"Gesture: %@",class);
    //    [self.gestureStatusLabel setText:class];
}

#pragma TODO - fix up this section so that it does something more useful.
-(void)didReceiveEnsembleState:(NSString *)state withSpread:(NSNumber *)spread withRatio:(NSNumber*) ratio{
    //    NSLog(@"Ensemble State: %@",state);
    //    [self.ensembleStatusLabel setText:state];
    // Cut for experiment.
    if (self.listenToMetatoneClassifierMessages) {
        if ([state isEqualToString:@"divergence"] && [spread floatValue] < 10.0 && [spread floatValue] > -10.0) {
            float newDistort = [spread floatValue];
            [self.distortSlider setValue:newDistort animated:YES];
            [self setDistortion:newDistort];
//            NSLog(@"Distortion Reduced to %f",newDistort);
        } else {
            float oldDistort = [self.distortSlider value];
            float newDistort = oldDistort * 0.5;
            if (newDistort <= 1 && newDistort >= 0) {
                [self.distortSlider setValue:newDistort animated:YES];
                [self setDistortion:newDistort];
//                NSLog(@"Distortion Reduced to %f",newDistort);
            }
        }
    }
}

#pragma mark TODO make sure that Performance Start Events are working
// performance start events should be of the form:
// /metatone/performance/start (string) deviceID (int) type (composition) int
// the type should be
//#define PERFORMANCE_TYPE_LOCAL 0
//#define PERFORMANCE_TYPE_REMOTE 1
//#define EXPERIMENT_TYPE_BOTH 2
//#define EXPERIMENT_TYPE_NONE 3
//#define EXPERIMENT_TYPE_BUTTON 4
//#define EXPERIMENT_TYPE_SERVER 5
//#define EXPERIMENT_TYPE_BUTTON_FADE 6
//
// the composition is an int that corresponds to one of the available compositions,
// for the experiment, the int can be random (as long as everybody has the same one).
-(void)didReceivePerformanceStartEvent:(NSString *)event forDevice:(NSString *)device withType:(NSNumber *)type andComposition:(NSNumber *)composition {
    // Open the new composition
    NSLog(@"PERFORMANCE: Received Performance Event: %@, %@, %@, %@", event,device,type,composition);
    int newComposition = [composition intValue] % NUMBER_COMPOSITIONS_AVAILABLE;
    self.currentPerformanceType = [type intValue];
    switch (self.currentPerformanceType) {
        case PERFORMANCE_TYPE_LOCAL:
            // Local
            NSLog(@"PERFORMANCE: Starting Local Mode.");
            [self.compositionStepper setHidden:YES];
            [self.settingsButton setHidden:NO];
            [self.setupDescription setHidden:NO];
            [self.experimentNewSetupButton setHidden:YES];
            self.listenToMetatoneClassifierMessages = YES;
            self.buttonFadingMode = NO;
            self.experimentMode = NO;
            [[NSUserDefaults standardUserDefaults] setValue:[NSNumber numberWithInt:newComposition] forKey:@"composition"];
            break;
        case PERFORMANCE_TYPE_REMOTE:
            // Remote
            NSLog(@"PERFORMANCE: Starting Remote Mode. Normal");
            [self.compositionStepper setHidden:NO];
            self.buttonFadingMode = NO;
            [self.settingsButton setHidden:NO];
            [self.setupDescription setHidden:NO];
            [self.experimentNewSetupButton setHidden:YES];
            self.listenToMetatoneClassifierMessages = YES;
            self.experimentMode = NO;
            break;
        case EXPERIMENT_TYPE_BUTTON:
            // Button
            self.listenToMetatoneClassifierMessages = NO;
            self.buttonFadingMode = NO;
            self.experimentMode = YES;
            [self.oscStatusLabel setText:@"EXPERIMENT: Button control."];
            [self randomiseSound];
            [[NSUserDefaults standardUserDefaults] setValue:[NSNumber numberWithInt:newComposition] forKey:@"composition"];
            NSLog(@"EXPERIMENT: Starting Button Mode.");
            [self.compositionStepper setHidden:YES];
            [self.settingsButton setHidden:YES];
            [self.setupDescription setHidden:YES];
            [self.experimentNewSetupButton setHidden:NO];
            [self fadeInNewSetupButton];
            break;
        case EXPERIMENT_TYPE_SERVER:
            NSLog(@"EXPERIMENT: Starting Server Mode.");
            [self.oscStatusLabel setText:@"EXPERIMENT: Server control."];
            // Server
            self.listenToMetatoneClassifierMessages = YES;
            self.buttonFadingMode = NO;
            self.experimentMode = YES;
            [self randomiseSound];
            [[NSUserDefaults standardUserDefaults] setValue:[NSNumber numberWithInt:newComposition] forKey:@"composition"];
            [self.compositionStepper setHidden:YES];
            [self.settingsButton setHidden:YES];
            [self.setupDescription setHidden:YES];
            [self.experimentNewSetupButton setHidden:YES];
            [self fadeOutNewSetupButton];
            break;
        case EXPERIMENT_TYPE_NONE:
            NSLog(@"EXPERIMENT: Starting None Mode.");
            [self.oscStatusLabel setText:@"EXPERIMENT: No controls."];
            // None
            self.listenToMetatoneClassifierMessages = NO;
            self.buttonFadingMode = NO;
            self.experimentMode = YES;
            [self randomiseSound];
            [[NSUserDefaults standardUserDefaults] setValue:[NSNumber numberWithInt:newComposition] forKey:@"composition"];
            [self.compositionStepper setHidden:YES];
            [self.settingsButton setHidden:YES];
            [self.setupDescription setHidden:YES];
            [self.experimentNewSetupButton setHidden:YES];
            [self fadeOutNewSetupButton];
            break;
        case EXPERIMENT_TYPE_BOTH:
            NSLog(@"EXPERIMENT: Starting Both Mode.");
            [self.oscStatusLabel setText:@"EXPERIMENT: Button + Server."];
            // Both
            self.listenToMetatoneClassifierMessages = YES;
            self.buttonFadingMode = NO;
            self.experimentMode = YES;
            [self randomiseSound];
            [[NSUserDefaults standardUserDefaults] setValue:[NSNumber numberWithInt:newComposition] forKey:@"composition"];
            [self.compositionStepper setHidden:YES];
            [self.settingsButton setHidden:YES];
            [self.setupDescription setHidden:YES];
            [self.experimentNewSetupButton setHidden:NO];
            [self fadeInNewSetupButton];
            break;
        case EXPERIMENT_TYPE_BUTTON_FADE:
            NSLog(@"EXPERIMENT: Starting Button-Fade Mode.");
            [self.oscStatusLabel setText:@"EXPERIMENT: Button ⨯ Server."];
            // Fade
            self.listenToMetatoneClassifierMessages = YES;
            self.buttonFadingMode = YES;
            self.experimentMode = YES;
            [self randomiseSound];
            [[NSUserDefaults standardUserDefaults] setValue:[NSNumber numberWithInt:newComposition] forKey:@"composition"];
            [self.compositionStepper setHidden:YES];
            [self.settingsButton setHidden:YES];
            [self.setupDescription setHidden:YES];
            [self.experimentNewSetupButton setHidden:NO];
            [self fadeOutNewSetupButton];
            break;
        default:
            NSLog(@"PERFORMANCE: Unknown type: %d, changing to remote type!",self.currentPerformanceType);
            self.currentPerformanceType = PERFORMANCE_TYPE_REMOTE;
            // Remote
            [self.oscStatusLabel setText:@"Unknown performance type."];
            [self.compositionStepper setHidden:NO];
            [self.settingsButton setHidden:NO];
            [self.setupDescription setHidden:NO];
            [self.experimentNewSetupButton setHidden:YES];
            self.listenToMetatoneClassifierMessages = YES;
            self.buttonFadingMode = NO;
            self.experimentMode = YES;
            break;
    }
}

-(void)didReceivePerformanceEndEvent:(NSString *)event forDevice:(NSString *)device {
    // Performance end - go back to default configuration.
    NSLog(@"PERFORMANCE: Ended, going back to default state");
    [self searchingForLoggingServer];
    [self.compositionStepper setHidden:NO];
    [self.settingsButton setHidden:NO];
    [self.experimentNewSetupButton setHidden:YES];
    self.listenToMetatoneClassifierMessages = YES;
    [self updateUITextLabels];
    [self updateBowlViewColourScheme];
}

-(void) didReceiveGesturePlayMessageFor:(NSString*)device withClass:(NSString*)cla {
    // Do something with the message.
}
-(void) didReceiveTouchPlayMessageFor:(NSString*)device X:(NSNumber*)x Y:(NSNumber*)y vel:(NSNumber*)vel {
    [self processPlaybackTouchWithX:x Y:y Vel:vel];
}

#pragma mark Experiment Mode Methods

-(void)startExperimentMode {
    NSLog(@"Entering Experiment Mode:");
}

-(void)stopExperimentMode {
    NSLog(@"Entering Normal Mode: Configuring UI Elements...");
    [self.compositionStepper setHidden:NO];
    [self.settingsButton setHidden:NO];
    [self.experimentNewSetupButton setHidden:YES];
    [self updateUITextLabels];
    [self updateBowlViewColourScheme];
}

#pragma mark In App Settings Kit Methods
- (IASKAppSettingsViewController*)appSettingsViewController {
    if (!_appSettingsViewController) {
        _appSettingsViewController = [[IASKAppSettingsViewController alloc] init];
        _appSettingsViewController.delegate = self;
        BOOL enabled = [[NSUserDefaults standardUserDefaults] boolForKey:@"AutoConnect"];
        _appSettingsViewController.hiddenKeys = enabled ? nil : [NSSet setWithObjects:@"AutoConnectLogin", @"AutoConnectPassword", nil];
    }
    return _appSettingsViewController;
}

- (IBAction)showSettingsModal:(id)sender {
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
        [self showSettingsPopover:sender];
    } else {
            UINavigationController *aNavController = [[UINavigationController alloc] initWithRootViewController:self.appSettingsViewController];
            [self.appSettingsViewController setShowCreditsFooter:NO];
            [self.appSettingsViewController setShowDoneButton:YES];
            [self presentViewController:aNavController animated:YES completion:nil];
    }
}

// This is the popover for iPad - should work now.
- (void)showSettingsPopover:(UIButton *)sender {
    if(self.currentPopoverController) {
        [self dismissCurrentPopover];
        return;
    }
    [self.appSettingsViewController setShowCreditsFooter:NO];
    [self.appSettingsViewController setShowDoneButton:NO];
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:self.appSettingsViewController];
    UIPopoverController *popover = [[UIPopoverController alloc] initWithContentViewController:navController];
    popover.delegate = self;
    [popover presentPopoverFromRect:sender.bounds inView:sender permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    self.currentPopoverController = popover;
}

// Popover/Settings end methods, previously had settings changes as well!
- (void) dismissCurrentPopover {
//    NSLog(@"VC: dismissing the popover ourselves..");
    [self.currentPopoverController dismissPopoverAnimated:YES];
    self.currentPopoverController = nil;
}

- (void)settingsViewControllerDidEnd:(IASKAppSettingsViewController*)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
//    NSLog(@"VC: Settings Changed, updating everything!");
}

- (void) popoverControllerDidDismissPopover:(UIPopoverController *)popoverController {
//    NSLog(@"VC: Popover going away updating everything!!");
}

- (void) popoverController:(UIPopoverController *)popoverController willRepositionPopoverToRect:(inout CGRect *)rect inView:(inout UIView *__autoreleasing *)view {
//    NSLog(@"VC: repositioning popover");
}

- (BOOL)popoverControllerShouldDismissPopover:(UIPopoverController *)popoverController {
//    NSLog(@"VC: Popover will be dismissed.!!");
    return YES;
}

// AudioBus State Saving Methods
- (NSDictionary *) audiobusStateDictionaryForCurrentState
{
    NSLog(@"VC: Request to save state.");
    return [StateSaver currentState];
}

- (void) loadStateFromAudiobusStateDictionary: (NSDictionary *)dictionary responseMessage:(NSString **) outResponseMessage
{
    NSLog(@"VC: Request to load state.");
    [StateSaver loadState:dictionary];
    *outResponseMessage = @"PhaseRings State Loaded";
}

@end
