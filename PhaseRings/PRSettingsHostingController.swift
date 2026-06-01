//
//  PRSettingsHostingController.swift
//  PhaseRingsKit
//
//  Issue #23 (Phase F.2): @objc shim that lets the ObjC hosts (`ViewController`
//  in the app, `InstrumentViewController` in the extension) present the shared
//  SwiftUI `PRSettingsView`. It owns the `PRSettingsModel` (so it stays alive
//  for the screen's lifetime) and embeds a `UIHostingController` as a child —
//  embedding rather than subclassing `UIHostingController<…>` keeps the class
//  non-generic and therefore representable in Objective-C.
//
//  Edits flow live through `PRSettingsModel` → `PRSettingsStore`; the host is
//  responsible for observing the store (or reloading on dismiss) to push the
//  new settings into its audio core / AU parameter tree.
//
//  iOS 16: the controller presents itself as a medium/large detent sheet
//  (`UISheetPresentationController`, the primitive behind SwiftUI's
//  `presentationDetents`). Configured here rather than via the SwiftUI modifier
//  because the SwiftUI surface is embedded as a child controller — detents must
//  be set on the controller that is actually presented as a sheet. Both hosts
//  (app + AUv3) get the half-sheet for free.
//

import UIKit
import SwiftUI

@objc(PRSettingsHostingController)
public final class PRSettingsHostingController: UIViewController {

    private let model: PRSettingsModel

    /// Invoked when the user taps Done. The host dismisses + applies the new
    /// settings (swipe-to-dismiss is handled separately via the presentation
    /// controller delegate).
    @objc public var onDone: (() -> Void)?

    /// When true, the screen also shows the app-only MIDI / Network sections.
    /// The standalone app sets this; the AUv3 extension leaves it off. Set
    /// before presentation (read in viewDidLoad).
    @objc public var showsAppSettings: Bool = false

    @objc public init(store: PRSettingsStore) {
        self.model = PRSettingsModel(store: store)
        super.init(nibName: nil, bundle: nil)
        title = "Settings"
        modalPresentationStyle = .pageSheet
        if let sheet = sheetPresentationController {
            sheet.detents = [.medium(), .large()]
            sheet.prefersGrabberVisible = true
            sheet.prefersScrollingExpandsWhenScrolledToEdge = false
        }
    }

    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("PRSettingsHostingController must be created with initWithStore:")
    }

    public override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .systemBackground

        let host = UIHostingController(rootView: PRSettingsView(model: model,
                                                                 showsAppSettings: showsAppSettings) { [weak self] in
            self?.onDone?()
        })
        addChild(host)
        host.view.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(host.view)
        NSLayoutConstraint.activate([
            host.view.topAnchor.constraint(equalTo: view.topAnchor),
            host.view.bottomAnchor.constraint(equalTo: view.bottomAnchor),
            host.view.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            host.view.trailingAnchor.constraint(equalTo: view.trailingAnchor),
        ])
        host.didMove(toParent: self)
    }
}
