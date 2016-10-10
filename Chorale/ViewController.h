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
#import "ABAudiobusController.h"
#import "StateSaver.h"
// Settings:
#import "IASKAppSettingsViewController.h"
#import "IASKSettingsReader.h"

@interface ViewController : UIViewController <PdReceiverDelegate,MetatoneNetworkManagerDelegate,IASKSettingsDelegate,UIPopoverControllerDelegate,ABAudiobusControllerStateIODelegate>
@property (strong, nonatomic) MetatoneMidiManager* midiManager;
@property (strong, nonatomic) IASKAppSettingsViewController *appSettingsViewController;
@property (weak, nonatomic) UIPopoverController* currentPopoverController;
@property (strong, nonatomic) ABAudiobusController *audiobusController;
@property (strong, nonatomic) ABSenderPort *senderport;

@property (nonatomic) bool webClassifierSearchEnabled;
@property (nonatomic) bool localClassifierSearchEnabled;
@property (nonatomic) bool displayClassifierInfo;

@property (nonatomic) int currentPerformanceType;
@property (nonatomic) bool experimentMode;
@property (nonatomic) bool buttonFadingMode;
@property (nonatomic) bool listenToMetatoneClassifierMessages;
@property (nonatomic) bool serverConnected;


@property (weak, nonatomic) IBOutlet UIButton *experimentNewSetupButton;
- (IBAction)experimentNewSetupButtonPressed:(UIButton *)sender;
/*! @brief Opens the correct Pd patch for the currently selected sound scheme. */
- (void) openPdPatch;
/*! @brief Generates a composition object according the the selected settings then draws a new bowlView for the new  setups.*/
- (void) openComposition;

- (void) updateClassifierSettings;
- (IBAction)showSettingsModal:(id)sender;
- (void) shutdownSoundProcessing;
- (void) restartSoundProcessing;
- (void) updateBowlViewColourScheme;
- (void) setupOSCLogging;
- (void) stopOSCLogging;
@end
