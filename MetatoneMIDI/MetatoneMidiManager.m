//
//  MetatoneMidiManager.m
//  SnowMusic
//
//  Created by Charles Martin on 16/10/2014.
//  Copyright (c) 2014 Charles Martin Percussion. All rights reserved.
//

#import "MetatoneMidiManager.h"

@implementation MetatoneMidiManager

- (MetatoneMidiManager *) init {
    self = [super init];
    [self setupMidi];
    return self;
}

- (void) setupMidi {
    self.midi = [[PGMidi alloc] init];
    self.midi.networkEnabled = YES;
}

#pragma mark Midi
-(void) attachToAllExistingSources
{
    for (PGMidiSource *source in self.midi.sources)
    {
        [source addDelegate:self];
    }
}

-(void) setMidi:(PGMidi*)m {
    _midi = m;
    self.midi.delegate = self;
    [self attachToAllExistingSources];
    NSLog(@"MIDI: Setting up.");
}

-(void) midi:(PGMidi*)midi sourceAdded:(PGMidiSource *)source {
    [source addDelegate:self];
    NSLog(@"Midi Source Added: %@", source.name);
}

-(void) midi:(PGMidi*)midi sourceRemoved:(PGMidiSource *)source {
    NSLog(@"Midi Source Removed: %@", source.name);
}

-(void) midi:(PGMidi*)midi destinationAdded:(PGMidiDestination *)destination{
    NSLog(@"Midi Destination Added: %@", destination.name);
}

-(void) midi:(PGMidi*)midi destinationRemoved:(PGMidiDestination *)destination {
    NSLog(@"Midi Destination Removed: %@", destination.name);
}

-(void) midiSource:(PGMidiSource *)input midiReceived:(const MIDIPacketList *)packetList
{
    const MIDIPacket *packet = &packetList->packet[0];
    for (int i = 0; i < packetList->numPackets; ++i) {
        if ((packet->length == 3) && [[NSUserDefaults standardUserDefaults] boolForKey:@"midi_in"]) {
            const UInt8 status = packet->data[0] & 0xf0;
            if (status == 0x90 && packet->data[2] != 0 && self.noteOnHandler) {
                self.noteOnHandler(packet->data[1], packet->data[2]);
            } else if (status == 0xb0 && packet->data[1] == 64 && self.sustainHandler) {
                self.sustainHandler(packet->data[2] >= 64);   // CC64 sustain pedal
            }
        }
        packet = MIDIPacketNext(packet);
    }
}
@end

