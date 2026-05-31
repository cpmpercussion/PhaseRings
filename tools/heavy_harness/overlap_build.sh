#!/usr/bin/env bash
# Build the dedicated [sampler-overlap] harness. Unlike build.sh (which links
# the three app contexts), this compiles ONLY a standalone SamplerOverlap
# context generated from PhaseRingSynth/sampler_overlap_test.pd, so it never
# touches the app's vendored PhaseRings/Heavy/ tree.
#
# Usage:
#   bash tools/heavy_harness/overlap_build.sh            # debug
#   bash tools/heavy_harness/overlap_build.sh --release  # NDEBUG, asserts off
#
# Output: tools/heavy_harness/build/overlap_harness

set -euo pipefail

MODE="debug"
if [ "${1:-}" == "--release" ]; then MODE="release"; fi

REPO_ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
HARNESS_DIR="$REPO_ROOT/tools/heavy_harness"
SYNTH_DIR="$REPO_ROOT/PhaseRingSynth"
HVCC="$REPO_ROOT/.venv-hvcc/bin/hvcc"
GEN_DIR="$HARNESS_DIR/overlap_gen"
BUILD_DIR="$HARNESS_DIR/build"

if [ ! -x "$HVCC" ]; then
    echo "hvcc not found at $HVCC -- run scripts/install_hvcc.sh first" >&2
    exit 1
fi

# Regenerate the wrapper context from scratch.
rm -rf "$GEN_DIR"
mkdir -p "$GEN_DIR" "$BUILD_DIR"
"$HVCC" "$SYNTH_DIR/sampler_overlap_test.pd" \
    -n SamplerOverlap -g cpp -o "$GEN_DIR" \
    -p "$SYNTH_DIR" -p "$SYNTH_DIR/libs" || true

if [ ! -f "$GEN_DIR/c/Heavy_SamplerOverlap.cpp" ]; then
    echo "FAIL: hvcc did not emit Heavy_SamplerOverlap.cpp" >&2
    exit 1
fi

echo "--- table enum (update overlap_main.cpp kDefaultTable if \$0 changed) ---"
grep -A4 "enum Table" "$GEN_DIR/c/Heavy_SamplerOverlap.hpp" || true
echo "------------------------------------------------------------------------"

CFLAGS=(-std=c++14 -Wno-unused-parameter -Wno-unused-variable)
if [ "$MODE" == "release" ]; then CFLAGS+=(-O2 -DNDEBUG); else CFLAGS+=(-O0 -g); fi

SRCS=("$HARNESS_DIR/overlap_main.cpp")
while IFS= read -r f; do SRCS+=("$f"); done < <(find "$GEN_DIR/c" \( -name '*.cpp' -o -name '*.c' \))

clang++ "${CFLAGS[@]}" \
    -I"$GEN_DIR/c" -I"$HARNESS_DIR" \
    "${SRCS[@]}" \
    -o "$BUILD_DIR/overlap_harness"

echo "built $BUILD_DIR/overlap_harness ($MODE)"
