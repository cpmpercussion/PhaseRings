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
#import <PhaseRingsKit/PRSettingsStore.h>

NS_ASSUME_NONNULL_BEGIN

@class InstrumentViewController;

/// Observes raw local input on the shared surface so an app host can mirror it
/// onto its app-only subsystems (OSC ensemble broadcast). MIDI-out is NOT here
/// — it is emitted directly by the controller through `midiOutSink` so the
/// plugin gets it too. Fired from the UIResponder touch phases, matching where
/// the standalone app historically broadcast OSC. The resolved `pitch` is
/// provided so the host needn't recompute geometry.
@protocol InstrumentViewControllerDelegate <NSObject>
@optional
- (void)instrument:(InstrumentViewController *)vc touchBeganAtPoint:(CGPoint)point pitch:(int)pitch velocity:(int)velocity;
- (void)instrument:(InstrumentViewController *)vc touchMovedToPoint:(CGPoint)point velocity:(CGFloat)pixelVelocity;
- (void)instrumentTouchEnded:(InstrumentViewController *)vc;
@end

@interface InstrumentViewController : UIViewController

/// Backing store for the instrument's settings (composition, notes/scales,
/// sound, labels). Drives the ring layout and the shared settings screen. Hosts
/// may inject their own (app → NSUserDefaults, AUv3 → fullState in F.4); if left
/// unset, a session-only in-memory store is created on first access.
@property (nonatomic, strong, null_resettable) id<PRSettingsStore> settingsStore;

/// Supplies the live event sink to send events to, or nil when audio isn't
/// running. Pulled on demand so it tolerates the AU allocating its core
/// lazily. The host sets this: the AUv3 returns its `HeavyCore`, the
/// standalone app its `HeavyAudioEngine` — both conform to `HeavyEventSink`.
@property (nonatomic, copy, nullable) id<HeavyEventSink> _Nullable (^coreProvider)(void);

/// Called when the user picks a sound scheme (0..6) from the on-screen
/// control bar. The host wires this to the AU's `sound` parameter so the
/// choice is saved with the AU and applied to the core. If unset, the view
/// controller falls back to driving the core directly.
@property (nonatomic, copy, nullable) void (^soundSchemeHandler)(NSInteger scheme);

/// Observes local input for app-only mirroring (OSC). MIDI-out does not go
/// through here — see `midiOutSink`.
@property (nonatomic, weak, nullable) id<InstrumentViewControllerDelegate> delegate;

/// Transport for MIDI-out. The controller maps gestures to MIDI (note-on at
/// tap, note-off, aftertouch from swirl velocity; channel 1) and hands the raw
/// bytes here. Each host routes them to its own MIDI path: the app to CoreMIDI,
/// the AUv3 to the host's `MIDIOutputEventBlock`. Always emitted (no setting).
@property (nonatomic, copy, nullable) void (^midiOutSink)(const uint8_t *bytes, NSUInteger length);

/// When YES, the ring layout is drawn in the lighter alternate scheme used for
/// App Store screenshots and the master volume is muted. Mirrors the app's old
/// `screenshotMode` default; the host sets it before the view lays out.
@property (nonatomic) BOOL screenshotMode;

/// Number of setups in the current composition (for a host driving remote
/// setup changes).
@property (nonatomic, readonly) NSInteger numberOfSetups;

/// The setup index currently shown.
@property (nonatomic, readonly) int currentSetupState;

/// Switch to a given setup index (clamped), updating the stepper + label.
/// Used by the app for ensemble composition-step / new-idea events.
- (void)showSetupState:(int)state;

/// Resolve a point in the surface's coordinate space to a MIDI pitch.
- (int)pitchAtPoint:(CGPoint)point;

/// Remote-OSC playback (ensemble): animate the rings and play audio as if a
/// remote peer were touching. `playbackTapAtPoint:` is a single struck note;
/// `playbackSwirlAtPoint:velocity:` is a continuous gesture that auto-stops 1s
/// after the last call; `stopPlayback` ends it immediately.
- (void)playbackTapAtPoint:(CGPoint)point;
- (void)playbackSwirlAtPoint:(CGPoint)point velocity:(CGFloat)velocity;
- (void)stopPlayback;

/// Reflect the current sound scheme (0..6) in the control bar without firing
/// the handler — e.g. after the host restores AU state.
- (void)setDisplayedSoundScheme:(NSInteger)scheme;

/// Rebuild the ring layout from a default generative composition.
- (void)reloadComposition;

@end

NS_ASSUME_NONNULL_END
