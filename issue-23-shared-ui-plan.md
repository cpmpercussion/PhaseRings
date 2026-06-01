# Issue #23 — Shared instrument UI + settings for app and AUv3

**Goal:** app and AUv3 plugin render the *same* instrument surface and offer the
*same* controls, instead of today's full storyboard `ViewController` (app) vs.
stripped-down `InstrumentViewController` (plugin). Finishes the deferred
**Phase F step 3** of `auv3-plan.md`.

**Status:** F.0–F.2 implemented (mixed ObjC/Swift Kit; settings model/store/
composition factory; shared SwiftUI settings screen). **Deployment floor raised
14 → 16** during F.2 so the shared settings sheet can use `presentationDetents`
(via `UISheetPresentationController`) and F.3 can use `ViewThatFits` for the AU
host pane. F.3–F.5 remain.

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
 │   + networking / MIDI / IAA / ensemble chrome only
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

### Phase F.3 — Expand `InstrumentViewController`'s on-screen UI (PhaseRingsKit)
Per Charles's issue comment — a cleaner on-screen interface:
1. Replace the ad-hoc 3-pill bar with: **scale/setup label**, a **setup stepper**
   (currently app-only — `compositionStepper`), and a **Settings button** that
   presents `PRSettingsHostingController` (UIKit chrome, stays ObjC).
2. Drive composition + labels from `PRSettings` instead of the hardcoded
   `reloadComposition` defaults (`InstrumentViewController.m:166`).
3. Keep the `coreProvider` / `soundSchemeHandler` block seam; route *all* setting
   changes through the store, and have each host observe the store to push to its
   core / AU params.
4. Ensure it lays out in a small host pane as well as full-screen iPad
   (carry-over watch-item from `auv3-plan.md` risks).

### Phase F.4 — AU state round-trip (extension)
1. Add `fullState` / `fullStateForDocument` override to `PhaseRingsAudioUnit`
   that serialises the non-parameter settings (composition/notes/scales/labels)
   alongside the auto-serialised parameter tree.
2. On `setFullState:`, restore into `PRAudioUnitStore` and refresh the instrument
   surface.
3. Verify state round-trips across host close/reopen (Phase H item 4).

### Phase F.5 — Retrofit the standalone app (Phase F step 3)
1. Point `ViewController` at an embedded `InstrumentViewController` for the ring
   surface + on-screen controls, leaving only networking / MIDI-out / IAA /
   ensemble chrome in the app shell.
2. Swap the IASK popover for `PRSettingsHostingController` (+ the app-only sections).
3. Confirm no behaviour regression: audio, settings persistence, ensemble net,
   IAA, screenshot mode (`ViewController.m:339`).

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
