//
//  SingingBowlView.h
//  PhaseRings
//
//  Created by Charles Martin on 22/01/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SingingBowlSetup.h"
#import "NoteColours.h"



@interface SingingBowlView : UIView

/*! Draws a new ring setup on the screen. */
-(void) drawSetup:(SingingBowlSetup *) setup;


/*! Starts the tap animation for a single ring. */
-(void) animateBowlAtRadius:(CGFloat)radius;
/*! Starts the tap animation for the ring carrying a given MIDI note number.
    No-op if the note is not present in the current setup. Used to light rings
    from incoming MIDI (issue #29); the radius variant resolves to this. */
-(void) animateBowlForNote:(int)note;
/*! Starts the swirl animation for a single ring. */
-(void) continuouslyAnimateBowlAtRadius:(CGFloat) radius;
/*! Starts the pulsing (held) animation for the ring carrying a given MIDI note
    number, made visible directly (no volume gesture drives it). Used for
    sustain-pedal held notes from incoming MIDI (issue #29). No-op if the note
    is not present in the current setup. */
-(void) continuouslyAnimateBowlForNote:(int)note;
/*! Stops the pulsing animation for a single ring by MIDI note number, fading it
    out. Counterpart to continuouslyAnimateBowlForNote:. */
-(void) stopContinuousAnimationForNote:(int)note;
/*! Adjusts the "volume" (opacity) of the currently animated ring.*/
-(void) changeBowlVolumeTo:(CGFloat) level;
/*! Adjusts the speed of the currently animated ring.*/
-(void) changeContinuousAnimationSpeed:(CGFloat) speed;
/*! Stops the continuous ring animation for all rings.*/
-(void) stopAnimatingBowl;
/*! Changes the saturation of the currently animated ring.*/
-(void) changeContinuousColour:(CGFloat) amount forRadius:(CGFloat)radius;

/*! Sets the colour scheme by reading the current trait collection's userInterfaceStyle. */
-(void) setSelectedColourScheme;

/*! Lights every other ring in the current setup at full saturation for App Store screenshots. */
-(void) lightAlternateRingsForScreenshot;

/*! Calculates the distance of a CGPoint from the centre of the SingingBowlView */
-(CGFloat)calculateDistanceFromCenter:(CGPoint)touchPoint;


/*! Records whether to display the note values on each ring. */
@property (nonatomic) bool displayNoteNames;


@end
