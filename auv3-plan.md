# v3.0 AUv3 Instrument Plan

Turning PhaseRings into a proper Audio Unit v3 instrument
(`kAudioUnitType_MusicDevice`, `'aumu'`) that ships **alongside** the
standalone app.

Prerequisite: the hvcc/Heavy migration (see `hvcc-migration-plan.md`). The
Heavy C++ core is the enabler — it has no libpd/RemoteIO assumptions baked in
once we finish the inversion below.

## Decisions (2026-05-30)

- **Full touch ring UI inside the plugin.** The `AUViewController` hosts the
  whole `SingingBowlView` ring UI, so PhaseRings is a *playable* instrument
  inside AUM / GarageBand / Logic, not just a MIDI sound module. It also
  accepts MIDI note input from the host.
- **Keep the standalone app + add the extension.** The standalone app keeps
  its OSC / MIDI / WebSocket ensemble features (Metatone). Networking is
  compiled into the app only, never the extension/shared framework.

## The core inversion (this is the crux)

Today `HeavyAudioEngine` *owns* a RemoteIO output unit and drives Heavy from
its own `HeavyRenderCallback` (`PhaseRings/HeavyAudioEngine.mm`). In AUv3 the
host owns audio I/O and calls *our* `internalRenderBlock`. So `HeavyAudioEngine`
splits in two:

```
HeavyCore               (host-agnostic, lives in the shared framework)
  - the 3 Heavy contexts (_phase/_strings/_soundscraper) + atomic _current
  - sample decode + loadSamplesIntoContext:
  - the render logic: drain event FIFO → ctx->process()
  - message sends (now via the FIFO, not direct)

StandaloneAudioDriver   (app target only)
  - AVAudioSession config (Playback + MixWithOthers)
  - RemoteIO unit + AURenderCallback that calls into HeavyCore
  - the current configureSession/buildAudioUnit/isActive/setActive code
```

The extension never touches `AVAudioSession` and never creates a RemoteIO
unit — the host provides both. The standalone app keeps exactly the audio path
it has today, just refactored to call `HeavyCore` instead of embedding it.

## Architecture: targets & code sharing

```
PhaseRingsKit.framework   (NEW, embedded)   ← shared by both app and extension
  - HeavyCore (+ PhaseRings/Heavy/* sources)
  - PhaseRingsAudioUnit : AUAudioUnit       (the 'aumu' instrument)
  - InstrumentViewController (the ring UI: SingingBowlView, NoteColours,
    touch→note logic, composition stepping)
  - composition model: SingingBowlComposition, GenerativeSetupComposition,
    SingingBowlSetup, ScaleMaker
  - StateSaver (settings serialise/restore)

PhaseRings.app           (standalone)        ← embeds the framework + extension
  - AppDelegate, app lifecycle
  - StandaloneAudioDriver (RemoteIO + session)
  - hosts InstrumentViewController as its root VC
  - InAppSettingsKit settings popover
  - MetatoneNetworkManager / MetatoneMIDI / OSC / WebSocket (app-only)
  - IAA publish (existing recipe; AUv3 is its modern successor but keep both)

PhaseRingsAUv3.appex     (NEW extension)     ← embeds the framework
  - Info.plist NSExtension → AudioComponents ('aumu', subtype, manufacturer)
  - AUViewController subclass that:
      * creates PhaseRingsAudioUnit
      * embeds InstrumentViewController as its view
  - NO networking, NO AVAudioSession, NO IAA
```

The standalone app instantiates the **same** `PhaseRingsAudioUnit` internally
(Apple's recommended pattern) so the app and plugin run identical audio code.

## Phases

### Phase A — Extract HeavyCore (no behaviour change) — ✅ COMPLETE

1. ✅ Created `PhaseRingsKit.framework` (embedded dynamic framework, iOS 14,
   `DEFINES_MODULE`, umbrella `PhaseRingsKit.h`, public `HeavyCore.h`). The 34
   Heavy sources + `HeavyCore.mm` + the 6 WAV samples now live in it; the app
   links + embeds it. `scripts/create_framework.rb` builds the target;
   `scripts/wire_heavy_into_xcode.rb` now targets `PhaseRingsKit`. Had to link
   AVFoundation/AudioToolbox explicitly (autolink doesn't fire for the
   framework). App builds & runs on the iPad Pro 11" (M5) simulator with the
   framework embedded; samples resolve via `bundleForClass:`.
2. ✅ Split `HeavyAudioEngine` → `HeavyCore` + standalone driver.
   `HeavyCore` (`PhaseRings/HeavyCore.{h,mm}`) holds the 3 contexts, the
   atomic `_current`, sample decode/load, `selectSynth:`, the message sends,
   and the RT render callback `HeavyCoreRenderCallback`. `HeavyAudioEngine`
   is now a thin standalone driver (AVAudioSession + RemoteIO) that wraps a
   `HeavyCore` and wires the callback with `core.renderRefCon`. Its public
   API is unchanged, so `ViewController` needed zero edits. The enqueue API
   is deferred to Phase B; sends still go straight to Heavy for now.
3. ✅ Sample loading uses `[NSBundle bundleForClass:[HeavyCore class]]`
   (was `mainBundle`), so it resolves wherever HeavyCore ships.
4. ✅ App builds on the iPad Pro 11" (M5) simulator, unchanged, via the new
   driver. (`scripts/add_heavycore.rb` wired the files in.)

Regeneration flow after a `.pd` change is now:

```
bash scripts/build_hvcc.sh            # regenerate Heavy C++
ruby scripts/wire_heavy_into_xcode.rb # re-sync into PhaseRingsKit (the framework)
```

`scripts/create_framework.rb` is a one-shot (creating the framework target);
it bails if `PhaseRingsKit` already exists.

### Phase B — Lock-free event FIFO (correctness) — ✅ COMPLETE

The most important RT-safety work. Previously `sendFloat:toReceiver:` called
Heavy from the UI thread while `process()` ran on the audio thread — a latent
data race that happened to work standalone but is not RT-correct and would
bite under a host's render thread.

Implemented in `HeavyCore.mm`:

1. ✅ `HeavyEventQueue` — ring buffer (1024) of POD `HeavyEvent`
   `{kind: Float|Bang|Note, hash, a,b,c}`. **Wait-free consumer** (render
   thread: relaxed read idx, acquire write idx, release on advance — no lock,
   no alloc). Producers serialise enqueue with `os_unfair_lock` (cheap, never
   contended on the render thread), so it's safe for the main thread *and*
   network-callback threads, not just a single producer.
2. ✅ `HeavyCoreRenderCallback` drains the queue into the active context
   (`sendFloatToReceiver`/`sendBangToReceiver`/`sendMessageToReceiverV`)
   immediately before `ctx->process()` — same thread, no race. Heavy's own
   message-queue mutation now only ever happens on the render thread.
3. ✅ `sendFloat:`/`sendBangToReceiver:`/`sendNoteOn:` only enqueue.
   Receiver-name hashing (`hv_stringToHash`) happens producer-side.
4. ✅ Overflow drops the event and bumps an atomic `_dropped` counter rather
   than blocking. The render state (active context + queue) lives in one
   `HeavyRenderState` behind `HeavyCore.renderRefCon`.

### Phase C — PhaseRingsAudioUnit : AUAudioUnit — ✅ COMPLETE

`PhaseRings/PhaseRingsAudioUnit.{h,mm}` in the framework.

1. ✅ `AUAudioUnit` subclass. Identity in one place: `'aumu'` / `'phrg'` /
   `'CPMa'`. `+componentDescription` and `+registerAUComponent` (in-process
   registration for the standalone app; the extension uses its Info.plist).
2. ✅ One stereo (non-interleaved float32) output bus + bus array.
   `allocateRenderResourcesAndReturnError:` builds a `HeavyCore` at the bus
   sample rate, selects the synth param's value, pushes all params, then
   publishes the refCon. `deallocateRenderResources` clears it.
3. ✅ `internalRenderBlock` captures a stable heap `AURenderCtx`
   (atomic `heavyRefCon` + scratch buffers). It repoints null host buffers at
   scratch, then calls the existing `HeavyCoreRenderCallback` (FIFO drain +
   `process()`). No ObjC/alloc/locks on the render path. MIDI-event walking is
   stubbed with a comment for Phase D.
4. ✅ `AUParameterTree`: masterVolume / reverbVolume / distortLevel /
   processEffects (bool) / synth (indexed Phase|CircleStrings|SoundScraper).
   `implementorValueObserver` maps float params to Heavy receivers (via the
   FIFO) and `synth` to `selectSynth:`. Host-ramped sample-accurate parameter
   events are NOT handled (the observer path is coarse-grained — fine for this
   instrument; revisit if needed).
5. ⬜ `fullState` — relying on the base class's parameter-tree snapshot for
   now; custom state (wrapping `StateSaver`) deferred.
6. ⬜ Factory presets — deferred (optional).

Smoke-tested at runtime (`PhaseRingsTests/PhaseRingsAudioUnitTests.m`, all
passing on the iPad Pro 11" (M5) sim): instantiate + allocate, render silence
(finite + silent), null-output-buffer path fills scratch, and — the key one —
FIFO-delivered `sing`/`singpitch`/`singlevel` events produce audible output
through the render block. This is the first end-to-end exercise of the Phase B
FIFO via a real render path.

### Phase D — MIDI input — ✅ COMPLETE

1. ✅ `internalRenderBlock` walks `realtimeEventListHead` for legacy
   `AURenderEventMIDI` note-on/off and forwards to the new RT-safe
   `HeavyCoreSendMIDINote(refCon, pitch, vel, channel)`, which sends
   `__hv_notein` directly on the render thread (no lock, mirrors the FIFO
   Note path). Channel is made 1-based to match the app's `sendNoteOn:1`.
   `AURenderEventMIDIEventList` (UMP / MIDI 2.0) is NOT handled — most hosts
   deliver legacy events unless the AU opts into the MIDI 2.0 protocol;
   revisit if a target host needs it.
2. ✅ Note-off (status 0x80, or note-on with velocity 0) forwards velocity 0
   to `[notein]`. The decaying/one-shot voices largely ignore it, which is the
   intended behaviour.

Smoke-tested: `testMidiNoteDrivesAudio` feeds a note-on through the render
event list (as a host would) and asserts audible output. Touch and MIDI now
share the same `[notein]` path.

### Phase E — Extension target + AUViewController

1. Create `PhaseRingsAUv3.appex`. Info.plist `NSExtension` →
   `NSExtensionAttributes.AudioComponents` entry; `NSExtensionPrincipalClass`
   = the `AUViewController`.
2. `AUViewController` overrides `createAudioUnitWithComponentDescription:` to
   make `PhaseRingsAudioUnit`, then embeds `InstrumentViewController` as its
   child VC and wires touch → the AU's FIFO.
3. Handle the resizable/auto-layout AU view so it works in narrow host frames.

### Phase F — Split ViewController

`ViewController` becomes two things:

1. `InstrumentViewController` (framework): owns the ring view, touch gestures,
   note generation, composition stepping, parameter UI. Talks only to
   `HeavyCore`/the AU — no networking, no IAA, no session.
2. Standalone app chrome (app target): settings popover (InAppSettingsKit),
   `MetatoneNetworkManager` wiring, IAA publish, app lifecycle. Hosts the
   instrument VC.

Networking delegate callbacks (ensemble new-idea / composition-step) drive the
instrument VC from the app side only.

### Phase G — Registration, entitlements, packaging

1. Embed framework in both app and appex; embed appex in app.
2. App Group (optional) if app↔extension need to share presets/state.
3. Audio entitlements; confirm no networking entitlement leaks into the appex.
4. Verify the AU registers: `auval -v aumu <subtype> <manuf>` on a Mac, and it
   appears in AUM / GarageBand / Logic on device.

### Phase H — Verify

1. `auval` passes.
2. Loads in AUM (and GarageBand/Logic) on iPad; touch UI renders and plays.
3. Host MIDI drives the synth; host automation moves the parameters.
4. State save/restore round-trips (close/reopen host session).
5. Standalone app still works end-to-end (audio, settings, ensemble net, IAA).
6. No regression on iPad Pro / iOS 26.3 audio.

## Identity (suggested — confirm before shipping)

- Component type: `kAudioUnitType_MusicDevice` (`'aumu'`)
- Manufacturer code: 4-char OSType, e.g. `'CPMa'` (Charles P. Martin) — must be
  registered consistently; reuse if one already exists.
- Subtype: e.g. `'phrg'`.
- Name string: `"Charles Martin: PhaseRings"` (host display = "Manufacturer:
  Name").

## Risks / watch-items

- **RT-safety**: zero ObjC, allocation, or locks on the render thread. The FIFO
  (Phase B) is non-negotiable for a clean `auval`.
- **Heavy context teardown vs in-flight render**: keep all 3 contexts live and
  swap via the atomic pointer (already done) — never `delete` while a render
  could be running.
- **Polyphony**: Heavy isn't implicitly polyphonic like Pd. Confirm static
  voice counts hold up under fast MIDI chords (carry-over from migration DoD).
- **AUv3 memory budget**: samples are only ~2.3 MB total — fine.
- **View hosting in small frames**: the ring UI must lay out sensibly in a host
  pane, not just full-screen iPad.
- **Bundle paths**: anything using `mainBundle` breaks in the extension.

## Definition of done for the AUv3 instrument

1. `PhaseRingsAUv3.appex` registers as an `'aumu'` instrument; `auval` passes.
2. Loads in AUM/GarageBand/Logic on device; full ring touch UI renders and is
   playable; audio comes out.
3. Host MIDI plays it; host parameter automation works; state round-trips.
4. Standalone app unchanged for the user (audio, settings, ensemble net, IAA).
5. App and extension share one `PhaseRingsAudioUnit` code path via
   `PhaseRingsKit.framework`.
6. No RT-thread allocations/locks (verified via `auval` + Instruments).
