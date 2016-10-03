//
//  StateSaver.h
//  PhaseRings
//
//  Created by Charles Martin on 3/10/16.
//  Copyright © 2016 Charles Martin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StateSaver : NSObject
+ (NSDictionary *) currentState;
+ (void) loadState:(NSDictionary *)newState;
@end
