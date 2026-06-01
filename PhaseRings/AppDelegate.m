//
//  AppDelegate.m
//  PhaseRings
//
//  Created by Charles Martin on 20/01/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    return NO;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Register defaults
    NSDictionary *defaults = @{@"sound":@2,
                               @"note_labels":@YES,
                               @"setup_label":@YES,
                               @"composition":@1,
                               @"note_1":@1,
                               @"note_2":@3,
                               @"note_3":@4,
                               @"scale_1":@3,
                               @"scale_2":@8,
                               @"scale_3":@9,
                               @"midi_in":@YES,
                               @"process_effects":@YES,
                               @"reverb_volume":@0.5,
                               @"master_volume":@1.0};

    [[NSUserDefaults standardUserDefaults] registerDefaults:defaults];

    // The Main storyboard was retired in #27; build the window + root view
    // controller programmatically. ViewController hosts the shared instrument
    // surface plus the app-only networking / MIDI / ensemble chrome. Settings
    // changes flow through the shared PRSettingsStore (which drives the surface)
    // and the controller's own engine-level push, so the old NSUserDefaults KVO
    // wiring here is no longer needed.
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    ViewController *viewController = [[ViewController alloc] init];
    self.viewController = viewController;
    self.window.rootViewController = viewController;

    // Screenshot mode: force a UI appearance so light/dark App Store captures
    // are deterministic regardless of the simulator's current setting. The
    // -uiStyle flag lands in NSArgumentDomain.
    NSString *uiStyle = [[NSUserDefaults standardUserDefaults] stringForKey:@"uiStyle"];
    if ([uiStyle isEqualToString:@"light"]) {
        self.window.overrideUserInterfaceStyle = UIUserInterfaceStyleLight;
    } else if ([uiStyle isEqualToString:@"dark"]) {
        self.window.overrideUserInterfaceStyle = UIUserInterfaceStyleDark;
    }

    [self.window makeKeyAndVisible];

    application.idleTimerDisabled = YES;
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    [self.viewController shutdownSoundProcessing];
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    [[UIApplication sharedApplication] setIdleTimerDisabled:NO];
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    [self.viewController openPdPatch];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    [self.viewController restartSoundProcessing];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    [[NSUserDefaults standardUserDefaults] synchronize];
    [self.viewController stopOSCLogging];
}

@end
