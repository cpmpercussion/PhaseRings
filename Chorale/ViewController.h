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

@property (nonatomic) int currentPerformanceType;
@property (nonatomic) bool experimentMode;
@property (nonatomic) bool buttonFadingMode;
@property (nonatomic) bool listenToMetatoneClassifierMessages;

/*! The "New Setup" button as used in PhaseRings HCI experiments. */
@property (weak, nonatomic) IBOutlet UIButton *experimentNewSetupButton;
/*! Method called when the "New Setup" button is called in PhaseRings HCI experiments. */
- (IBAction)experimentNewSetupButtonPressed:(UIButton *)sender;

/*! 
 @brief Opens the correct Pd patch for the currently selected sound scheme.
 This method does nothing if the same Pd patch is opened twice. 
 */
- (void) openPdPatch;
/*! 
 @brief Generates a composition object according the the selected settings then draws a new bowlView for the new  setups.
 This method is destructive in that it generates all new setups so only be called when absolutely necessary.
 */
- (void) openComposition;
/*! @brief Updates the setup description label and note name labels in the UI according to the selected settings. */
-(void) updateUITextLabels;
/*! @brief Updates the colour scheme according to the selected settings. */
- (void) updateBowlViewColourScheme;
/*! @brief Updates the connections to OSC and Web Classifiers according to the selected settings. This is a disruptive method as it can
 trash the current setup. */
- (void) updateClassifierConnections;

- (IBAction)showSettingsModal:(id)sender;

- (void) shutdownSoundProcessing;
- (void) restartSoundProcessing;

- (void) setupOSCLogging;
- (void) stopOSCLogging;
@end
