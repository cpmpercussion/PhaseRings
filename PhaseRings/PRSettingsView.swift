//
//  PRSettingsView.swift
//  PhaseRingsKit
//
//  Issue #23 (Phase F.2): the shared in-app settings screen. A SwiftUI `Form`
//  reproducing the instrument-relevant sections of the iOS Settings bundle,
//  bound to `PRSettingsModel` (the ObservableObject bridge over the
//  host-agnostic `PRSettingsStore`). Both the standalone app and the AUv3
//  extension present this same view; neither knows which store backs it.
//
//  Labels and value lists mirror the existing Settings.bundle plists 1:1
//  (Root.plist sound/composition, custom_composition.plist notes/scales,
//  sounds.plist slider ranges) so the screen is behaviourally identical to the
//  IASK one it will eventually replace.
//
//  iOS 16 floor (issue #23): uses `NavigationStack` for the title/Done chrome;
//  the host presents it as a `presentationDetents`-style sheet (see
//  PRSettingsHostingController). Form / Picker / Slider / Toggle are the body.
//

import SwiftUI

public struct PRSettingsView: View {

    @ObservedObject private var model: PRSettingsModel
    private let onDone: () -> Void

    public init(model: PRSettingsModel, onDone: @escaping () -> Void = {}) {
        self.model = model
        self.onDone = onDone
    }

    // Presentation strings, matching the Settings bundle exactly.
    private let soundSchemes = ["Phase Synthesis", "String Synthesis", "Singing Bowls",
                                "Gongs", "Crotales", "Terracotta Pots", "Marimba"]
    private let compositions = ["Custom Composition", "Study in Bowls", "Amores",
                                "Mixo Steps", "Scheimpflug Principle"]
    private let noteNames = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
    private let scaleNames = ["Ionian", "Dorian", "Phrygian", "Lydian", "Mixolydian",
                              "Aeolian", "Lochrian", "Lydian ♯5", "Mixolydian ♭6",
                              "Octatonic", "Whole Tone"]

    public var body: some View {
        NavigationStack {
            form
                .navigationTitle("Settings")
                .navigationBarTitleDisplayMode(.inline)
                .toolbar {
                    ToolbarItem(placement: .confirmationAction) {
                        Button("Done", action: onDone)
                    }
                }
        }
    }

    private var form: some View {
        Form {
            Section(header: Text("General")) {
                Picker("Sound Scheme", selection: $model.sound) {
                    ForEach(0..<soundSchemes.count, id: \.self) { Text(soundSchemes[$0]).tag($0) }
                }
                Picker("Composition", selection: $model.composition) {
                    ForEach(0..<compositions.count, id: \.self) { Text(compositions[$0]).tag($0) }
                }
                Toggle("Show Note Labels", isOn: $model.noteLabels)
                Toggle("Show Setup Description", isOn: $model.setupLabel)
            }

            // Custom notes/scales only matter when "Custom Composition" is selected.
            if model.composition == 0 {
                Section(header: Text("Custom Composition")) {
                    notePicker("First Note", selection: $model.note1)
                    scalePicker("First Scale", selection: $model.scale1)
                    notePicker("Second Note", selection: $model.note2)
                    scalePicker("Second Scale", selection: $model.scale2)
                    notePicker("Third Note", selection: $model.note3)
                    scalePicker("Third Scale", selection: $model.scale3)
                }
            }

            Section(header: Text("Audio")) {
                VStack(alignment: .leading) {
                    Text("Master Volume")
                    Slider(value: $model.masterVolume, in: 0...1.5)
                }
                VStack(alignment: .leading) {
                    Text("Reverb Volume")
                    Slider(value: $model.reverbVolume, in: 0...1)
                }
                Toggle("Process Audio Effects", isOn: $model.processEffects)
            }
        }
    }

    private func notePicker(_ title: String, selection: Binding<Int>) -> some View {
        Picker(title, selection: selection) {
            ForEach(0..<noteNames.count, id: \.self) { Text(noteNames[$0]).tag($0) }
        }
    }

    private func scalePicker(_ title: String, selection: Binding<Int>) -> some View {
        Picker(title, selection: selection) {
            ForEach(0..<scaleNames.count, id: \.self) { Text(scaleNames[$0]).tag($0) }
        }
    }
}
