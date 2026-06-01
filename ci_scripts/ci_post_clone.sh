#!/bin/sh
# ci_post_clone.sh — runs immediately after Xcode Cloud clones the repo.
#
# The Xcode project is generated from project.yml by XcodeGen and is NOT
# committed (see .gitignore). This script installs XcodeGen if needed and
# generates PhaseRings.xcodeproj before Xcode Cloud's build phase begins.

set -e

# Xcode Cloud sets CI_PRIMARY_REPOSITORY_PATH to the cloned repo root. Fall
# back to the directory above this script when running outside Xcode Cloud.
cd "${CI_PRIMARY_REPOSITORY_PATH:-"$(dirname "$0")/.."}"

if ! command -v xcodegen >/dev/null 2>&1; then
    echo "XcodeGen not found — installing via Homebrew…"
    if command -v brew >/dev/null 2>&1; then
        # HOMEBREW_NO_AUTO_UPDATE keeps the install fast and deterministic in CI.
        HOMEBREW_NO_AUTO_UPDATE=1 brew install xcodegen
    else
        echo "error: Homebrew is unavailable; cannot install XcodeGen." >&2
        exit 1
    fi
fi

echo "Generating PhaseRings.xcodeproj with $(xcodegen --version)…"
xcodegen generate

if [ ! -d "PhaseRings.xcodeproj" ]; then
    echo "error: xcodegen generate did not produce PhaseRings.xcodeproj." >&2
    exit 1
fi
echo "PhaseRings.xcodeproj generated successfully."
