//
//  ViewController.h
//  Chorale
//
//  Created by Charles Martin on 20/01/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PdAudioController.h"
#import "PdBase.h"
#import "PdFile.h"
#import "MetatoneNetworkManager.h"
#import "MetatoneMidiManager.h"
#import "Audiobus.h"


// Settings:
#import "IASKAppSettingsViewController.h"
#import "IASKSettingsReader.h"



@interface ViewController : UIViewController <PdReceiverDelegate,MetatoneNetworkManagerDelegate,IASKSettingsDelegate,UIPopoverControllerDelegate>
@property (strong, nonatomic) MetatoneMidiManager* midiManager;
@property (strong, nonatomic) IASKAppSettingsViewController *appSettingsViewController;
@property (weak, nonatomic) UIPopoverController* currentPopoverController;
@property (strong, nonatomic) ABAudiobusController *audiobusController;
@property (strong, nonatomic) ABSenderPort *senderport;


- (void) openPdPatch;
- (void) openComposition;
- (IBAction)showSettingsModal:(id)sender;
- (void) shutdownSoundProcessing;
- (void) restartSoundProcessing;

-(void) setupOSCLogging;
-(void) stopOSCLogging;
@end
