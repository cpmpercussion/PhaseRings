//
//  AppDelegate.m
//  Chorale
//
//  Created by Charles Martin on 20/01/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#import "AppDelegate.h"

#define CUSTOM_COMPOSITION_PROPERTIES @[@"note_1",@"note_2",@"note_3",@"scale_1",@"scale_2",@"scale_3"]
#define CUSTOM_COMPOSITION_NUMBER 0

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Register defaults
    NSDictionary *defaults = @{@"sound":@2,
                               @"note_labels":@YES,
                               @"setup_label":@YES,
                               @"dark_mode":@NO,
                               @"composition":@1,
                               @"note_1":@1,
                               @"note_2":@3,
                               @"note_3":@4,
                               @"scale_1":@3,
                               @"scale_2":@8,
                               @"scale_3":@9,
                               @"midi_in":@YES,
                               @"midi_out":@YES,
                               @"process_effects":@YES,
                               @"reverb_volume":@0.5,
                               @"master_volume":@1.0,
                               @"web_classifier":@NO,
                               @"local_classifier":@YES,
                               @"display_classifier_information":@NO};
    
    [[NSUserDefaults standardUserDefaults] registerDefaults:defaults];
    
    // Override point for customization after application launch.
    application.idleTimerDisabled = YES;
    self.viewController = (ViewController*) self.window.rootViewController;
    
    // NSNotification for NSUserDefaults.
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(defaultsDidChange:) name:NSUserDefaultsDidChangeNotification
                                               object:nil];
    
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"composition"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"note_1"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"note_2"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"note_3"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"scale_1"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"scale_2"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"scale_3"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"web_classifier"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    [[NSUserDefaults standardUserDefaults] addObserver:self
                                            forKeyPath:@"local_classifier"
                                               options:NSKeyValueObservingOptionNew
                                               context:NULL];
    return YES;
}

- (void)defaultsDidChange:(NSNotification *)aNotification
{
    NSLog(@"SETTINGS NOTIFICATION: Settings changed.");
    [self.viewController openPdPatch];
    [self.viewController updateClassifierSettings];
}

-(void)observeValueForKeyPath:(NSString *)aKeyPath ofObject:(id)anObject
                       change:(NSDictionary *)aChange context:(void *)aContext
{
    NSLog(@"APP DELEGATE: Value Changed for Keypath: %@",aKeyPath);
    bool compositionChanged = NO;
    if ([aKeyPath isEqualToString:@"composition"]) {
        compositionChanged = YES;
        NSLog(@"APP DELEGATE: Changed Composition");
    } else if ([aKeyPath isEqualToString:@"web_classifier"]) {
        // trigger change to webclassifier connection
# pragma mark TODO - make sure that webclassifier gets turned on and off here!
    } else if ([aKeyPath isEqualToString:@"local_classifier"]) {
        // trigger change to localclassifier connection.
    }
    
    if ([CUSTOM_COMPOSITION_PROPERTIES containsObject:aKeyPath] &&
        ([[NSUserDefaults standardUserDefaults] integerForKey:@"composition"] == CUSTOM_COMPOSITION_NUMBER)) {
        compositionChanged = YES;
        NSLog(@"APP DELEGATE: Changing scale/note while Custom is open");
    }
    
    if (compositionChanged) {
        [self.viewController openComposition];
    } else {
        NSLog(@"APP DELEGATE: settings change not for composition.");
    }
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    if (!self.viewController.audiobusController.connected &&
        !self.viewController.audiobusController.audiobusAppRunning) {
        [self.viewController shutdownSoundProcessing];
    }
//    [self.viewController stopOSCLogging];
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    
    [[UIApplication sharedApplication] setIdleTimerDisabled:NO];

//    if ( !self.viewController.audiobusController.connected && !self.viewController.audiobusController.memberOfActiveAudiobusSession ) {
//        // Fade out and stop the audio engine, suspending the app, if we're not connected, and we're not part of an active Audiobus session
//        [ABAudioUnitFader fadeOutAudioUnit:self.viewController.audioController.audioUnit completionBlock:^{ [_audioEngine stop]; }];
//    }
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
//    NSLog(@"Application will enter foreground - checking to see if patch needs to be reopened...");
    [self.viewController openPdPatch];
//    [self.viewController setupOSCLogging];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
//    NSLog(@"Application did become active.");
    [self.viewController restartSoundProcessing];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    [[NSUserDefaults standardUserDefaults] synchronize];
    [self.viewController stopOSCLogging];
}


// AudioBus State Saving Methods
- (NSDictionary *) audiobusStateDictionaryForCurrentState
{
    return [StateSaver currentState];
}

- (void) loadStateFromAudiobusStateDictionary: (NSDictionary *)dictionary responseMessage:(NSString **) outResponseMessage
{
    [StateSaver loadState:dictionary];
    *outResponseMessage = @"State Loaded!";
}
@end
