# Issue #23 — Shared instrument UI + settings for app and AUv3

**Goal:** app and AUv3 plugin render the *same* instrument surface and offer the
*same* controls, instead of today's full storyboard `ViewController` (app) vs.
stripped-down `InstrumentViewController` (plugin). Finishes the deferred
**Phase F step 3** of `auv3-plan.md`.

**Status:** F.0–F.4 + **F.5a** implemented (mixed ObjC/Swift Kit; settings
model/store/composition factory; shared SwiftUI settings screen; expanded
`InstrumentViewController` on-screen UI driven by the settings store; AUv3
`fullState` round-trip via `PRAudioUnitStore`; app settings unified on the
shared screen + IASK retired). **Deployment floor raised 14 → 16** during F.2
so the shared settings sheet can use `presentationDetents` (via
`UISheetPresentationController`).

**Remaining: F.5b** (issue **#27**) — embed the shared instrument *surface* in
the standalone app, make the AUv3 design the default, kill `Main.storyboard`,
deprecate the HCI-experiment chrome, and make **MIDI-out a shared app+AUv3
feature**. IAA is removed first (#26). This is a large `ViewController` refactor
whose ensemble/OSC regression risk isn't covered by automated tests, so it's its
own issue + PR. Full spec under Phase F.5b below.

---

## 1. Current state (what we're starting from)

### Two instrument surfaces
| | Standalone app | AUv3 extension |
|---|---|---|
| Controller | storyboard `ViewController` (`PhaseRings/ViewController.m`, 992 ln) | `PhaseRingsAUViewController` hosting shared `InstrumentViewController` (PhaseRingsKit, 259 ln) |
| On-screen UI | rings + setup stepper + setup label + ensemble view + settings button | rings + 3-pill bar: sound menu / "New Setup" / "Labels" (`InstrumentViewController.m:71`) |
| Extra subsystems | networking, MIDI-out, IAA, ensemble | none (correct — those stay app-only) |
| Composition source | `openComposition` reads NSUserDefaults (`ViewController.m:282`) | hardcoded `@[45,50,57]` / `IONIAN,MIXOLYDIAN,AEOLIAN` (`InstrumentViewController.m:166`) |

### Two settings / persistence models
- **App:** iOS **system Settings bundle** (`PhaseRings/Settings.bundle/*.plist`)
  surfaced in-app via **InAppSettingsKit** (popover/modal), persisted to
  `NSUserDefaults` standard domain. Keys: `composition`, `note_1..3`,
  `scale_1..3`, `sound`, `note_labels`, `setup_label`, `master_volume`,
  `reverb_volume`, `process_effects`, `midi_out`, `midi_in`,
  `remote_control_enabled`.
- **AUv3:** `AUParameterTree` — **5 params only**: `masterVolume`, `reverbVolume`,
  `distortLevel`, `processEffects`, `sound` (`PhaseRingsAudioUnit.mm:128–165`).
  There is **no `fullState` override**, so the AU relies on the default
  parameter-tree serialisation. **Composition / root notes / scales / labels are
  not persisted in the plugin at all** — they're hardcoded.

### The core tension
The system Settings bundle and IASK are **unavailable to an app extension**. And
the AU's per-session `fullState` can't currently express composition/scale
choices. So the unification has to introduce a **shared settings store + shared
settings UI** that each host backs with its own persistence:
- app → `NSUserDefaults`
- extension → AU parameters + `fullState`

---

## 2. Target architecture

```
PhaseRingsKit (mixed ObjC/Swift framework, shared by both targets)
 ├─ InstrumentViewController      ← the one true instrument surface (expanded; UIKit)
 ├─ PRSettingsStore  (ObjC proto) ← read/write typed settings; host-agnostic
 ├─ PRSettings       (model)      ← composition, notes, scales, sound, labels,
 │                                   master/reverb/distort, effects
 ├─ PRSettingsModel  (Swift)      ← ObservableObject bridge over PRSettingsStore
 │                                   for SwiftUI binding (@Published)
 ├─ PRSettingsView   (SwiftUI)    ← shared in-app settings form (replaces IASK)
 └─ PRSettingsHostingController   ← @objc UIHostingController shim so ObjC hosts
                                     can present PRSettingsView

App target                         Extension target
 ├─ ViewController  ──hosts──▶ InstrumentViewController
 │   + networking/OSC + ensemble chrome only (no storyboard; MIDI-out is
 │     shared in the Kit; IAA removed in #26)
 └─ PRUserDefaultsStore (NSUserDefaults-backed PRSettingsStore)

 PhaseRingsAUViewController ──hosts──▶ InstrumentViewController
   └─ PRAudioUnitStore (AUParameterTree + fullState-backed PRSettingsStore)
```

Key idea: the instrument surface and settings UI talk only to a `PRSettingsStore`
protocol. Neither knows whether it's in the app or the plugin.

**Language decision (issue #23):** the settings screen is built in **SwiftUI**
(`Form`/`Picker`/`Slider`/`Toggle`) — it's new, self-contained, form-shaped, and
shared by both targets, so it's where SwiftUI pays off most. The ring surface
(`SingingBowlView`, custom Core Graphics + bespoke touch→radius→pitch handling)
and its on-screen chrome **stay UIKit**. This makes PhaseRingsKit a mixed
ObjC/Swift framework; the blast radius of Swift is intentionally confined to the
one settings screen + a thin `ObservableObject` bridge.

---

## 3. Work breakdown

### Phase F.0 — Enable Swift in PhaseRingsKit (one-time setup)
1. Turn PhaseRingsKit into a mixed-language framework: `DEFINES_MODULE = YES`,
   confirm the generated `PhaseRingsKit-Swift.h` is importable from the ObjC
   hosts, and that the existing umbrella/module map still exposes the ObjC API.
2. Verify both consumers still link: standalone app **and** AUv3 extension
   (the appex is the tighter constraint — confirm Swift runtime + framework
   embed/sign still pass, given the earlier exportArchive codesign work).
3. Smoke-test: a trivial `@objc` Swift class instantiated from `ViewController`
   before building anything real on top.

### Phase F.1 — Settings model + store abstraction (PhaseRingsKit)
1. `PRSettings` value type holding everything currently split across the
   Settings bundle plists that is *instrument-relevant* (exclude app-only
   network/MIDI keys): `composition`, `note1..3`, `scale1..3`, `sound`,
   `noteLabels`, `setupLabel`, `masterVolume`, `reverbVolume`, `distortLevel`,
   `processEffects`.
2. `PRSettingsStore` protocol (ObjC): typed getters/setters + a change-notification
   block. Defaults mirror the current Settings bundle `DefaultValue`s. Add a
   Swift `PRSettingsModel: ObservableObject` that wraps a `PRSettingsStore` and
   republishes its values as `@Published` properties for SwiftUI binding (writes
   flow back through the store).
3. `PRUserDefaultsStore` (app): wraps the existing NSUserDefaults keys 1:1, so
   **existing user settings carry over unchanged**.
4. `PRAudioUnitStore` (extension): maps the 5 existing AU params, and persists
   the rest (composition/notes/scales/labels) via a `fullState` /
   `fullStateForDocument` override on `PhaseRingsAudioUnit` (new — see Phase F.4).
5. Move the composition-construction logic out of `ViewController.openComposition`
   (`ViewController.m:282`, incl. the case 1–4 presets + custom) into a shared
   `+[GenerativeSetupComposition compositionForSettings:]` so both hosts build
   the identical composition from `PRSettings`.

### Phase F.2 — Shared in-app settings screen (PhaseRingsKit, SwiftUI)
1. `PRSettingsView` — a SwiftUI `Form` reproducing the relevant Settings bundle
   sections: Sound Scheme (`Picker`), Composition + custom notes/scales
   (`Picker`s), Show Note Labels / Show Setup Description (`Toggle`s),
   Master/Reverb volume (`Slider`s), Process Effects (`Toggle`). Bound to
   `PRSettingsModel`.
   - **App-only sections** (MIDI, Network/remote, AutoConnect creds) are gated by
     a flag / injected section list so the extension simply omits them.
2. `PRSettingsHostingController` — `@objc` `UIViewController` that **embeds** a
   `UIHostingController<PRSettingsView>` as a child (rather than subclassing the
   generic hosting controller, which can't be represented in ObjC). ObjC hosts
   (`ViewController`, `InstrumentViewController`) present it. Reads/writes flow
   through `PRSettingsModel` → `PRSettingsStore`; changes apply live, and the
   host reloads the composition on dismiss (Done or swipe-down).
   - Presents itself as a **medium/large detent sheet** via
     `UISheetPresentationController` (the primitive behind SwiftUI's
     `presentationDetents`); set on the presented controller because the SwiftUI
     surface is an embedded child. Both hosts get the half-sheet for free.
3. **Retire IASK** for the instrument settings. (Decide separately whether to
   drop the `InAppSettingsKit` pod entirely or keep it only for any leftover
   app-only screens — see Open questions.) **Status:** in the app, the SwiftUI
   screen is wired *alongside* IASK behind the `PRUseSwiftUISettings` default for
   side-by-side comparison; IASK removal lands in F.5.
4. **iOS 16 floor:** `Form`/`Picker`/`Slider`/`Toggle` + `NavigationStack` +
   detents are all available; verify layout in a small AU host pane, not just
   full-screen (F.3 can lean on `ViewThatFits`).

### Phase F.3 — Expand `InstrumentViewController`'s on-screen UI (PhaseRingsKit) ✅
Per Charles's issue comment — a cleaner on-screen interface. **Implemented:**
1. Replaced the ad-hoc 3-pill bar (sound menu / New Setup / Labels) with a
   **setup stepper** (`UIStepper`, wraps, range from `numberOfSetups`), a
   **setup description label** (shown per the `setup_label` setting), and a
   **Settings gear** that presents `PRSettingsHostingController`. Sound scheme +
   note labels moved off the bar into the shared settings screen.
2. Composition + labels now come from `PRSettings` via
   `+[PRCompositionFactory compositionForSettings:]` — the hardcoded
   `@[45,50,57]`/`IONIAN…` defaults are gone.
3. The controller gained a `settingsStore` property (injectable; defaults to a
   new in-memory **`PRMemoryStore`** when no host injects one). It subscribes to
   `store.onChange` and applies *only what moved* in `-settingsDidChange:`
   (rebuild composition vs. just relabel vs. re-apply sound), so toggling a label
   doesn't reset the player to setup 0. Sound still routes out through the
   existing `soundSchemeHandler` seam (→ AU `sound` param in the extension).
4. Layout uses safe-area constraints; the bar is compact for small AU host panes.

**Deferred to F.4:** AU parameter-tree ↔ store sync (today the extension's
`PRMemoryStore` is seeded from defaults, not the AU's restored `sound`/volumes).
`PRMemoryStore` is the interim extension backing store; F.4 swaps in a
`fullState`-persisted `PRAudioUnitStore`.

### Phase F.4 — AU state round-trip (extension) ✅
**Implemented:**
1. `PhaseRingsAudioUnit` overrides `fullState`/`setFullState:`: it merges the
   non-parameter settings (composition/notes/scales/labels), held in a new
   `instrumentSettingsState` dictionary, into the dict alongside the
   auto-serialised parameter tree under `PhaseRingsInstrumentState`.
   `fullStateForDocument` builds on `fullState`, so it's covered too.
2. New **`PRAudioUnitStore`** (`PRSettingsStore`): the five audio params
   read/write through the AU parameter tree (so host automation + state stay
   consistent and the `implementorValueObserver` applies them to the core);
   composition/notes/scales/labels read/write the AU's `instrumentSettingsState`.
   `currentSettings` bases on `+[PRSettings defaultSettings]` so missing keys
   (fresh or older sessions) degrade gracefully. The AU view controller injects
   it into `InstrumentViewController.settingsStore`, replacing the F.3
   `PRMemoryStore`.
3. On restore, the AU fires `instrumentStateRestoredHandler` (main queue) →
   `PRAudioUnitStore` rebroadcasts via `onChange` → the instrument surface
   rebuilds. Covered by `PhaseRingsAUStateTests` (param+non-param round-trip,
   cross-unit `fullState` restore, onChange-on-restore) — no render alloc, so
   free of the #25 skip. Live host close/reopen check still pending (Phase H 4).

### Phase F.5 — Retrofit the standalone app (Phase F step 3)
Split into two commits (settings first, then the riskier surface embed).

**F.5a — settings unified + IASK retired ✅ (implemented)**
- `ViewController -showSettingsModal:` now always presents the shared
  `PRSettingsHostingController` (the `PRUseSwiftUISettings` toggle is gone). It
  sets `showsAppSettings = YES`.
- `PRSettingsView` gained a `showsAppSettings` flag → renders app-only **MIDI**
  (`midi_out`/`midi_in`) and **Network** (`remote_control_enabled`) sections,
  bound via `@AppStorage` straight to the existing NSUserDefaults keys. The
  extension leaves the flag off. (The `AutoConnect*` keys IASK referenced were
  dead — defined in no plist, read nowhere — so they're dropped, not ported.)
  **Note:** F.5b removes the **MIDI-out** toggle from this section — MIDI-out
  becomes always-on and shared (B3a); only `midi_in` + Network remain app-only.
- **IASK fully retired:** removed the `IASKAppSettingsViewController` /
  popover / delegate code, the `IASKSettingsDelegate` conformance, and the
  `InAppSettingsKit` pod (`pod install` → 0 pods). The `Settings.bundle` stays
  (it backs the iOS system Settings.app pane, independent of IASK).

**F.5b — embed the shared instrument surface in the app (pending, the risky half)**

> **Tracked as its own issue + PR (#27).** F.0–F.5a achieve the headline of #23
> (one shared settings UI, shared surface in the plugin) and are independently
> shippable. F.5b is a large refactor of the app's 992-line `ViewController` —
> its main risk, regressing the OSC/ensemble performance paths, **cannot be
> caught by the current automated tests** (no multi-device harness), so it needs
> its own device/ensemble test pass. The plan below is the spec for that issue.

> **Scope decisions (Charles, 2026-06-01) — the AUv3 surface becomes the
> default; lean into it rather than preserving every storyboard behaviour:**
> - **Kill `Main.storyboard`.** Build the container + window/root VC
>   programmatically. Storyboards no longer earn their keep.
> - **Deprecate the HCI-experiment chrome entirely** — remove
>   `experimentNewSetupButton`, performance-type chrome, `randomiseSound`,
>   `buttonFadingMode`, and the fades. Not coming back. This deletes a large
>   slice of the untested `ViewController` surface and removes the need for the
>   `controlsHidden`/`stepperHidden` seams the earlier draft proposed.
> - **IAA is removed, not preserved** (issue #26). Land **#26 first** — it also
>   refactors `ViewController` (the raw `AudioOutputUnitPublish` route), so do it
>   before this embed rather than re-wiring IAA only to delete it.
> - **MIDI-out becomes a shared app + AUv3 feature** (folded into #27). The
>   gesture→MIDI mapping moves into the Kit; each host supplies a transport.
>   **No settings switch** — always on (drop the `midi_out` gate + the F.5a
>   settings toggle). See B3a.
>
> Net app shell after F.5b: networking/OSC + ensemble overlay wrapped around the
> shared `InstrumentViewController`, with MIDI-out living in the Kit and no
> storyboard. Ensemble (`ensembleView`/`oscStatusLabel`) + OSC-driven setup
> changes stay app-only, exactly as before.

#### B1. What `ViewController` does today that must survive the embed
The app surface is not just "rings + stepper"; it is the hub for several
app-only behaviours that all reach into the same `bowlView` / geometry:

| Behaviour | Code today | Disposition under F.5b |
|---|---|---|
| Local tap → note | `touchesBegan:` (`VC.m:394`) | **Keep.** Audio (Kit) + MIDI note on/off (now Kit, always-on) + gated OSC touch msg (app, via delegate) |
| Local moved/ended | `touchesMoved/Ended:` (`:414/:423`) | **Keep.** OSC touch stream (app) + MIDI note off (Kit) |
| Local swirl | `panGestureRecognized:` (`:435`) | **Keep.** audio sing + bowl animation (Kit) + MIDI note/aftertouch (Kit) + OSC (app) |
| **Remote playback** | `processPlaybackTouchWithX:Y:Vel:` → `playbackTappedNote:` / `playbackMovingNote:Vel:` (`:494–558`) | **Keep, move into Kit.** network-driven; animates rings + plays audio with a 1s auto-stop timer |
| Remote setup change | network delegate → `compositionStepper`/`applyNewSetup:`/`updateSetupDescription:` (`:687`, `:707`) | **Keep.** ensemble "composition step" / "new idea" → `showSetupState:` |
| Performance-type chrome | hides/shows `compositionStepper`, `setupDescription`, `experimentNewSetupButton`; `randomiseSound`; fade in/out (`:773`+, `:903`+) | **DELETE** (HCI-experiment chrome deprecated) |
| Screenshot mode | `viewDidLayoutSubviews` → `lightAlternateRingsForScreenshot` + mute master (`:379`) | **Keep, move into Kit** (`screenshotMode`) |
| Geometry | `noteFromPosition:` / `calculateDistanceFromCenter:` (`:627/:633`) | **Keep in Kit** — used by touch + playback + MIDI |
| Ensemble chrome | `ensembleView` `drawEnsemble:` (`:669`), `oscStatusLabel` | **Keep, app-only**, overlaid |

#### B2. The audio-sink mismatch (decide first)
`InstrumentViewController` sends events to a `HeavyCore` via
`coreProvider` (`HeavyCore *(^)(void)`). The **app drives `HeavyAudioEngine`**,
which has the *same* send API (`selectSynth:`, `sendFloat:toReceiver:`,
`sendNoteOn:…`, `sendBangToReceiver:`) but **is not a `HeavyCore`** and exposes
no `core` accessor (`HeavyAudioEngine.h`). Options:
- **(preferred) Extract a `HeavyEventSink` protocol** (the four send methods +
  `selectSynth:`) that both `HeavyCore` and `HeavyAudioEngine` conform to, and
  retype `InstrumentViewController.coreProvider` to return `id<HeavyEventSink>`.
  Clean, keeps RT ownership where it is. Touches the shared `HeavyCore` header
  (used by the AU) — verify the appex still builds.
- (cheaper, leakier) Add a `core` getter to `HeavyAudioEngine` and keep
  `coreProvider` returning `HeavyCore *`. Bypasses the engine's own send path.

#### B3. New seams on `InstrumentViewController` (Kit)
A delegate (preferred over scattered blocks) carries **OSC/ensemble** concerns
only — MIDI is no longer app-only, so it leaves this protocol (see B3a):
```
@protocol InstrumentViewControllerDelegate <NSObject>
@optional
// Local input, with the resolved pitch so the app needn't recompute geometry.
- (void)instrument:(InstrumentViewController *)vc tapAtPoint:(CGPoint)p pitch:(int)pitch velocity:(int)vel;
- (void)instrument:(InstrumentViewController *)vc swirlState:(UIGestureRecognizerState)s
            atPoint:(CGPoint)p pitch:(int)pitch velocity:(CGFloat)v translation:(CGFloat)t;
- (void)instrumentTouchesEnded:(InstrumentViewController *)vc;
@end
```
Plus public API the app's network code calls:
- `- (void)playbackTapAtPoint:(CGPoint)p` / `- (void)playbackSwirlAtPoint:(CGPoint)p velocity:(CGFloat)v` / `- (void)stopPlayback` — the remote-OSC playback path (incl. the auto-stop timer) moves into the Kit.
- `- (void)showSetupState:(int)state` + `@property(readonly) NSInteger numberOfSetups` + `currentSetupState` — for remote setup changes (drives the existing stepper + label).
- `@property BOOL screenshotMode` — moves `lightAlternateRingsForScreenshot` + the layout hook into the Kit.
- Expose geometry if still needed: `- (int)pitchAtPoint:(CGPoint)p`.

(No `controlsHidden`/`stepperHidden` seam — performance-type chrome is deleted.)

#### B3a. Shared MIDI-out (folded into #27)
MIDI-out moves from app-only inline code (`VC.m:401–486`, hand-built note/
aftertouch bytes gated on the `midi_out` default, sent via
`MetatoneMidiManager`'s PGMidi) into the Kit, so the AUv3 plugin emits MIDI too.
The gesture→MIDI mapping (note-on at tap, note-off at end, aftertouch from swirl
velocity, channel 1) lives in `InstrumentViewController`; each host provides a
**transport sink**:
```
// Kit calls this whenever the instrument produces a MIDI event.
@property (nonatomic, copy, nullable) void (^midiOutSink)(const uint8_t *bytes, NSUInteger length);
```
- **App** → `MetatoneMidiManager`'s `midi sendBytes:` (CoreMIDI), as today.
- **AUv3** → advertise `MIDIOutputNames` and emit via the host-supplied
  `MIDIOutputEventBlock`. Gestures fire on the **main thread** but
  `MIDIOutputEventBlock` is pulled from the **render thread**, so the AU needs a
  lock-free main→render handoff (small ring buffer drained in
  `internalRenderBlock`). This is the only non-trivial new bit; the app side is
  a straight lift.
- **No settings switch:** drop the `midi_out` user-default gate and the MIDI-out
  toggle F.5a added to `PRSettingsView`; MIDI-out is always on. (`midi_in` —
  MIDI *input* feeding the synth — is unaffected here and stays as-is; its
  clean-up + sharing + ring-light feedback is the **#29** follow-up, building on
  the playback/remote-trigger seam this issue moves into the Kit.)

#### B4. View hierarchy — kill the storyboard
- Today `bowlView` is a storyboard `IBOutlet` with a pan recognizer;
  `ensembleView`, `oscStatusLabel`, `settingsButton` are sibling chrome
  (`experimentNewSetupButton` is deleted with the HCI chrome); `compositionStepper`
  + `setupDescription` **move into** the embedded controller.
- **Delete `Main.storyboard`.** Build the window/root VC programmatically (drop
  `UIMainStoryboardFile` from Info.plist; add a minimal `SceneDelegate`/window
  setup). `ViewController` builds a full-bleed **container view** in `viewDidLoad`
  that hosts `InstrumentViewController` as a child VC (`addChildViewController:` +
  constraints), with the ensemble/OSC chrome as overlays on top.
- Remove the now-dead `bowlView`/`compositionStepper`/`setupDescription` outlets,
  touch/pan/playback/geometry methods, the inline MIDI byte-building, and
  `openComposition`'s ring building from `ViewController`; route through the
  embedded controller + its `settingsStore` (already an `id<PRSettingsStore>` on
  the app side) + the new MIDI-out sink (B3a).

#### B5. Step order (each step builds + keeps the app shippable)
0. **Land #26 first** (remove IAA) — it refactors the same `ViewController`.
1. `HeavyEventSink` protocol + conformances (B2); retype `coreProvider`. Build app + appex.
2. Add the OSC delegate + public seams to `InstrumentViewController` (B3); move the
   playback path + screenshot mode into the Kit. Add the shared MIDI-out (B3a):
   gesture→MIDI in the Kit + `midiOutSink`; AU `MIDIOutputNames` +
   render-thread emit. Unit-test playback/setup-state + MIDI-mapping logic where possible.
3. Delete the HCI-experiment chrome from `ViewController` (B1).
4. Embed the child VC; build the container programmatically; wire delegate →
   OSC, `midiOutSink` → CoreMIDI, network callbacks → `showSetupState:`,
   screenshot default → `screenshotMode`. Delete the dead `ViewController` code.
5. Delete `Main.storyboard` + outlet cleanup; programmatic window setup.

#### B6. Verification (NOT covered by current tests)
1. Existing 47 unit + 5 UI/screenshot tests stay green (screenshot test pins the
   surface — watch for layout drift from the embed; update if the deliberate
   redesign changes it).
2. **Device pass (manual, required before merge):** local tap/swirl audio + ring
   animation; MIDI out from the **app** (always-on, no toggle); MIDI out from the
   **AUv3 plugin** into a host (e.g. AUM MIDI routing); screenshot mode lights
   alternate rings + mutes. (IAA no longer applies — removed in #26.)
3. **Ensemble pass (manual, multi-device or loopback OSC):** touch broadcast,
   remote playback animates + sounds, remote composition-step / new-idea change
   the setup. This is the path with no automated coverage and the main reason to
   PR it separately.

#### B7. Risks specific to F.5b
- Silent ensemble regressions (no automated coverage) — the dominant risk.
- AUv3 MIDI-out: main→render thread handoff must be lock-free / RT-safe; getting
  the `MIDIOutputEventBlock` timing or `MIDIOutputNames` advertisement wrong = no
  MIDI in the host. New surface, no prior coverage.
- Programmatic window/root-VC setup replacing the storyboard — verify launch,
  scene lifecycle, and child-VC layout vs. the screenshot test's expectations.
- Touching shared `HeavyCore` for the sink protocol — re-verify the appex.
- The remote-playback auto-stop timer + `currentlyPanningPitch` state moving into
  the Kit without changing behaviour.

---

## 4. Risks / watch-items
- **Settings migration:** `PRUserDefaultsStore` must read the *exact* existing
  keys so current users keep their settings. No key renames without migration.
- **Live updates:** app pushes changes to `HeavyAudioEngine`; extension must push
  through AU params (so host automation/state stays consistent) — don't bypass
  the parameter tree for the 5 mapped params.
- **Dropping IASK:** if the pod is removed, check nothing else references it; if
  kept, document why.
- **RT-safety unchanged:** settings work is all main-thread; don't touch the
  render path.
- **Extension bundle paths:** `PRSettingsView` must not assume `mainBundle`
  (carry-over watch-item).
- **Small-frame layout** for the expanded on-screen UI in AU host panes.
- **Mixed-language framework (new):** adding Swift to PhaseRingsKit is a one-time
  toolchain change — confirm the AUv3 appex still embeds/signs cleanly and that
  the ObjC hosts can import `PhaseRingsKit-Swift.h`. De-risk this in Phase F.0
  *before* building the settings UI on top.
- **Deployment floor 14 → 16 (decided in F.2):** raised so the settings sheet
  can use detents and F.3 can use `ViewThatFits`. Trades off older-device users;
  acceptable for v3.0. Bumped in `Podfile` + all `IPHONEOS_DEPLOYMENT_TARGET`
  entries; `pod install` re-run.

## 5. Open questions (resolve before/while implementing)
1. **Remove the `InAppSettingsKit` pod entirely**, or keep it for any residual
   app-only settings? (Leaning: remove — one settings UI is the point of #23.)
2. **App Group** to share presets between app and plugin (`auv3-plan.md` Phase G
   item 2), or keep their stores independent? Independent is simpler and matches
   "AU state is per-session"; App Group would let the plugin inherit the app's
   last-used composition.
3. **Custom composition editing in the plugin:** expose the full custom
   notes/scales editor in `PRSettingsViewController`, or limit the plugin to the
   named presets + sound scheme to keep the host pane simple?

## 6. Suggested PR sequence
1. F.0 enable Swift in PhaseRingsKit + trivial `@objc` smoke test (isolates the
   toolchain change; both targets must still build/sign before any feature code).
2. F.1 settings model + `PRSettingsModel` bridge + `PRUserDefaultsStore` + shared
   composition builder (app behaviour identical; pure refactor, easy to verify).
3. F.2 SwiftUI `PRSettingsView` + `PRSettingsHostingController` wired into the app
   behind a feature toggle alongside IASK, to compare.
4. F.3 expanded `InstrumentViewController` UI (plugin adopts it first).
5. F.4 AU `fullState` round-trip.
6. F.5 app retrofit + IASK removal.

Each step keeps both targets building and shippable.
