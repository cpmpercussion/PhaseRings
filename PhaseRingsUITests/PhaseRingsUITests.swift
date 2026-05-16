//
//  PhaseRingsUITests.swift
//  PhaseRingsUITests
//

import XCTest

class PhaseRingsUITests: XCTestCase {

    var app: XCUIApplication!

    override func setUp() {
        super.setUp()
        continueAfterFailure = false
        app = XCUIApplication()
        app.launch()
    }

    /// Smoke test: app launches without crashing and has a visible window.
    func testLaunchDoesNotCrash() {
        XCTAssertTrue(app.wait(for: .runningForeground, timeout: 5.0))
        XCTAssertGreaterThan(app.windows.count, 0)
    }

    /// Tap centre of the main view to ensure the bowl view accepts touches
    /// (the path that exercises Pd note triggering and CALayer animation).
    func testTappingCentreDoesNotCrash() {
        let window = app.windows.firstMatch
        XCTAssertTrue(window.waitForExistence(timeout: 5.0))
        window.coordinate(withNormalizedOffset: CGVector(dx: 0.5, dy: 0.5)).tap()
        // Give Pd a beat to process the note-on before tearing down.
        XCTAssertTrue(app.wait(for: .runningForeground, timeout: 2.0))
    }

    /// Tap the composition stepper's "+" half to advance composition state.
    /// The stepper is the only UIStepper on screen, so first-match is safe.
    func testCompositionStepperIncrements() {
        let steppers = app.steppers
        // If the stepper isn't visible, skip — some performance modes hide it.
        guard steppers.firstMatch.waitForExistence(timeout: 3.0) else { return }
        steppers.firstMatch.buttons.element(boundBy: 1).tap()
        XCTAssertTrue(app.wait(for: .runningForeground, timeout: 2.0))
    }
}

/// App Store screenshot capture. Driven by scripts/make_screenshots.sh, which
/// runs this against the iPhone 17 and iPad Pro 11" (M5) simulators for both
/// light and dark appearance. The screenshots are attached to the test run
/// with `.keepAlways` so xcresulttool can extract them afterwards.
class PhaseRingsScreenshotTests: XCTestCase {

    override func setUp() {
        super.setUp()
        continueAfterFailure = false
    }

    func testCaptureLightMode() {
        captureScreenshot(style: "light")
    }

    func testCaptureDarkMode() {
        captureScreenshot(style: "dark")
    }

    private func captureScreenshot(style: String) {
        let app = XCUIApplication()
        app.launchArguments += ["-screenshotMode", "1", "-uiStyle", style]
        app.launch()
        XCTAssertTrue(app.wait(for: .runningForeground, timeout: 5.0))
        // Give the bowl view a beat to finish layout and re-light its rings;
        // viewDidLayoutSubviews fires more than once during launch.
        Thread.sleep(forTimeInterval: 1.5)
        let attachment = XCTAttachment(screenshot: XCUIScreen.main.screenshot())
        attachment.name = "phaserings-\(style)"
        attachment.lifetime = .keepAlways
        add(attachment)
    }
}
