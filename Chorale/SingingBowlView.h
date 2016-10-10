//
//  SingingBowlView.h
//  Chorale
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


/*! Starts the swirl animation for a single ring. */
-(void) continuouslyAnimateBowlAtRadius:(CGFloat) radius;
/*! Adjusts the "volume" (opacity) of the currently animated ring.*/
-(void) changeBowlVolumeTo:(CGFloat) level;
/*! Adjusts the speed of the currently animated ring.*/
-(void) changeContinuousAnimationSpeed:(CGFloat) speed;
/*! Stops the continuous ring animation for all rings.*/
-(void) stopAnimatingBowl;
/*! Changes the saturation of the currently animated ring.*/
-(void) changeContinuousColour:(CGFloat) amount forRadius:(CGFloat)radius;

/*! Sets the colour scheme according to the current NSUserDefaults setting.*/
-(void) setSelectedColourScheme;
/*! Sets the colour scheme to the "server connected mode"*/
-(void) setServerColourScheme;

/*! Records whether to display the note values on each ring. */
@property (nonatomic) bool displayNoteNames;


@end
