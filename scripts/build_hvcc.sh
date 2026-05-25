#!/usr/bin/env bash
# Generate Heavy C++ from each top-level Pd environment patch into the iOS
# project tree. Output is committed (treated as vendored sources) so the app
# builds without requiring hvcc on every machine. Regenerate after editing
# any .pd file under PhaseRingSynth/.
#
# Layout produced:
#   PhaseRings/Heavy/Heavy_PhaseRing/        (from PhaseRingSynthEnvironment.pd)
#   PhaseRings/Heavy/Heavy_CircleStrings/    (from CircleStringsSynthEnvironment.pd)
#   PhaseRings/Heavy/Heavy_SoundScraper/     (from SoundScraperSynthEnvironment.pd)
#
# See hvcc-migration-plan.md (Step 1) for context.

set -uo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
VENV_DIR="$REPO_ROOT/.venv-hvcc"
HVCC="$VENV_DIR/bin/hvcc"
SYNTH_DIR="$REPO_ROOT/PhaseRingSynth"
OUT_ROOT="$REPO_ROOT/PhaseRings/Heavy"

if [ ! -x "$HVCC" ]; then
    echo "hvcc not found at $HVCC -- run scripts/install_hvcc.sh first" >&2
    exit 1
fi

# patch.pd  =>  context base name. hvcc prefixes "Heavy_" to the name passed
# via -n when it emits sources, so passing PhaseRing yields Heavy_PhaseRing.cpp
# inside the corresponding output directory.
PATCHES=(
    "PhaseRingSynthEnvironment.pd:PhaseRing"
    "CircleStringsSynthEnvironment.pd:CircleStrings"
    "SoundScraperSynthEnvironment.pd:SoundScraper"
)

SEARCH_PATHS=(
    "-p" "$SYNTH_DIR"
    "-p" "$SYNTH_DIR/metaPdLibs"
    "-p" "$SYNTH_DIR/metaPdLibs/control"
    "-p" "$SYNTH_DIR/metaPdLibs/fx"
    "-p" "$SYNTH_DIR/metaPdLibs/instruments"
    "-p" "$SYNTH_DIR/metaPdLibs/scales"
)

mkdir -p "$OUT_ROOT"

OVERALL=0
for entry in "${PATCHES[@]}"; do
    patch="${entry%%:*}"
    name="${entry##*:}"
    out="$OUT_ROOT/Heavy_$name"

    echo "=== $patch -> Heavy_$name ==="
    rm -rf "$out"
    mkdir -p "$out"

    "$HVCC" \
        "$SYNTH_DIR/$patch" \
        -n "$name" \
        -g cpp \
        -o "$out" \
        "${SEARCH_PATHS[@]}"
    rc=$?

    if [ $rc -eq 0 ]; then
        echo "  OK -> $out"
    else
        echo "  FAIL exit=$rc"
        OVERALL=1
    fi
done

if [ $OVERALL -eq 0 ]; then
    echo
    echo "Heavy C++ generated under $OUT_ROOT"
    echo "Commit the changes to vendor the generated sources."
fi
exit $OVERALL
