//
//  SingingBowlView.m
//  Chorale
//
//  Created by Charles Martin on 22/01/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#import "SingingBowlView.h"
#import "ScaleMaker.h"

#define ROOTTWO 1.41421356237
#define DISPLAYNOTENAME true

@interface SingingBowlView()
@property (strong,nonatomic) CALayer *rimSubLayer;
@property (strong,nonatomic) NSMutableDictionary *continuousEdgeLayers;
@property (strong,nonatomic) NSMutableDictionary *tapEdgeLayers;
@property (weak,nonatomic) SingingBowlSetup* currentSetup;
@property (nonatomic) CGFloat currentRimWidth;
@end

@implementation SingingBowlView

- (id)initWithCoder:(NSCoder *)aDecoder
{
    self = [super initWithCoder:aDecoder];
    if (self) {
        // Initialization code
        self.backgroundColor = [UIColor clearColor];

        self.rimColour = [UIColor blackColor];
        self.textColour = [UIColor blackColor];
        self.tapColour = [UIColor blueColor];
        self.swirlColour = [UIColor greenColor];
        self.rimSubLayer = [[CALayer alloc] init];
        [self.layer addSublayer:self.rimSubLayer];
        self.multipleTouchEnabled = YES;
        self.displayNoteNames = DISPLAYNOTENAME;
//        self.totalRadius = [self viewRadius];
    }
    return self;
}

-(void) drawSetup:(SingingBowlSetup *) setup
{
    // delete previous setup
    [self.rimSubLayer setSublayers:nil];
    self.continuousEdgeLayers = [NSMutableDictionary dictionary];
    self.tapEdgeLayers = [NSMutableDictionary dictionary];
    self.currentSetup = setup;

    // draw new one
    CGFloat totalRadius = [self viewRadius];
    self.currentRimWidth = totalRadius / (CGFloat) [setup numberOfPitches];
    //CGFloat tapEdgeWidth = 0.0;
    
    for (int i = 0; i < [setup numberOfPitches]; i++) {
        // draw the rim.
        CGFloat rimradius = i * self.currentRimWidth;
        int noteNumber = [setup pitchAtIndex:i];
        NSString *note = [SingingBowlSetup noteNameForMidiNumber:noteNumber];
        [self drawBowlRimAtRadius:rimradius withNote:note];
        
        // setup for rim layers:
        CGFloat rimCenter = (i + 0.5) * self.currentRimWidth;
        
        // make continuous rim layer
        CAShapeLayer* continuousLayer = [self makeBowlLayerAtRadius:rimCenter withColour:[NoteColours colourForNote:noteNumber withSaturation:0.6] ofWidth:self.currentRimWidth];
        [self.continuousEdgeLayers setObject:continuousLayer forKey:[NSNumber numberWithInt:noteNumber]];
        
        // make tap rim layer
        CAShapeLayer* tapLayer = [self makeBowlLayerAtRadius:rimCenter withColour:[NoteColours colourForNote:noteNumber withSaturation:1.0] ofWidth:self.currentRimWidth];
        [self.tapEdgeLayers setObject:tapLayer forKey:[NSNumber numberWithInt:noteNumber]];
    }
}

#pragma mark - Drawing

-(void) drawBowlRimAtRadius:(CGFloat) radius withNote:(NSString *) note {
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    shapeLayer.path = [[self makeCircleAtLocation:self.center radius:radius] CGPath];
    shapeLayer.strokeColor = [self.rimColour CGColor];
    shapeLayer.fillColor = nil;
    shapeLayer.lineWidth = 3.0;
    
    [self.rimSubLayer addSublayer:shapeLayer];
    [self.rimLayers addObject:shapeLayer];
    
    if (self.displayNoteNames) {
        //        NSLog(@"DRAWING SETUP: Note names, current radius: %f",radius);
        CATextLayer *noteTextLayer = [CATextLayer layer];
        [noteTextLayer setForegroundColor:[self.textColour CGColor]];
        noteTextLayer.string = note;
        [noteTextLayer setFont:@"HelveticaNeue"];
        noteTextLayer.fontSize = 20.f;
        noteTextLayer.alignmentMode = kCAAlignmentCenter;
        noteTextLayer.contentsScale = [[UIScreen mainScreen] scale];
        [noteTextLayer setBounds:CGRectMake(0.0f, 0.0f, 25.0f, 25.0f)];
        
        // Positioning.
        CGFloat alpha = self.center.y / self.center.x;
        CGFloat beta = 1.0f / sqrt(1.0f + (alpha * alpha));
        CGFloat dX = (radius + 0.5 * self.currentRimWidth) * beta;
        CGFloat dY = alpha * dX;
        
        if (radius == 0.0) {
            // centre ring
            [noteTextLayer setPosition:CGPointMake(floorf(self.center.x),floorf(self.center.y))];
        } else {
            [noteTextLayer setPosition:CGPointMake(floorf(self.center.x + dX),floorf(self.center.y + dY))];
        }
        
        [self.rimSubLayer addSublayer:noteTextLayer];
        [self.rimLayers addObject:noteTextLayer];
    }
}

- (UIBezierPath *)makeCircleAtLocation:(CGPoint)location radius:(CGFloat)radius
{
    UIBezierPath *path = [UIBezierPath bezierPath];
    [path addArcWithCenter:location
                    radius:radius
                startAngle:0.0
                  endAngle:M_PI * 2.0
                 clockwise:YES];
    return path;
}

- (CAShapeLayer*) makeBowlLayerAtRadius:(CGFloat) radius withColour:(UIColor *)colour ofWidth:(CGFloat)width {
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    shapeLayer.path = [[self makeCircleAtLocation:self.center radius:radius] CGPath];
    shapeLayer.strokeColor = [colour CGColor];
    shapeLayer.fillColor = nil;
    shapeLayer.lineWidth = width;
    shapeLayer.hidden = YES;
    [self.rimSubLayer addSublayer:shapeLayer];
    return shapeLayer;
}



-(void) animateBowlAtRadius:(CGFloat)radius {
    CGFloat fracRadius = [self fractionOfTotalRadiusFromRadius:radius];
    int note = [self.currentSetup pitchAtRadius:fracRadius];
    CAShapeLayer *layer = [self.tapEdgeLayers objectForKey:
                           [NSNumber numberWithInt:note]];
    [CATransaction setAnimationDuration:2.0];
    layer.hidden = NO;
    [CATransaction setCompletionBlock:^{
        [CATransaction setAnimationDuration:1.0];
        layer.hidden = YES;
        [CATransaction setCompletionBlock:^{
            [CATransaction setAnimationDuration:3.0];
        }];
    }];
}

-(void) continuouslyAnimateBowlAtRadius:(CGFloat) radius{
    CAShapeLayer *layer = [self.continuousEdgeLayers objectForKey:
                           [NSNumber numberWithInt:[self.currentSetup pitchAtRadius:
                            [self fractionOfTotalRadiusFromRadius:radius]]]];
    CGFloat width = layer.lineWidth;
    layer.hidden = NO;
    
    CABasicAnimation *pulse = [CABasicAnimation animationWithKeyPath:@"lineWidth"];
    pulse.fromValue = [NSNumber numberWithDouble:width * 0.90];
    pulse.toValue = [NSNumber numberWithDouble:width * 1.10];
    pulse.duration = 0.15;
    pulse.autoreverses = YES;
    pulse.repeatCount = HUGE_VALF;
    
    [layer addAnimation:pulse forKey:@"pulseAnimation"];
}



-(void) stopAnimatingBowl {
    for (CALayer *n in [self.continuousEdgeLayers objectEnumerator]) {
        n.hidden = YES;
    }
}

-(void) changeBowlVolumeTo:(CGFloat) level {
    for (CALayer *n in [self.continuousEdgeLayers objectEnumerator]) {
        n.opacity = level;
    }
}

-(void) changeContinuousAnimationSpeed:(CGFloat) speed {
    CGFloat newSpeed = speed;
    //if (speed > 1) newSpeed = 1;
    if (speed < 0) newSpeed = 0;
    for (CALayer *layer in [self.continuousEdgeLayers objectEnumerator]) {
        layer.timeOffset = [layer convertTime:CACurrentMediaTime() fromLayer:nil];
        layer.beginTime = CACurrentMediaTime();
        layer.speed = newSpeed;
    }
}

-(void) changeContinuousColour:(CGFloat) amount forRadius:(CGFloat)radius {
    CGFloat newSaturation = 0.6 + (amount * 0.1);
    int noteNumber = [self.currentSetup pitchAtRadius: [self fractionOfTotalRadiusFromRadius:radius]];
    CAShapeLayer *layer = [self.continuousEdgeLayers objectForKey: [NSNumber numberWithInt:noteNumber]];
    layer.strokeColor = [[NoteColours colourFornote:noteNumber withSaturation:newSaturation andBend:amount] CGColor];
}

#pragma mark - Touch
-(void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [super touchesBegan:touches withEvent:event];
    for (UITouch * touch in [touches objectEnumerator]) {
        [self animateBowlAtRadius:[self calculateDistanceFromCenter:[touch locationInView:self]]];
    }
}

#pragma mark - Util
-(CGFloat)calculateDistanceFromCenter:(CGPoint)touchPoint {
    CGFloat xDist = (touchPoint.x - self.center.x);
    CGFloat yDist = (touchPoint.y - self.center.y);
    return sqrt((xDist * xDist) + (yDist * yDist));
}

-(CGFloat) viewRadius {
    return sqrt((self.center.x * self.center.x)+(self.center.y * self.center.y));
}

-(CGFloat)fractionOfTotalRadiusFromRadius:(CGFloat)radius {
    return radius / [self viewRadius];
}

#pragma mark - Observing Changes
-(void)didMoveToWindow {
    NSLog(@"Did Move to Window! Something Happened!");
}

-(void)didMoveToSuperview {
    NSLog(@"Did Move to Superview!");
}

-(void)didChange:(NSKeyValueChange)changeKind valuesAtIndexes:(NSIndexSet *)indexes forKey:(NSString *)key {
    NSLog(@"View DID change!");
}

@end
