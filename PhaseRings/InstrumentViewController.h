//
//  InstrumentViewController.h
//  PhaseRingsKit
//
//  The playable PhaseRings instrument surface: the concentric SingingBowlView
//  rings plus the tap / swirl gestures, decoupled from the standalone app's
//  networking, MIDI-out, settings and storyboard. Hosted by the standalone
//  app and by the AUv3 extension's AUViewController. Sends note / sing events
//  to whatever HeavyCore the host is driving. See auv3-plan.md (Phase F).
//

#import <UIKit/UIKit.h>
#import <PhaseRingsKit/HeavyCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface InstrumentViewController : UIViewController

/// Supplies the live core to send events to, or nil when audio isn't running.
/// Pulled on demand so it tolerates the AU allocating its core lazily. The
/// host (AU view controller / standalone app) sets this.
@property (nonatomic, copy, nullable) HeavyCore * _Nullable (^coreProvider)(void);

/// Called when the user picks a sound scheme (0..6) from the on-screen
/// control bar. The host wires this to the AU's `sound` parameter so the
/// choice is saved with the AU and applied to the core. If unset, the view
/// controller falls back to driving the core directly.
@property (nonatomic, copy, nullable) void (^soundSchemeHandler)(NSInteger scheme);

/// Reflect the current sound scheme (0..6) in the control bar without firing
/// the handler — e.g. after the host restores AU state.
- (void)setDisplayedSoundScheme:(NSInteger)scheme;

/// Rebuild the ring layout from a default generative composition.
- (void)reloadComposition;

@end

NS_ASSUME_NONNULL_END
