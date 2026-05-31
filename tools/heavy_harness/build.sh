#!/usr/bin/env bash
# Build the Heavy harness binary. Links every Heavy context (Phase, Strings,
# Scraper) so the binary can drive any of them via --synth.
#
# Usage:
#   bash tools/heavy_harness/build.sh             # debug build, hv_assert active
#   bash tools/heavy_harness/build.sh --release   # NDEBUG, asserts compiled out
#
# Use --release to render audio past tabread bounds asserts (matches what
# the iOS app does in shipping builds), --debug to catch the first OOB.
#
# Output: tools/heavy_harness/build/harness

set -euo pipefail

MODE="debug"
if [ "${1:-}" == "--release" ]; then MODE="release"; fi

REPO_ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
HARNESS_DIR="$REPO_ROOT/tools/heavy_harness"
HEAVY_ROOT="$REPO_ROOT/PhaseRings/Heavy"
BUILD_DIR="$HARNESS_DIR/build"

mkdir -p "$BUILD_DIR"

INCLUDES=(
    -I"$HEAVY_ROOT/shared"
    -I"$HEAVY_ROOT/Heavy_PhaseRing"
    -I"$HEAVY_ROOT/Heavy_CircleStrings"
    -I"$HEAVY_ROOT/Heavy_SoundScraper"
    -I"$HARNESS_DIR"
)

CFLAGS=(-std=c++14 -Wno-unused-parameter -Wno-unused-variable)
if [ "$MODE" == "release" ]; then
    CFLAGS+=(-O2 -DNDEBUG)
else
    CFLAGS+=(-O0 -g)
fi

# Heavy's runtime is a mix of .c and .cpp. clang++ compiles both; the headers
# already guard with extern "C" where it matters.
SRCS=(
    "$HARNESS_DIR/main.cpp"
    "$HEAVY_ROOT/Heavy_PhaseRing/Heavy_PhaseRing.cpp"
    "$HEAVY_ROOT/Heavy_CircleStrings/Heavy_CircleStrings.cpp"
    "$HEAVY_ROOT/Heavy_SoundScraper/Heavy_SoundScraper.cpp"
)
# Include every shared file (both .c and .cpp).
while IFS= read -r f; do SRCS+=("$f"); done < <(find "$HEAVY_ROOT/shared" \( -name '*.cpp' -o -name '*.c' \))

clang++ "${CFLAGS[@]}" \
    "${INCLUDES[@]}" \
    "${SRCS[@]}" \
    -o "$BUILD_DIR/harness"

echo "built $BUILD_DIR/harness ($MODE)"
