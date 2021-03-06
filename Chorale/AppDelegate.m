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
#define AUDIOBUS_SOURCE_URL @"us.audiob.Audiobus"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    // Handle preset incoming from loading url.
    if ([((NSString *) [options valueForKey:@"UIApplicationOpenURLOptionsSourceApplicationKey"]) isEqualToString:AUDIOBUS_SOURCE_URL]) {
        NSLog(@"URL_LOADER: Opened by Audiobus, ready to load settings");
        return YES;
    }
    return NO;
}

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

/*! Method to update non-disruptive features which runs after any settings update. */
- (void)defaultsDidChange:(NSNotification *)aNotification
{
    NSLog(@"AD: defaultsDidChange, updating all non-disruptive features.");
    [self.viewController openPdPatch];
    [self.viewController updateBowlViewColourScheme];
    [self.viewController updateUITextLabels];
}

/*! Method to update the disruptive features only when needed, i.e., composition setup and classifier connection */
- (void)observeValueForKeyPath:(NSString *)aKeyPath ofObject:(id)anObject
                       change:(NSDictionary *)aChange context:(void *)aContext
{
    NSLog(@"AD: Value Changed for Keypath: %@",aKeyPath);
    bool compositionChanged = NO;
    if ([aKeyPath isEqualToString:@"composition"]) {
        compositionChanged = YES;
    } else if ([aKeyPath isEqualToString:@"web_classifier"]) {
        // trigger change to webclassifier connection
        NSLog(@"AD: Updating classifier connection due to change in Web Classifier");
        [self.viewController updateClassifierConnections];
    } else if ([aKeyPath isEqualToString:@"local_classifier"]) {
        // trigger change to localclassifier connection.
        NSLog(@"AD: Updating classifier connection due to change in Local Classifier");
        [self.viewController updateClassifierConnections];
    }
    
    if ([CUSTOM_COMPOSITION_PROPERTIES containsObject:aKeyPath] &&
        ([[NSUserDefaults standardUserDefaults] integerForKey:@"composition"] == CUSTOM_COMPOSITION_NUMBER)) {
        compositionChanged = YES;
        NSLog(@"APP DELEGATE: Changing scale/note while Custom is open");
    }
    
    if (compositionChanged) {
        NSLog(@"AD: Composition settings were changed, updating composition.");
        [self.viewController openComposition];
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

@end
