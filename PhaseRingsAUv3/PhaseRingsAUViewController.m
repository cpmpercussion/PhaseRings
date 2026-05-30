//
//  PhaseRingsAUViewController.m
//  PhaseRingsAUv3
//
//  See PhaseRingsAUViewController.h and auv3-plan.md (Phase E).
//

#import "PhaseRingsAUViewController.h"
#import <PhaseRingsKit/PhaseRingsKit.h>

@interface PhaseRingsAUViewController ()
@property (nonatomic, strong) PhaseRingsAudioUnit *audioUnit;
@property (nonatomic, strong) InstrumentViewController *instrument;
@end

@implementation PhaseRingsAUViewController

- (void)loadView {
    self.view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 1024, 1024)];
    self.view.backgroundColor = [UIColor blackColor];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.preferredContentSize = CGSizeMake(1024, 1024);
    [self embedInstrument];
}

- (void)embedInstrument {
    if (self.instrument) return;

    InstrumentViewController *instrument = [[InstrumentViewController alloc] init];
    __weak PhaseRingsAUViewController *weakSelf = self;
    instrument.coreProvider = ^HeavyCore * _Nullable {
        return weakSelf.audioUnit.core;
    };
    self.instrument = instrument;

    [self addChildViewController:instrument];
    instrument.view.frame = self.view.bounds;
    instrument.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:instrument.view];
    [instrument didMoveToParentViewController:self];
}

#pragma mark - AUAudioUnitFactory

- (AUAudioUnit *)createAudioUnitWithComponentDescription:(AudioComponentDescription)desc
                                                   error:(NSError **)error {
    self.audioUnit = [[PhaseRingsAudioUnit alloc] initWithComponentDescription:desc
                                                                       options:0
                                                                         error:error];
    return self.audioUnit;
}

@end
