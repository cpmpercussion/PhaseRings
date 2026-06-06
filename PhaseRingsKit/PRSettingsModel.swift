//
//  PRSettingsModel.swift
//  PhaseRingsKit
//
//  Issue #23 (Phase F.1): SwiftUI-facing bridge over the ObjC `PRSettingsStore`.
//  Exposes each setting as an `@Published` property so the shared SwiftUI
//  settings screen (Phase F.2) can bind directly; writes flow straight back
//  through the store, which persists and re-broadcasts. This is also the live
//  proof that PhaseRingsKit builds and links as a mixed ObjC/Swift framework
//  (replacing the Phase F.0 smoke test).
//

import Foundation
import Combine

@objc(PRSettingsModel)
public final class PRSettingsModel: NSObject, ObservableObject {

    private let store: PRSettingsStore
    // Token from the store's addSettingsObserver: (issue #37 — registering as
    // one observer among many, instead of stealing the instrument surface's
    // old single-slot `onChange` callback).
    private var observerToken: Any?
    // Suppresses store writes while we're ingesting a snapshot (load / observer
    // callback), so republishing doesn't bounce back into the store.
    private var isSyncing = false

    @Published public var sound: Int { didSet { push() } }
    @Published public var composition: Int { didSet { push() } }
    @Published public var noteLabels: Bool { didSet { push() } }
    @Published public var setupLabel: Bool { didSet { push() } }
    @Published public var masterVolume: Float { didSet { push() } }
    @Published public var reverbVolume: Float { didSet { push() } }
    @Published public var distortLevel: Float { didSet { push() } }
    @Published public var processEffects: Bool { didSet { push() } }
    @Published public var note1: Int { didSet { push() } }
    @Published public var note2: Int { didSet { push() } }
    @Published public var note3: Int { didSet { push() } }
    @Published public var scale1: Int { didSet { push() } }
    @Published public var scale2: Int { didSet { push() } }
    @Published public var scale3: Int { didSet { push() } }

    @objc public init(store: PRSettingsStore) {
        self.store = store
        let s = store.currentSettings()
        sound = s.sound
        composition = s.composition
        noteLabels = s.noteLabels
        setupLabel = s.setupLabel
        masterVolume = s.masterVolume
        reverbVolume = s.reverbVolume
        distortLevel = s.distortLevel
        processEffects = s.processEffects
        note1 = s.note1
        note2 = s.note2
        note3 = s.note3
        scale1 = s.scale1
        scale2 = s.scale2
        scale3 = s.scale3
        super.init()

        observerToken = store.addSettingsObserver { [weak self] snapshot in
            self?.ingest(snapshot)
        }
    }

    deinit {
        store.removeSettingsObserver(observerToken)
    }

    /// Pull a store snapshot into the published properties without writing back.
    private func ingest(_ s: PRSettings) {
        isSyncing = true
        sound = s.sound
        composition = s.composition
        noteLabels = s.noteLabels
        setupLabel = s.setupLabel
        masterVolume = s.masterVolume
        reverbVolume = s.reverbVolume
        distortLevel = s.distortLevel
        processEffects = s.processEffects
        note1 = s.note1
        note2 = s.note2
        note3 = s.note3
        scale1 = s.scale1
        scale2 = s.scale2
        scale3 = s.scale3
        isSyncing = false
    }

    /// Persist the current published values through the store.
    private func push() {
        guard !isSyncing else { return }
        store.updateSettings { s in
            s.sound = self.sound
            s.composition = self.composition
            s.noteLabels = self.noteLabels
            s.setupLabel = self.setupLabel
            s.masterVolume = self.masterVolume
            s.reverbVolume = self.reverbVolume
            s.distortLevel = self.distortLevel
            s.processEffects = self.processEffects
            s.note1 = self.note1
            s.note2 = self.note2
            s.note3 = self.note3
            s.scale1 = self.scale1
            s.scale2 = self.scale2
            s.scale3 = self.scale3
        }
    }
}
