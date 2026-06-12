# PhaseRings v3.1 — App Store submission notes

Working notes for the v3.1 App Store Connect submission (minor update).
v3.0 version record created 2026-05-31; v3.1 prepared 2026-06-12.

## What's in v3.1

- **SoundScraper read-point fix (#42)** — the sampled sound schemes (singing
  bowl, gong, crotales, marimba, etc.) regain their percussive note-onset
  "snap". The v3.0 Heavy migration scaled the granular `loopstart` read-point
  10× too deep (~250–540 ms into each sample instead of ~25–54 ms), so taps
  landed in the sustain body rather than the attack. Reported by a player via
  an App Store review reply.
- **Reproducible Heavy generation** — internal only; `scripts/build_hvcc.sh`
  now produces byte-identical C++ across runs. Not user-facing, not mentioned
  in release notes.

No new features, no UI changes, no permission or entitlement changes from v3.0.

## App Store metadata

Final copy-paste text for the fields that change this version (Promotional
Text, What's New) plus the unchanged fields for convenience lives in
**`appstore-metadata-v3.1.md`** — character limits checked. Everything else
(Name, Subtitle, Keywords, Description, Review Notes, URLs) is unchanged from
`appstore-metadata-v3.0.md`.

## App Accessibility section (Accessibility Nutrition Label)

Unchanged from v3.0 — no accessibility-affecting changes in this update. See
`release-v3.0.md` for the full declaration rationale (VoiceOver, Dark
Interface, Differentiate Without Color Alone) and the "do not declare yet"
list. Nothing to re-verify unless ASC requires re-confirmation.

## App Store Connect URLs

| Field             | Value                                                |
|-------------------|------------------------------------------------------|
| Marketing URL     | https://charlesmartin.au/phaserings/                 |
| Support URL       | https://charlesmartin.au/phaserings/#support         |
| Privacy Policy URL| https://charlesmartin.au/phaserings/privacy.html     |
| Accessibility URL | https://charlesmartin.au/phaserings/accessibility.html |

## Pre-submission device checklist

- [ ] Play each SoundScraper scheme (bowl, gong, crotales, marimba, …) and
      confirm the percussive attack "snap" is back on taps
- [ ] Confirm the synth schemes (phase, string) are unaffected
- [ ] AUv3 still loads and plays in AUM / GarageBand
- [ ] Settings About section shows "Version 3.1 (n)" with the CI build number
