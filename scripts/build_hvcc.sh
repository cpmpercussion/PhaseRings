#!/usr/bin/env bash
# Generate Heavy C++ from each top-level Pd environment patch into the iOS
# project tree. Output is committed (treated as vendored sources) so the app
# builds without requiring hvcc on every machine. Regenerate after editing
# any .pd file under PhaseRingSynth/.
#
# Layout produced:
#   PhaseRings/Heavy/shared/                  -- Heavy runtime (one copy)
#   PhaseRings/Heavy/Heavy_PhaseRing/         -- patch-specific .cpp/.h/.hpp only
#   PhaseRings/Heavy/Heavy_CircleStrings/
#   PhaseRings/Heavy/Heavy_SoundScraper/
#
# Why split? Each `hvcc` run emits the full runtime alongside the
# patch-specific Heavy_<Name>.cpp; the runtime files are byte-identical across
# contexts (with SoundScraper adding HvControlPrint / HvSignalSamphold).
# Linking all three trees would produce hundreds of duplicate symbols, so we
# consolidate runtime files into PhaseRings/Heavy/shared/ (taking the union
# across contexts) and keep only the per-context entry points beside it.
#
# See hvcc-migration-plan.md (Step 1) for context.

set -uo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
VENV_DIR="$REPO_ROOT/.venv-hvcc"
HVCC="$VENV_DIR/bin/hvcc"
SYNTH_DIR="$REPO_ROOT/PhaseRingSynth"
OUT_ROOT="$REPO_ROOT/PhaseRings/Heavy"
TMP_ROOT="$OUT_ROOT/.tmp"

if [ ! -x "$HVCC" ]; then
    echo "hvcc not found at $HVCC -- run scripts/install_hvcc.sh first" >&2
    exit 1
fi

# patch.pd  =>  context base name. hvcc prefixes "Heavy_" to the name passed
# via -n when it emits sources, so passing PhaseRing yields Heavy_PhaseRing.cpp.
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

# Wipe previous output. We rebuild from scratch every time so removed files
# don't linger.
rm -rf "$OUT_ROOT"
mkdir -p "$OUT_ROOT/shared" "$TMP_ROOT"

OVERALL=0
for entry in "${PATCHES[@]}"; do
    patch="${entry%%:*}"
    name="${entry##*:}"
    tmp="$TMP_ROOT/Heavy_$name"

    echo "=== $patch -> Heavy_$name ==="
    rm -rf "$tmp"
    mkdir -p "$tmp"

    "$HVCC" \
        "$SYNTH_DIR/$patch" \
        -n "$name" \
        -g cpp \
        -o "$tmp" \
        "${SEARCH_PATHS[@]}"
    rc=$?

    if [ $rc -ne 0 ]; then
        echo "  FAIL exit=$rc"
        OVERALL=1
        continue
    fi

    ctx_out="$OUT_ROOT/Heavy_$name"
    mkdir -p "$ctx_out"

    # Sort generated files into shared runtime vs. patch-specific entry point.
    # Patch-specific files are exactly Heavy_<Name>.{cpp,h,hpp}.
    for f in "$tmp/c"/*; do
        base="$(basename "$f")"
        case "$base" in
            Heavy_"$name".cpp|Heavy_"$name".h|Heavy_"$name".hpp)
                mv "$f" "$ctx_out/$base"
                ;;
            *)
                # Runtime file. Only copy if shared doesn't have it yet, and
                # sanity-check that any existing copy is byte-identical to
                # the new one (catches divergence between contexts early).
                dst="$OUT_ROOT/shared/$base"
                if [ -e "$dst" ]; then
                    if ! cmp -s "$f" "$dst"; then
                        echo "  ERROR: $base differs between contexts" >&2
                        OVERALL=1
                    fi
                else
                    mv "$f" "$dst"
                fi
                ;;
        esac
    done
done

rm -rf "$TMP_ROOT"

if [ $OVERALL -eq 0 ]; then
    shared_count=$(find "$OUT_ROOT/shared" -type f | wc -l | tr -d ' ')
    echo
    echo "Heavy C++ generated under $OUT_ROOT"
    echo "  shared/: $shared_count files (one compiled copy of the runtime)"
    for entry in "${PATCHES[@]}"; do
        name="${entry##*:}"
        n=$(find "$OUT_ROOT/Heavy_$name" -type f | wc -l | tr -d ' ')
        echo "  Heavy_$name/: $n files (patch entry only)"
    done
    echo
    echo "Commit the changes to vendor the generated sources."
fi
exit $OVERALL
