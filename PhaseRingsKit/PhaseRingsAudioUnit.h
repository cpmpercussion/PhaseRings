//
//  PhaseRingsAudioUnit.h
//  PhaseRingsKit
//
//  The PhaseRings instrument as an AUv3 audio unit
//  (kAudioUnitType_MusicDevice, 'aumu'). Wraps a HeavyCore: the
//  internalRenderBlock drains the core's control-event FIFO and runs the
//  active Heavy context. Lives in the shared framework so both the
//  standalone app and the AUv3 app extension instantiate the same unit.
//  See auv3-plan.md (Phase C).
//

#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <PhaseRingsKit/HeavyCore.h>

NS_ASSUME_NONNULL_BEGIN

/// Component identity. Kept in one place so the extension Info.plist and the
/// in-process registration agree. Type 'aumu' = music device (instrument).
extern const OSType PhaseRingsAUType;          // 'aumu'
extern const OSType PhaseRingsAUSubType;       // 'phrg'
extern const OSType PhaseRingsAUManufacturer;  // 'CPMa'

@interface PhaseRingsAudioUnit : AUAudioUnit

/// The DSP core driving this unit. nil until render resources are allocated.
/// The host UI routes touch / note events here (same FIFO the render block
/// drains).
@property (nonatomic, readonly, nullable) HeavyCore *core;

/// Non-parameter instrument settings (composition / notes / scales / labels)
/// that aren't expressible in the AU parameter tree but must still round-trip
/// through the host's session save/restore. Keyed by the names PRAudioUnitStore
/// uses; seeded from the instrument defaults at init. Serialised inside
/// `fullState` under `kPhaseRingsInstrumentStateKey`. (Issue #23, Phase F.4.)
@property (atomic, copy) NSDictionary<NSString *, NSNumber *> *instrumentSettingsState;

/// Fired on the main thread after `setFullState:` restores instrument settings,
/// so a PRAudioUnitStore can rebroadcast the restored state to the UI.
@property (nonatomic, copy, nullable) void (^instrumentStateRestoredHandler)(void);

/// Queue a MIDI message for output to the host (via `MIDIOutputEventBlock`).
/// Called from the main thread (the instrument surface's gesture → MIDI
/// mapping); the bytes are drained and emitted on the render thread. The unit
/// advertises a single output port via `MIDIOutputNames`. (Issue #27, B3a.)
- (void)sendMIDIOutBytes:(const uint8_t *)bytes length:(NSUInteger)length;

/// Drain the MIDI messages received from the host since the last call, invoking
/// `handler` once per message with the raw status / data bytes (note-ons and
/// sustain CC; the channel is in the low nibble of `status`). Call from the main
/// thread; the host UI uses it to light rings on incoming MIDI (issue #29). The
/// render thread is the producer, so this is a lock-free consumer with no
/// realtime impact.
- (void)drainIncomingMIDI:(void (^)(uint8_t status, uint8_t data1, uint8_t data2))handler;

/// AudioComponentDescription for this unit ('aumu' / 'phrg' / 'CPMa').
+ (AudioComponentDescription)componentDescription;

/// Register the subclass in-process so the standalone app can instantiate it
/// without the app extension. Idempotent. The extension registers via its
/// Info.plist instead.
+ (void)registerAUComponent;

@end

NS_ASSUME_NONNULL_END
