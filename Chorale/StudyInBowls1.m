//
//  StudyInBowls1.m
//  SingingBowls
//
//  Created by Charles Martin on 7/03/2014.
//  Copyright (c) 2014 Charles Martin. All rights reserved.
//

#import "StudyInBowls1.h"

@implementation StudyInBowls1

- (StudyInBowls1 *) init {
    self = [super init];
    self.looping = YES;
    self.contents = @[
      @[@34, @48, @70],
      @[@34, @48, @54, @64, @70],
      @[@34, @36, @38, @52, @55, @57, @62, @70],
      @[@34, @36, @38, @48, @54, @55, @57, @58, @60, @62, @70],
      @[@36, @38, @56, @65],
      @[@36, @38, @55, @56, @60, @65],
      @[@36, @38, @40, @55, @56, @58, @60, @64, @65],
      @[@36, @38, @40, @53, @55, @56, @58, @60, @62, @64, @65],
      @[@37, @39, @55, @69],
      @[@37, @39, @40, @55, @67, @69],
      @[@37, @39, @40, @45, @52, @54, @55, @67, @69],
      @[@37, @39, @40, @45, @52, @54, @55, @48, @66, @67, @69],
      @[@41, @55, @69, @75],
      @[@41, @53, @55, @69, @75],
      @[@41, @43, @53, @55, @65, @69, @75],
      @[@41, @43, @45, @47, @53, @55, @57, @61, @65, @69, @75]];
    return self;
}

//- (StudyInBowls1 *) init {
//    self = [super init];
//    self.looping = YES;
//    self.contents = @[
//                      @[@34, @36, @58],
//                      @[@34, @36, @42, @52, @58],
//                      @[@34, @36, @38, @40, @43, @45, @50, @58],
//                      @[@34, @36, @38, @40, @42, @43, @45, @46, @48, @50, @58],
//                      @[@36, @38, @44, @53],
//                      @[@36, @38, @40, @44, @48, @53],
//                      @[@36, @38, @40, @43, @44, @46, @48, @52, @53],
//                      @[@36, @38, @40, @41, @43, @44, @46, @48, @50, @52, @53],
//                      @[@37, @39, @46, @52],
//                      @[@37, @39, @40, @46, @51, @52],
//                      @[@37, @39, @40, @42, @43, @45, @46, @51, @52],
//                      @[@37, @39, @40, @42, @43, @45, @46, @48, @49, @51, @52],
//                      @[@41, @51, @59, @61],
//                      @[@41, @49, @51, @59, @61],
//                      @[@41, @43, @49, @51, @57, @59, @61],
//                      @[@41, @43, @45, @47, @49, @51, @53, @55, @57, @59, @61]];
//    return self;
//}
@end
