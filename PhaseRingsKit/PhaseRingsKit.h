//
//  PhaseRingsKit.h
//  PhaseRingsKit
//
//  Umbrella header for the shared framework that holds the host-agnostic
//  Heavy DSP core. Linked by both the standalone app and (later) the AUv3
//  extension. See auv3-plan.md.
//

#import <Foundation/Foundation.h>

//! Project version number for PhaseRingsKit.
FOUNDATION_EXPORT double PhaseRingsKitVersionNumber;

//! Project version string for PhaseRingsKit.
FOUNDATION_EXPORT const unsigned char PhaseRingsKitVersionString[];

#import <PhaseRingsKit/HeavyCore.h>
#import <PhaseRingsKit/PhaseRingsAudioUnit.h>
#import <PhaseRingsKit/InstrumentViewController.h>
#import <PhaseRingsKit/PRSettings.h>
#import <PhaseRingsKit/PRSettingsStore.h>
#import <PhaseRingsKit/PRSettingsObserverSet.h>
#import <PhaseRingsKit/PRMemoryStore.h>
#import <PhaseRingsKit/PRAudioUnitStore.h>
#import <PhaseRingsKit/PRCompositionFactory.h>
