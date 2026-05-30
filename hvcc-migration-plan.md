# v3.0 hvcc Migration Plan

## Status

**Pd → Heavy conversion: complete.** All three environment patches compile
cleanly with hvcc (0 errors, 11 non-blocking warnings).

```
$ bash scripts/check_hvcc_compat.sh
PhaseRingSynthEnvironment.pd             OK
CircleStringsSynthEnvironment.pd         OK
SoundScraperSynthEnvironment.pd          OK
```

The remaining warnings (`[block~]` ignored, `[declare]` inside abstractions
ignored) are non-blocking. Cleanup is optional; hvcc compiles either way.

## What changed in the patches

Branch: `v3.0-hvcc-migration` (commits since `8f9291b`).

| Phase | Change | Why |
|---|---|---|
| Phase/CircleStrings | Various | First-pass hvcc compat (commit `4bd75dd`) |
| `vu` removal | Top-level VU meter deleted | hvcc doesn't support UI-only objects |
| `[list]` family | All `[list]`, `[list prepend]`, `[list split]`, `[list trim]` rewritten as `[pack]`/`[unpack]`/`[route]`/messages | hvcc supports zero list-family ops |
| `$1-xyloClick` concat | Rewrote big embedded sample message | Heavy doesn't allow `$1-name` (dollar args must stand alone) |
| `[tabread4~]` initial arg | Added `tabread4~ crotale` in all 6 instances | hvcc requires the table arg; `set <name>` still swaps at runtime. crotale chosen as largest sample for bounds-check headroom |
| `[soundfiler]` removal | Moved sample-loading scaffolding into `PhaseRingSynth/load_sound_files.pd` (out of the compile path); deleted `[r samplesread]` gate | Heavy has no file I/O. Sample loading moves to the iOS host |
| `[makefilename]` removal | Removed defensive `panner/check-arg` idiom | Unsupported by hvcc; `panner` is always called with a literal arg |
| `@hv_table` annotation | All 6 sample tables marked `table NAME 200000 @hv_table` | Exposes them in Heavy's generated C API for host-side sample loading |
| `[pack s f f]` reorder | Reordered to `[pack f s f]` (gain first, tablename second), updated consumer `[unpack]` and `[set $1]` → `[set $2]` | hvcc allows `s` in `[pack]` slots > 0 but never in slot 0. `[unpack]` accepts `s` anywhere |

### Heavy quirks learned (worth keeping in mind for future patches)

- **`[list]` is completely unsupported** — not even `[list append]`.
- **`[pack]` accepts `s` only after slot 0**; `[unpack]` accepts `s` anywhere.
  This asymmetry is intentional in `PdPackObject.py`.
- **`[tabread4~]` needs an initial table name** but supports `set <name>`
  messages to swap at runtime. The initial table's *size* is what's used for
  bounds-check, so pick the largest sample as the default.
- **`@hv_table` marker** on `[table NAME SIZE @hv_table]` is the syntax to
  expose a table to the host as an `HV_..._TABLE_NAME` enum. Without it,
  tables are internal-only.
- **`[block~]`, `[declare]` inside abstractions**: ignored (warning only,
  not an error). Move `[declare]` to root canvas for cleanliness.
- **Control floats into the LEFT (signal) inlet of some `~` objects are
  silently dropped.** Heavy docs: *"Many objects do not take control signals
  on their left inlet. `[osc~]` for instance always requires the use of
  `[sig~]` before connecting a value."* hvcc emits **no warning** — it just
  generates an empty `cReceive_*_sendMessage` (for `[r]` sources) and leaves
  the signal inlet on the constant-zero buffer, so the patch goes silent /
  near-DC. **Confirmed dropped: `[samphold~]`** (the grain size / read-point
  fed its left inlet went to zero → static read; fixed by inserting `[sig~]`,
  see `sampler-overlap.pd`). The doc also names `[osc~]`.
  *Not* dropped — Heavy auto-converts or has a control-rate setter:
  `[phasor~]`/`[osc~]` frequency (compiles to a `sPhasor_k_onMessage` setter),
  and filter/arith inlets like `[lop~]`/`[*~]` (implicit signal-var, `sVarf`).
  Inconsistent by object, so when in doubt insert `[sig~]`.
  Audit the whole patch set with
  `tools/heavy_harness/check_control_to_signal_inlet.py PhaseRingSynth/**/*.pd`.

#### Control→signal-left-inlet audit (2026-05-30)

Ran the linter over all 33 `.pd` files. 12 candidates after excluding
abstraction/subpatch signal sources and by-design message inlets
(`set`→`[tabread4~]`, bang→`[snapshot~]`, msg→`[readsf~]`). Verdict — **no
outstanding bugs in the compiled patches**:

- `[osc~]`/`[phasor~]` freq (phasesynth, stringsynth, sampler-overlap,
  PhaseRingEnv): OK — `_k` message setter.
- `[lop~]` 1/0 gate (soundscrapersynth2): OK — implicit `sVarf`.
- `[delread~]` (pluck~): OK — vanilla control delay-time, compiles.
- `[samphold~]` ← `[r]` in **`soundscrapersynth.pd`**: the broken pattern, but
  that file is the OLD scraper, no longer instantiated (env uses
  `soundscrapersynth2` → fixed `sampler-overlap`). Dead code.
- `[c_adsr]`→`[outlet~]` in `bellsynth.pd`: orphaned patch, not reachable from
  any environment, and `c_adsr` doesn't resolve. Ignored.

## Architecture: how samples flow from disk to Heavy

Old flow (libpd, gone):

```
soundfiles subpatch:
  [loadbang] → [read -resize bowl.wav bowl] → [soundfiler] → [table bowl]
  ... × 6 samples ...
  → [s samplesread] → gates synth playback
```

New flow (Heavy):

```
iOS host (ObjC):
  load bowl.wav via AVAudioFile
  ctx->setLengthForTable(HV_SOUNDSCRAPER_TABLE_BOWL, numSamples)
  memcpy(ctx->getBufferForTable(HV_SOUNDSCRAPER_TABLE_BOWL), pcm, ...)
  ... × 6 samples ...
  (no runtime gate — host loads samples before process() runs)

In the patch:
  [tabread4~ crotale]  ← default; `set bowl`, `set gong`, etc. swap at runtime
```

The `pd soundfiles` subpatch in `SoundScraperSynthEnvironment.pd` is now an
empty subpatch placeholder. The original soundfiler scaffolding lives in
`PhaseRingSynth/load_sound_files.pd` outside the compile path (kept for
reference / future libpd debugging).

## Next: iOS-side work (the actual v3.0 build)

### 1. Generate Heavy C++ into the iOS project tree (done)

`scripts/build_hvcc.sh` generates C++ for all three patches and consolidates
the output under `PhaseRings/Heavy/`:

```
PhaseRings/Heavy/
  shared/                          61 files -- the Heavy runtime, compiled once
  Heavy_PhaseRing/                  3 files -- Heavy_PhaseRing.{cpp,h,hpp}
  Heavy_CircleStrings/              3 files -- Heavy_CircleStrings.{cpp,h,hpp}
  Heavy_SoundScraper/               3 files -- Heavy_SoundScraper.{cpp,h,hpp}
```

Each `hvcc` invocation emits the full Heavy runtime alongside the
patch-specific `Heavy_<Name>.cpp`. The runtime files are byte-identical
between contexts (SoundScraper additionally needs `HvControlPrint.c` and
`HvSignalSamphold.c`), so `build_hvcc.sh` moves them into a single
`shared/` directory — linking all three full trees would produce hundreds
of duplicate symbols.

`scripts/wire_heavy_into_xcode.rb` adds the resulting groups to the
`PhaseRings` target, attaches the source files to the build phase, and adds
`$(SRCROOT)/PhaseRings/Heavy/shared` to `HEADER_SEARCH_PATHS` so the
per-context entry .cpp files can resolve `#include "HeavyContext.hpp"`. The
script is idempotent (it removes any existing Heavy group before rebuilding),
so the regeneration flow is:

```
bash scripts/build_hvcc.sh           # regenerate sources
ruby scripts/wire_heavy_into_xcode.rb # re-sync Xcode project
```

Verified: the iPad Pro 11" simulator (iOS 26.5) Debug build succeeds with
Heavy code linked in (no audio driving it yet — that's Step 2).

### 2. Replace libpd with Heavy's C++ API

`PdAudioController` (libpd) goes away entirely. Need:

- A Core Audio `AURenderCallbackStruct` that drives `ctx->process()` for
  the current synth's Heavy context. Inputs/outputs in float interleaved
  or split form (Heavy uses split, libpd was interleaved — converter
  glue needed).
- Switch logic for the active synth (matches current `openPdPatch`):
  free old context, create new context, reload samples if it's the
  SoundScraper.
- A "send message to receiver" wrapper that maps the existing
  `[sendFloat: forReceiver: @"sing"]` style calls to
  `hv_sendFloatToReceiver(ctx, hashString("sing"), value)`. Same for
  `singpitch`, `singlevel`, `selectsound`, `mastervolume`,
  `sampleNameFreq`, `panTranslation`, `distortlevel`, `processeffects`,
  `reverbvolume`, etc.
- A return-message path if any patches send data back to the host
  (currently nothing does, so probably skip).

### 3. Sample loading (SoundScraper only)

- At app startup, decode the six WAVs in `PhaseRingSynth/samples/` via
  `AVAudioFile` to mono float32 at 44100 Hz. Cache `NSData` blobs.
- When SoundScraper context is created:
  - For each table name, call `setLengthForTable(HV_..._TABLE_X, len)`
  - `memcpy` the decoded PCM into `getBufferForTable(HV_..._TABLE_X)`
- Confirm the table hash enum values match (Heavy generates them based
  on the table name; the names must match the `[table NAME …]`
  declarations in `SoundScraperSynthEnvironment.pd`).

### 4. Drop CocoaPods libpd dependency

After the Heavy integration is verified working:

- Remove `pod 'libpd'` from `Podfile`
- `pod install` to regenerate `Pods/` and `Pods.xcodeproj`
- Delete any libpd-only ObjC bridging code
- Update `CLAUDE.md` (the "CocoaPods dependencies" table) and the
  build/run instructions

### 5. Smoke-test on hardware

- iPad Pro 11" simulator (iOS 26.5) — first pass
- iPad Pro / iOS 26.3 hardware — confirm audio works (this is the
  device that had the libpd glitch fixed in `main`; Heavy may have
  different audio engine semantics that need verification)
- Audiobus already dropped (per `MEMORY.md`), so no Audiobus regression
  test needed
- IAA: confirm still works under Heavy. The current `AudioOutputUnitPublish`
  setup is libpd-agnostic (Core Audio level), so it should be unaffected
  but verify

### 6. Polyphony sanity-check

- libpd was implicitly polyphonic via Pd's voice management. Heavy is not.
- The four `percsampler` instances in `SoundScraperSynthEnvironment.pd`
  provide four voices statically — confirm `PhaseRingSynthEnvironment.pd`
  and `CircleStringsSynthEnvironment.pd` have equivalent static
  polyphony, or accept reduced voices in v3.0.

## Files of interest

- `scripts/check_hvcc_compat.sh` — triage script, run anytime after patch edits
- `scripts/install_hvcc.sh` — sets up `.venv-hvcc/`
- `scripts/build_hvcc.sh` — generates Heavy C++ under `PhaseRings/Heavy/`
- `scripts/wire_heavy_into_xcode.rb` — re-syncs the generated tree into the
  Xcode project (idempotent)
- `PhaseRings/Heavy/{shared,Heavy_*}` — vendored Heavy output
- `PhaseRingSynth/*.pd` — patches that get compiled
- `PhaseRingSynth/load_sound_files.pd` — out-of-compile-path; original
  soundfiler scaffolding kept for reference
- `PhaseRingSynth/SoundScraperSynthEnvironment-old.pd` — pre-migration
  backup of the SoundScraper patch (untracked); delete when confident

## Next after the libpd→Heavy swap: AUv3 instrument

The Heavy core (no libpd/RemoteIO assumptions) is the enabler for shipping
PhaseRings as a proper AUv3 instrument (`kAudioUnitType_MusicDevice`) alongside
the standalone app. That effort has its own plan: see **`auv3-plan.md`**.

## Definition of done for v3.0

1. App builds and runs on iPad Pro 11" simulator without libpd
2. All three synths (Phase, CircleStrings, SoundScraper) produce audio
3. Sample-switching in SoundScraper works (tap a ring that selects a
   different sample → audible change)
4. IAA host connection still routes audio (verified in PR #18 / issue
   #17 recipe)
5. No regression on iPad Pro / iOS 26.3 audio (the libpd glitch fix
   carries over)
6. `pod 'libpd'` removed from Podfile; `Pods/` regenerated
7. `CLAUDE.md` updated to describe Heavy-based audio stack
