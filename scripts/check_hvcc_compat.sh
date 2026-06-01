#!/usr/bin/env bash
# Run hvcc against each of the three top-level Pd environment patches and
# capture per-patch output. Goal is compatibility triage, not a usable build,
# so we don't keep the generated C. See issue #20 for the v3.0 plan.
#
# Outputs:
#   build/hvcc/<patch-name>/        -- generated C/C++ (kept for inspection)
#   build/hvcc/<patch-name>.log     -- stdout+stderr from the hvcc run
#   build/hvcc/summary.txt          -- exit codes per patch
#
# Search paths: synth/ itself (root environment patches) and
# synth/libs/ (every abstraction the roots reference).

set -uo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
VENV_DIR="$REPO_ROOT/.venv-hvcc"
HVCC="$VENV_DIR/bin/hvcc"
SYNTH_DIR="$REPO_ROOT/synth"
OUT_DIR="$REPO_ROOT/build/hvcc"

if [ ! -x "$HVCC" ]; then
    echo "hvcc not found at $HVCC -- run scripts/install_hvcc.sh first" >&2
    exit 1
fi

PATCHES=(
    "PhaseRingSynthEnvironment.pd"
    "CircleStringsSynthEnvironment.pd"
    "SoundScraperSynthEnvironment.pd"
)

SEARCH_PATHS=(
    "-p" "$SYNTH_DIR"
    "-p" "$SYNTH_DIR/libs"
)

rm -rf "$OUT_DIR"
mkdir -p "$OUT_DIR"

SUMMARY="$OUT_DIR/summary.txt"
: > "$SUMMARY"

OVERALL=0
for patch in "${PATCHES[@]}"; do
    name="${patch%.pd}"
    log="$OUT_DIR/$name.log"
    out="$OUT_DIR/$name"
    mkdir -p "$out"

    echo "=== $patch ==="
    "$HVCC" \
        "$SYNTH_DIR/$patch" \
        -n "$name" \
        -g c \
        -o "$out" \
        "${SEARCH_PATHS[@]}" \
        >"$log" 2>&1
    rc=$?

    # See build_hvcc.sh for the same logic: pd2gui's legacy-color check trips
    # hvcc's exit code even though pd2hv/hv2ir/ir2c succeeded. Treat the
    # presence of a generated c/ directory as success.
    if [ -d "$out/c" ] && [ "$(ls -A "$out/c" 2>/dev/null)" ]; then
        if [ $rc -eq 0 ]; then
            echo "  OK  ($log)"
            printf "%-40s OK\n"   "$patch" >> "$SUMMARY"
        else
            echo "  OK  (pd2gui warning, $log)"
            printf "%-40s OK (pd2gui warning)\n" "$patch" >> "$SUMMARY"
        fi
    else
        echo "  FAIL exit=$rc  ($log)"
        printf "%-40s FAIL exit=%d\n" "$patch" "$rc" >> "$SUMMARY"
        OVERALL=1
    fi
done

echo
echo "=== summary ==="
cat "$SUMMARY"
echo
echo "Logs in $OUT_DIR/*.log"
exit $OVERALL
