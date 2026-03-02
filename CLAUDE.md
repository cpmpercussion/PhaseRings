# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

PhaseRings is an iOS music instrument app (Objective-C) that generates concentric ring UIs mapped to musical pitches. Players tap and swirl on rings to trigger notes. Audio synthesis runs via Pure Data (libpd), with Audiobus, Core MIDI, and OSC/WebSocket networking for ensemble performance.

## Build & Run

Dependencies are managed with CocoaPods. Always open the workspace, not the `.xcodeproj`:

```
pod install          # install/update CocoaPods dependencies
open PhaseRings.xcworkspace
```

Build and run from Xcode (Cmd+R). Target a connected iOS device or simulator. There are no command-line build or test scripts; everything runs through Xcode.

UI tests live in `PhaseRingsUITests/` and can be run via Xcode's test navigator (Cmd+U). The test suite is a mostly-empty template.

## Architecture

### Source layout

- `Chorale/` — all main app Objective-C source (the Xcode target is `PhaseRings`; "Chorale" is an older internal name)
- `PhaseRingSynth/` — Pure Data patches (`.pd`) and audio samples used by libpd
- `MetatoneOSC/` — OSC networking library (F53OSC + GCDAsyncSocket) and `MetatoneNetworkManager`
- `MetatoneMIDI/` — Core MIDI wrapper (PGMidi) and `MetatoneMidiManager`

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

Three top-level environment patches in `PhaseRingSynth/`:
- `PhaseRingSynthEnvironment.pd` — phase synthesis
- `CircleStringsSynthEnvironment.pd` — string synthesis
- `SoundScraperSynthEnvironment.pd` — sample-based (bowl, gong, crotales, pot, marimba)

Sub-patches and shared libraries live in `PhaseRingSynth/metaPdLibs/`. Audio samples (`.wav`) are in `PhaseRingSynth/samples/`.

## CocoaPods dependencies

| Pod | Purpose |
|-----|---------|
| `libpd` | Pure Data audio engine |
| `InAppSettingsKit` | Settings UI presented as a popover/modal |
| `Audiobus` (~2.1) | Inter-app audio / Audiobus 2 integration |
| `SocketRocket` (~0.5) | WebSocket client for Metatone Classifier |
