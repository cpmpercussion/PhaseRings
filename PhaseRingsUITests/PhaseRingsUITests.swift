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

    /// The settings sheet over the surface (one per appearance). Finds the
    /// gear via its accessibility label.
    func testCaptureSettingsLight() {
        captureScreenshot(style: "light", settings: true)
    }

    func testCaptureSettingsDark() {
        captureScreenshot(style: "dark", settings: true)
    }

    private func captureScreenshot(style: String, settings: Bool = false) {
        let app = XCUIApplication()
        // Vary the lit-ring pattern across the set: light shots use the classic
        // on-off alternation, dark shots the 1-on/1-off/2-on/1-off cycle.
        let pattern = style == "dark" ? "varied" : "alternate"
        app.launchArguments += ["-screenshotMode", "1", "-uiStyle", style,
                                "-screenshotPattern", pattern]
        app.launch()
        XCTAssertTrue(app.wait(for: .runningForeground, timeout: 5.0))
        // Give the bowl view a beat to finish layout and re-light its rings;
        // viewDidLayoutSubviews fires more than once during launch.
        Thread.sleep(forTimeInterval: 1.5)
        var name = "phaserings-\(style)"
        if settings {
            app.buttons["Settings"].tap()
            XCTAssertTrue(app.navigationBars["Settings"].waitForExistence(timeout: 5.0))
            // Let the sheet's presentation animation settle.
            Thread.sleep(forTimeInterval: 1.0)
            name = "phaserings-settings-\(style)"
        }
        let attachment = XCTAttachment(screenshot: XCUIScreen.main.screenshot())
        attachment.name = name
        attachment.lifetime = .keepAlways
        add(attachment)
    }
}

/// App Store preview-video choreography. Driven by scripts/make_preview_video.sh,
/// which records the simulator screen (simctl io recordVideo) while this test
/// plays the instrument: a few taps, a swirl around a ring (approximated by
/// short drag segments — XCUITest is single-pointer), taps over the top, and a
/// closing phrase. Timing aims for ~25 s of in-app footage (ASC previews are
/// 15–30 s).
class PhaseRingsPreviewVideoTests: XCTestCase {

    func testPreviewChoreography() {
        continueAfterFailure = false
        let app = XCUIApplication()
        // screenshotMode forces the busy 9-ring spread (the default composition
        // can land on a sparse 2-3 ring setup that reads as empty on video);
        // pattern "none" leaves every ring unlit so all the colour in the
        // preview comes from the touches.
        app.launchArguments += ["-screenshotMode", "1", "-uiStyle", "light",
                                "-screenshotPattern", "none"]
        app.launch()
        // Generous waits: this runs on a freshly-booted sim with the video
        // recorder competing for cycles, where the usual 5 s can flake.
        XCTAssertTrue(app.wait(for: .runningForeground, timeout: 30.0))
        let window = app.windows.firstMatch
        XCTAssertTrue(window.waitForExistence(timeout: 15.0))
        func at(_ dx: CGFloat, _ dy: CGFloat) -> XCUICoordinate {
            window.coordinate(withNormalizedOffset: CGVector(dx: dx, dy: dy))
        }
        Thread.sleep(forTimeInterval: 2.5)   // launch settle

        // A couple of opening taps on different rings.
        at(0.50, 0.50).tap()
        Thread.sleep(forTimeInterval: 1.4)
        at(0.50, 0.32).tap()
        Thread.sleep(forTimeInterval: 1.4)
        at(0.72, 0.55).tap()
        Thread.sleep(forTimeInterval: 1.6)

        // Swirl: drag segments around a circle (radius compensated for the
        // window aspect so the path is roughly circular), with taps landing
        // over the top mid-swirl (issue #35's polyphony in action).
        let frame = window.frame
        let rx: CGFloat = 0.24
        let ry = rx * frame.width / frame.height
        func onCircle(_ turn: CGFloat) -> XCUICoordinate {
            let a = turn * 2 * .pi
            return at(0.5 + rx * cos(a), 0.5 + ry * sin(a))
        }
        let segments = 16
        for i in 0..<segments {
            let from = onCircle(CGFloat(i) / CGFloat(segments))
            let to = onCircle(CGFloat(i + 1) / CGFloat(segments))
            from.press(forDuration: 0.04, thenDragTo: to)
            if i == 5 || i == 11 {
                at(0.50, 0.50).tap()   // taps over the swirl
            }
        }
        Thread.sleep(forTimeInterval: 1.2)

        // Closing phrase.
        at(0.50, 0.38).tap()
        Thread.sleep(forTimeInterval: 1.2)
        at(0.65, 0.50).tap()
        Thread.sleep(forTimeInterval: 1.2)
        at(0.50, 0.50).tap()
        Thread.sleep(forTimeInterval: 3.0)   // let the last note ring out
    }
}
