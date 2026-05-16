#!/bin/sh
# ci_post_clone.sh — runs immediately after Xcode Cloud clones the repo.
# Ensures the Pods/ tree matches Podfile.lock before the build phase begins.
# Pods/ is tracked in this repo, but this is a safety net for cases where the
# committed Pods drift from the lockfile.

set -e

# Xcode Cloud runs this script with CI_PRIMARY_REPOSITORY_PATH set to the
# cloned repo root.
cd "$CI_PRIMARY_REPOSITORY_PATH"

# CocoaPods ships with the Xcode Cloud image but may need the spec repo cache
# warmed for the first run. --no-repo-update keeps things fast in CI when the
# committed Podfile.lock already points at resolved versions.
if command -v pod >/dev/null 2>&1; then
    pod install --no-repo-update
else
    echo "CocoaPods not found on the Xcode Cloud image; cannot run pod install." >&2
    exit 1
fi
