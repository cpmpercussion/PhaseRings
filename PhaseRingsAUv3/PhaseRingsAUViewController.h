//
//  PhaseRingsAUViewController.h
//  PhaseRingsAUv3
//
//  Principal class of the AUv3 app extension. As an AUAudioUnitFactory it
//  creates the PhaseRingsAudioUnit; as an AUViewController it hosts the
//  shared InstrumentViewController (the ring UI). See auv3-plan.md (Phase E).
//

#import <CoreAudioKit/CoreAudioKit.h>

@interface PhaseRingsAUViewController : AUViewController <AUAudioUnitFactory>
@end
