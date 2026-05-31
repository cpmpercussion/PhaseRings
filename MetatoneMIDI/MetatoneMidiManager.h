//
//  MetatoneMidiManager.h
//  SnowMusic
//
//  Created by Charles Martin on 16/10/2014.
//  Copyright (c) 2014 Charles Martin Percussion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PGMidi.h"
#import "PGArc.h"


@interface MetatoneMidiManager : NSObject <PGMidiDelegate, PGMidiSourceDelegate>

@property (strong, nonatomic) PGMidi *midi;
/// Invoked on the MIDI thread when a note-on (status 0x90, non-zero velocity)
/// arrives, gated by the `midi_in` user default. Channel is fixed at 1 to
/// match the prior libpd routing.
@property (copy, nonatomic) void (^noteOnHandler)(int pitch, int velocity);

-(void) setupMidi;

@end
