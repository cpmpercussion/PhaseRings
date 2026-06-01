//
//  ViewController.h
//  PhaseRings
//
//  Created by Charles Martin on 20/01/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//
//  The standalone app's shell. It hosts the shared PhaseRingsKit
//  InstrumentViewController as the playable surface and adds the app-only
//  subsystems around it: OSC ensemble networking, Core MIDI out, and the
//  ensemble overlay. The instrument surface, settings UI and ring/touch logic
//  all live in PhaseRingsKit and are shared with the AUv3 extension.
//

#import <UIKit/UIKit.h>
#import "MetatoneNetworkManager.h"
#import "MetatoneMidiManager.h"

@interface ViewController : UIViewController <MetatoneNetworkManagerDelegate>
@property (strong, nonatomic) MetatoneMidiManager* midiManager;
@property (nonatomic) bool listenToMetatoneClassifierMessages;

/*! Pushes the current sound scheme + volumes (from settings) to the engine. */
- (void) openPdPatch;

- (void) shutdownSoundProcessing;
- (void) restartSoundProcessing;

- (void) setupOSCLogging;
- (void) stopOSCLogging;
@end
