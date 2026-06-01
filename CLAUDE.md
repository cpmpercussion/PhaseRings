# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

PhaseRings is an iOS music instrument app (Objective-C) that generates concentric ring UIs mapped to musical pitches. Players tap and swirl on rings to trigger notes. Audio synthesis runs via Pure Data (libpd), with Audiobus, Core MIDI, and OSC/WebSocket networking for ensemble performance.

## Build & Run

The Xcode project is **generated from `project.yml` by [XcodeGen]** and is *not*
committed (`PhaseRings.xcodeproj/` is gitignored). There are no third-party
package managers — all source is vendored in-tree. Generate the project, then
open it:

```
brew install xcodegen   # one-time, if not already installed
xcodegen generate       # writes PhaseRings.xcodeproj from project.yml
open PhaseRings.xcodeproj
```

Re-run `xcodegen generate` after adding/removing source files or changing
targets/settings — edit `project.yml`, never the generated `.xcodeproj`.

Build and run from Xcode (Cmd+R) against a connected iOS device or simulator.

UI tests live in `PhaseRingsUITests/`, unit tests in `PhaseRingsTests/`; run via
Xcode's test navigator (Cmd+U) or from the command line (see the M1 note below).

[XcodeGen]: https://github.com/yonaskolb/XcodeGen

## Xcode Cloud

The repo is wired into Xcode Cloud; builds on push to `main` and uploads to TestFlight in App Store Connect.

- **Project generation**: the `.xcodeproj` is not committed, so `ci_scripts/ci_post_clone.sh` installs XcodeGen (via Homebrew) and runs `xcodegen generate` after the clone, before the build phase. If a CI build fails at the very start, check that step first.
- **Shared scheme**: the `PhaseRings` shared scheme is declared in `project.yml` (`schemes:`) and emitted into `PhaseRings.xcodeproj/xcshareddata/xcschemes/` on generation — that's the one Xcode Cloud uses. Change it in `project.yml`, not by editing the generated scheme.
- **Build numbers**: "Use Xcode Cloud build number" is enabled on the workflow, which overrides `CFBundleVersion` from `Chorale/PhaseRings-Info.plist` (still `200` for local archives only). Build numbers are scoped per `CFBundleShortVersionString`; current marketing version is `2.0`, so the CI counter starts fresh from 1 for v2.0 — that's expected and fine.
- **Command-line builds on M1**: `xcodebuild test` for the iOS simulator needs `ONLY_ACTIVE_ARCH=YES ARCHS=arm64` overrides (target Debug has `ONLY_ACTIVE_ARCH=NO`). Xcode Cloud picks one arch per destination so it's not affected.

## Architecture

### Source layout

Each directory maps to exactly one target (XcodeGen globs them directly):

- `PhaseRings/` — standalone-app source (app shell, `ViewController`, networking glue, `HeavyAudioEngine`)
- `PhaseRingsKit/` — the **PhaseRingsKit.framework** source: shared instrument surface, compositions, `HeavyCore`, the AUAudioUnit, and the generated `Heavy/` DSP
- `PhaseRingsAUv3/` — the AUv3 app-extension wrapper
- `PhaseRingsTests/`, `PhaseRingsUITests/` — test targets
- `synth/` — Pure Data patches (`.pd`) and audio samples. The `.pd` files are hvcc *inputs only* (not bundled — the runtime engine is compiled Heavy, not libpd); the 6 sample WAVs under `synth/samples/` are bundled into the framework
- `MetatoneOSC/` — OSC networking library (F53OSC + GCDAsyncSocket) and `MetatoneNetworkManager` (compiled into the app)
- `MetatoneMIDI/` — Core MIDI wrapper (PGMidi) and `MetatoneMidiManager` (compiled into the app)

### Key classes and data flow

**`ViewController`** (`Chorale/ViewController.{h,m}`) is the single, central controller. It owns all subsystems and wires them together:

1. **Composition** — On launch, reads `NSUserDefaults` settings (composition choice, root notes, scales) and constructs a `GenerativeSetupComposition`. The composition generates a sequence of `SingingBowlSetup` objects (pitch arrays).

2. **Audio** — `PdAudioController` (libpd) initialises Pure Data at 44100 Hz. `openPdPatch` selects and opens one of three Pd environment patches based on the `sound` setting. The VC sends floats/NoteOns to Pd receivers (`sing`, `singpitch`, `singlevel`, `selectsound`, `mastervolume`, etc.).

3. **UI** — `SingingBowlView` renders concentric rings; each ring corresponds to a pitch in the current `SingingBowlSetup`. Touch position maps to ring radius → `pitchAtRadius:` → MIDI note number. Tap gestures trigger `sendNoteOn:`, pan gestures trigger continuous `sing` messages. `NoteColours` maps MIDI note numbers to hue for ring colouring.

4. **Networking** — `MetatoneNetworkManager` handles:
   - OSC broadcasting of touch events via F53OSC
   - Bonjour service discovery for a logging/classifier server
   - WebSocket connection to a Metatone Classifier (ML gesture classifier) via SocketRocket
   - Incoming OSC messages trigger delegate callbacks on `ViewController` for ensemble events (new idea, composition step, performance start/end)

5. **MIDI** — `MetatoneMidiManager` wraps PGMidi for CoreMIDI output; note-on/off and aftertouch are sent alongside Pd events when the `midi_out` setting is enabled.

6. **Audiobus** — `ABAudiobusController` registers the app as a generator; `StateSaver` serialises/deserialises `NSUserDefaults` state for Audiobus state saving.

### Composition model

```
SingingBowlComposition (base)
  └─ GenerativeSetupComposition
       └─ builds setups from (rootNotes × scales) using ScaleMaker
```

`ScaleMaker` provides class methods to compute MIDI note numbers for 11 modes/scales (Ionian through Whole Tone). `SingingBowlSetup` holds a flat `NSMutableArray` of MIDI pitches and maps a normalised radius (0–1) to a pitch index.

### Pure Data patches

Three top-level environment patches in `synth/`:
- `PhaseRingSynthEnvironment.pd` — phase synthesis
- `CircleStringsSynthEnvironment.pd` — string synthesis
- `SoundScraperSynthEnvironment.pd` — sample-based (bowl, gong, crotales, pot, marimba)

Sub-patches and shared libraries live in `synth/metaPdLibs/`. Audio samples (`.wav`) are in `synth/samples/`.

The patches are compiled ahead-of-time with hvcc into `PhaseRingsKit/Heavy/` (vendored — `shared/` holds the runtime, `Heavy_<Name>/` the per-patch entry). Regenerate after any `.pd` change with:

```
bash scripts/build_hvcc.sh && xcodegen generate
```

`build_hvcc.sh` rewrites `PhaseRingsKit/Heavy/`; `xcodegen generate` re-globs that directory into the framework target — no wiring script needed. See `hvcc-migration-plan.md`.

The Heavy sources, the host-agnostic `HeavyCore`, and the WAV samples live in the embedded **`PhaseRingsKit.framework`** target (shared so the AUv3 extension can reuse them). `HeavyAudioEngine` is just the standalone-app audio driver (AVAudioSession + RemoteIO) wrapping a `HeavyCore`. See `auv3-plan.md`.

## Dependencies

There are no third-party package managers. CocoaPods was removed once its last
pod (InAppSettingsKit) was retired — the audio engine is now compiled Heavy
(hvcc), not libpd, and Audiobus/IAA are gone. All remaining libraries (F53OSC +
GCDAsyncSocket under `MetatoneOSC/`, PGMidi under `MetatoneMIDI/`) are vendored
directly in-tree and compiled into the app target.

The only build-time tool is **XcodeGen** (`project.yml` → `.xcodeproj`).
