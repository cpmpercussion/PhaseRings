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

### Phase A — Extract HeavyCore (no behaviour change)

1. Create `PhaseRingsKit.framework` target. **(not yet — see below)**
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

**Remaining for Phase A:** create `PhaseRingsKit.framework` and move
`HeavyCore` + `PhaseRings/Heavy/*` + the 6 WAVs into it (separable Xcode
surgery: new target, umbrella/public headers, embed in app, link). The code
is already shaped for this — `HeavyCore` has no app/session/RemoteIO deps and
loads samples via `bundleForClass:`.

### Phase B — Lock-free event FIFO (correctness)

The most important RT-safety work. Today `sendFloat:toReceiver:` calls Heavy
from the UI thread while `process()` runs on the audio thread — a latent data
race that happens to work standalone but is not RT-correct and *will* bite
under a host's render thread.

1. Add a single-producer / single-consumer lock-free ring buffer of events
   (`{kind: float|bang|note, receiverHash, values[3]}`).
2. UI thread / MIDI enqueues; the render block drains the FIFO and calls
   `ctx->sendFloatToReceiver` / `sendMessageToReceiverV` *before*
   `ctx->process()`.
3. Re-point `HeavyCore`'s `sendFloat:`/`sendBang:`/`sendNoteOn:` to enqueue.
4. Size the FIFO for worst-case touch+MIDI burst per block; drop-and-log on
   overflow rather than block.

### Phase C — PhaseRingsAudioUnit : AUAudioUnit

1. Subclass `AUAudioUnit`. `AudioComponentDescription`: type `'aumu'`,
   subtype + manufacturer (see "Identity" below).
2. One stereo output `AUAudioUnitBusArray`; `allocateRenderResourcesAndReturnError:`
   / `deallocateRenderResources`.
3. `internalRenderBlock`: capture `HeavyCore` (raw ptr, no ObjC/alloc/locks),
   drain FIFO, handle MIDI events from the `AURenderEvent` list, call
   `process()`. Reuse the existing `HeavyRenderCallback` body.
4. `AUParameterTree`: mastervolume, reverbvolume, distortlevel, processeffects
   (bool), selectsound (indexed). Each param `address` → Heavy receiver;
   handle host-ramped param events in the render block.
5. `fullState` / `fullStateForDocument` for save/restore (wrap `StateSaver`).
6. Factory presets — optional, low priority.

### Phase D — MIDI input

1. In `internalRenderBlock`, walk `AURenderEventMIDI` /
   `AURenderEventMIDIEventList` and map note-on/off → Heavy `__hv_notein`
   (hash already known: `0x67E37CA3`). Map ring touch → the same path so MIDI
   and touch are unified.
2. Decide note-off behaviour (the synths are largely one-shot/decaying — map
   note-off to whatever `sing`/`singlevel 0` does today).

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
