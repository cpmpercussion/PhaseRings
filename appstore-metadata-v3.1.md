# PhaseRings v3.1 — App Store Connect metadata (copy-paste)

Minor maintenance update on top of v3.0. **Only the Promotional Text and the
What's New field change** from `appstore-metadata-v3.0.md`; Name, Subtitle,
Keywords, Description, Review Notes, and URLs are unchanged and reproduced here
so this stays a complete copy-paste reference.

## Name (30 chars max)

```
PhaseRings
```

## Subtitle (30 chars max — 28)

```
Ring instrument & AUv3 synth
```

## Keywords (100 chars max — 93)

```
auv3,audio unit,plugin,synth,instrument,midi,rings,generative,ambient,percussion,music making
```

## Promotional Text (170 chars max — 155)

```
PhaseRings is an AUv3 plugin — play it inside AUM, GarageBand or Logic Pro, run multiple instances, and drive it from MIDI. Seven expressive sound schemes.
```

## Description (4000 chars max)

Unchanged from v3.0 — reproduced for convenience.

```
PhaseRings is a musical instrument for performing expressive music with touch gestures. Anyone can create a beautiful piece of music with our sound schemes and generative composition engine!

Each ring on the screen represents a different pitch, and you can tap and swirl on each ring to create combinations of long and short notes. The angle and size of your tap will change the timbre of the notes you create!

New in version 3.0, PhaseRings is also an AUv3 Audio Unit plugin. Load it as an instrument in hosts like AUM, GarageBand, Logic Pro for iPad, and Cubasis — play the rings inside your host, run several instances at once, drive it from MIDI tracks, and record it through your host's effects.

PhaseRings includes seven expressive "sound schemes" featuring percussive sounds like marimba and singing bowls as well as pure synth sounds like phase and string synthesis.

Four "compositions" of pitches are included in the app, but you can also create your own custom composition by choosing three base notes and scales. PhaseRings will do the rest, generating a series of great setups from the harmony you choose!

Features:
- AUv3 Audio Unit instrument for AUM, GarageBand, Logic Pro, Cubasis, and other hosts
- 7 sound schemes
- 4 built-in compositions
- Custom generative composition
- 11 scales and modes
- Core MIDI in and out for iOS MIDI accessories and MIDI-enabled apps
- VoiceOver support and light/dark appearance
```

## What's New in This Version (4000 chars max)

```
PhaseRings 3.1 is a small maintenance update.

• Sound scheme fix: the sampled sound schemes (singing bowl, gong, crotales, and the others built on the SoundScraper engine) regain the bright, percussive attack that some players found had softened in 3.0. The grains now read from near the start of each sample again, so taps "snap" the way they used to.
• Under-the-hood audio engine build improvements.

Thanks to everyone who wrote in with feedback — keep it coming!
```

## App Review Information — Notes

Unchanged from v3.0 — reproduced for convenience.

```
PhaseRings is a self-contained musical instrument. No account, sign-in, or purchase is required; all features are available immediately.

Changes relevant to review:

1. The UIBackgroundModes audio entitlement flagged in the v2.0 review (guideline 2.5.4) has been removed. The app no longer declares or uses background audio.

2. This binary adds an AUv3 Audio Unit instrument extension. To test: install the app, then load "PhaseRings" as an instrument in a host — e.g. GarageBand (Tracks > External > Audio Unit Extensions) or AUM.

3. The local-network permission prompt appears only if the user enables the optional network ensemble features in settings; it is not required for normal use, and no data leaves the device otherwise.

Accessibility information: https://charlesmartin.au/phaserings/accessibility.html
```

## URLs

| Field              | Value                                                   |
|--------------------|---------------------------------------------------------|
| Marketing URL      | https://charlesmartin.au/phaserings/                    |
| Support URL        | https://charlesmartin.au/phaserings/#support            |
| Privacy Policy URL | https://charlesmartin.au/phaserings/privacy.html        |
| Accessibility URL  | https://charlesmartin.au/phaserings/accessibility.html  |
