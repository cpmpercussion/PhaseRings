# PhaseRings v3.0 — App Store submission notes

Working notes for the v3.0 App Store Connect submission (version record
created 2026-05-31). v2.0.0 shipped 2026-05-23.

## What's in v3.0

- Audio engine: Pure Data/libpd → compiled Heavy (hvcc)
- New: AUv3 instrument plugin (`aumu phrg CPMa`) — plays inside AUM,
  GarageBand, Logic Pro for iPad, Cubasis, etc.
- Removed: Audiobus, Inter-App Audio (superseded by the AUv3)
- Removed: `UIBackgroundModes` audio (issue #41 / App Review 2.5.4 — the
  v2.0 review complained; the AUv3 covers background/inter-app use)
- Shared settings UI (SwiftUI) in app + plugin; control bar bottom-centre;
  adaptive light/dark colours
- VoiceOver support on the instrument surface and controls; About section in
  settings

## App Store Connect URLs

| Field             | Value                                                |
|-------------------|------------------------------------------------------|
| Marketing URL     | https://charlesmartin.au/phaserings/                 |
| Support URL       | https://charlesmartin.au/phaserings/#support         |
| Privacy Policy URL| https://charlesmartin.au/phaserings/privacy.html     |
| Accessibility URL | https://charlesmartin.au/phaserings/accessibility.html |

## App Store metadata — make "AUv3" searchable

App Store search indexes only the **app name**, **subtitle**, and the hidden
**keywords field** — not the description. Musicians hunting for new
instruments search "auv3" directly, so it must appear in one of those three.

- **Subtitle** (30 chars max): e.g. `Ring instrument & AUv3 synth` (28 chars).
  This is the highest-value slot: visible on the product page *and* indexed.
- **Keywords field** (100 chars max, comma-separated, no spaces after commas):
  e.g. `auv3,audio unit,plugin,synth,instrument,midi,rings,generative,ambient,percussion,music making`
  (93 chars). Don't waste characters on "phaserings" (the name is already
  indexed) or plurals (search matches them). Avoid third-party app names
  (AUM, GarageBand) in *keywords* — guideline 2.3.7 territory; naming them in
  the **description** as compatible hosts is fine and conventional.
- **Description**: lead with AUv3 in the first paragraph (it's what's new and
  what differentiates v3.0), e.g. "…now an AUv3 Audio Unit plugin — play
  PhaseRings inside AUM, GarageBand, Logic Pro for iPad, Cubasis and other
  hosts." Not indexed, but it converts the people who arrive from an "auv3"
  search.
- **Promotional text** (170 chars, editable without re-review): use it to
  announce the AUv3 while v3.0 is fresh, e.g. "New in 3.0: PhaseRings is now
  an AUv3 plugin — load it in AUM, GarageBand or Logic, run multiple
  instances, and play it from MIDI."
- **What's New (release notes)**: AUv3 first line, for the same reason.

## App Accessibility section (Accessibility Nutrition Label)

App Store Connect → app page → **App Accessibility**. Declarations below are
based on what v3.0 actually does; each "supported" claim should be spot-checked
on a device before ticking (Apple expects declarations to be verified).

### Declare as supported

- **VoiceOver** — all on-screen controls have labels and hints (settings gear,
  setup stepper; the stepper announces the current setup description as its
  value). The playing surface uses `UIAccessibilityTraitAllowsDirectInteraction`
  (the standard instrument-app pattern, like GarageBand's keyboard) so VoiceOver
  users can play it by touch, with a label and hint describing the ring layout.
  The settings screen is SwiftUI Form — fully VoiceOver-navigable for free.
  *Verify: VoiceOver on (triple-click side button); swipe to gear and stepper to
  hear labels; confirm notes still play with touches inside the surface; open
  settings and navigate a few rows.*

- **Dark Interface** — the app tracks the system appearance; controls use
  system label colours and the surface background adapts (PR #40).
  *Verify: toggle dark mode mid-session; controls and background follow.*

- **Differentiate Without Color Alone** — pitch is conveyed by ring radius
  (geometry), not only colour; the optional *Show Note Labels* setting prints
  note names on the rings and *Show Setup Description* shows the scale/root as
  text. Declaring a feature that is enabled via a setting is allowed; note the
  setting in the label's optional notes field.

### Do NOT declare (yet) — and what it would take

- **Larger Text (Dynamic Type)** — the SwiftUI settings screen supports it, but
  the on-surface note labels and setup description use fixed-size fonts
  (15 pt label in `InstrumentViewController`, ring-relative note labels in
  `SingingBowlView`). Declare only after moving those to
  `UIFontMetrics`/text styles.
- **Sufficient Contrast** — system label colours are fine, but the ring
  colours (NoteColours hues) against the light/dark backgrounds haven't been
  measured against the 4.5:1 / 3:1 thresholds.
- **Voice Control** — the labelled buttons work, but *playing* the instrument
  via Voice Control is impractical; don't claim core-functionality support.
- **Reduced Motion** — the app doesn't currently check
  `UIAccessibility.isReduceMotionEnabled`; ring lighting animations are mild
  but unaudited.
- **Captions / Audio Descriptions** — not applicable: no speech, dialogue, or
  video content anywhere in the app. Leave unchecked (N/A), nothing to do.

### Supporting evidence (for review notes if asked)

- Accessibility page: https://charlesmartin.au/phaserings/accessibility.html
- VoiceOver work: commit `43f5800` (labels/hints/direct interaction), shipped
  in the v3.0 binary.
- Adaptive colours: PR #40 (merged 2026-06-06).

## Pre-submission device checklist

- [ ] Background mid-drone → system interrupts audio → foreground → audio
      recovers (issue #41 verification; `UIBackgroundModes` removed)
- [ ] Manual screen-lock mid-drone behaves like backgrounding (issue #41)
- [ ] VoiceOver pass per the App Accessibility notes above
- [ ] AUv3 loads and plays in AUM (screenshot already captured:
      `docs/images/phaserings-aum-auv3.jpg`)
- [ ] Settings About section shows "Version 3.0 (n)" with the CI build number
