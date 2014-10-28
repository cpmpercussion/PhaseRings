//
//  AppDelegate.m
//  Chorale
//
//  Created by Charles Martin on 20/01/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Register defaults
    NSDictionary *defaults = @{@"sound":@1,
                               @"note_labels":@YES,
                               @"note_1":@1,
                               @"note_2":@3,
                               @"note_3":@4,
                               @"scale_1":@3,
                               @"scale_2":@8,
                               @"scale_3":@9};
    
    [[NSUserDefaults standardUserDefaults] registerDefaults:defaults];
    
    // Override point for customization after application launch.
    application.idleTimerDisabled = YES;
    self.viewController = (ViewController*) self.window.rootViewController;
    
    
    
    // NSNotification for NSUserDefaults.
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(defaultsDidChange:) name:NSUserDefaultsDidChangeNotification
                                               object:nil];
    return YES;
}

- (void)defaultsDidChange:(NSNotification *)aNotification
{
    NSLog(@"SETTINGS NOTIFICATION: Something Changed: %@",aNotification);
    [self.viewController openComposition];
}

							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    NSLog(@"Application will enter foreground - checking to see if patch needs to be reopened...");
    [self.viewController openPdPatch];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    NSLog(@"Application did become active.");
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
