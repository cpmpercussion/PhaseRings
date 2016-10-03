//
//  StateSaver.m
//  PhaseRings
//
//  Created by Charles Martin on 3/10/16.
//  Copyright © 2016 Charles Martin. All rights reserved.
//

#import "StateSaver.h"

@implementation StateSaver

+ (NSDictionary *) currentState
{
    NSLog(@"STATE_SAVER: Packing up state to save.");
    // Register defaults
    
    NSDictionary *currentState = @{
                           @"sound":[[NSUserDefaults standardUserDefaults] objectForKey:@"sound"],
                           @"note_labels":[[NSUserDefaults standardUserDefaults] objectForKey:@"note_labels"],
                           @"setup_label":[[NSUserDefaults standardUserDefaults] objectForKey:@"setup_label"],
                           @"composition":[[NSUserDefaults standardUserDefaults] objectForKey:@"composition"],
                           @"note_1":[[NSUserDefaults standardUserDefaults] objectForKey:@"note_1"],
                           @"note_2":[[NSUserDefaults standardUserDefaults] objectForKey:@"note_2"],
                           @"note_3":[[NSUserDefaults standardUserDefaults] objectForKey:@"note_3"],
                           @"scale_1":[[NSUserDefaults standardUserDefaults] objectForKey:@"scale_1"],
                           @"scale_2":[[NSUserDefaults standardUserDefaults] objectForKey:@"scale_2"],
                           @"scale_3":[[NSUserDefaults standardUserDefaults] objectForKey:@"scale_3"],
                           @"midi_in":[[NSUserDefaults standardUserDefaults] objectForKey:@"midi_in"],
                           @"midi_out":[[NSUserDefaults standardUserDefaults] objectForKey:@"midi_out"],
                           @"process_effects":[[NSUserDefaults standardUserDefaults] objectForKey:@"process_effects"],
                           @"reverb_volume":[[NSUserDefaults standardUserDefaults] objectForKey:@"reverb_volume"],
                           @"master_volume":[[NSUserDefaults standardUserDefaults] objectForKey:@"master_volume"],
                           @"web_classifier":[[NSUserDefaults standardUserDefaults] objectForKey:@"web_classifier"],
                           @"local_classifier":[[NSUserDefaults standardUserDefaults] objectForKey:@"local_classifier"],
                           @"display_classifier_information":[[NSUserDefaults standardUserDefaults] objectForKey:@"display_classifier_information"],
                           @"dark_mode":[[NSUserDefaults standardUserDefaults] objectForKey:@"dark_mode"]};
    return currentState;
}

+ (void) loadState:(NSDictionary *)newState
{
    NSLog(@"STATE_SAVER: Loading new state.");
    [[NSUserDefaults standardUserDefaults] setValuesForKeysWithDictionary:newState];
}
@end
