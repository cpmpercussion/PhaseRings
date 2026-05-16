#!/usr/bin/env bash
#
# Generate App Store screenshots for PhaseRings.
#
# Runs the PhaseRingsScreenshotTests UI tests against iPhone 17 and
# iPad Pro 11" (M5) simulators for both light and dark mode, then extracts
# the PNG attachments from each xcresult bundle into screenshots/.
#
# Usage: scripts/make_screenshots.sh [device ...]
#   With no args, runs all configured devices. Device names must match
#   xcodebuild's -destination "name=" values.

set -euo pipefail

cd "$(dirname "$0")/.."

WORKSPACE="PhaseRings.xcworkspace"
SCHEME="PhaseRings"
TEST_TARGET="PhaseRingsUITests/PhaseRingsScreenshotTests"
OUT_ROOT="screenshots"
TMP_ROOT="$(mktemp -d -t phaserings-screenshots.XXXXXX)"
trap 'rm -rf "$TMP_ROOT"' EXIT

DEVICES_DEFAULT=("iPad Pro 11-inch (M5)" "iPhone 17")
if [ "$#" -gt 0 ]; then
  DEVICES=("$@")
else
  DEVICES=("${DEVICES_DEFAULT[@]}")
fi

STYLES=("light" "dark")

mkdir -p "$OUT_ROOT"

run_one() {
  local device="$1"
  local style="$2"
  local slug
  # Lowercase, drop parens entirely, collapse spaces+dashes to a single dash,
  # and strip any leading/trailing dashes so the path stays tidy.
  slug=$(echo "$device" \
    | tr '[:upper:]' '[:lower:]' \
    | tr -d '()' \
    | tr ' ' '-' \
    | tr -s '-' \
    | sed 's/^-//;s/-$//')
  local result_bundle="$TMP_ROOT/${slug}-${style}.xcresult"
  local out_dir="$OUT_ROOT/${slug}/${style}"
  rm -rf "$result_bundle" "$out_dir"
  mkdir -p "$out_dir"

  local style_cap
  case "$style" in
    light) style_cap="Light" ;;
    dark)  style_cap="Dark" ;;
    *) echo "unknown style: $style" >&2; exit 2 ;;
  esac

  echo "==> $device / $style"
  xcodebuild test \
    -workspace "$WORKSPACE" \
    -scheme "$SCHEME" \
    -destination "platform=iOS Simulator,name=${device}" \
    -only-testing:"${TEST_TARGET}/testCapture${style_cap}Mode" \
    -resultBundlePath "$result_bundle" \
    ONLY_ACTIVE_ARCH=YES ARCHS=arm64 \
    -quiet

  # Pull all PNG attachments out of the result bundle.
  local export_dir="$TMP_ROOT/${slug}-${style}-export"
  xcrun xcresulttool export attachments \
    --path "$result_bundle" \
    --output-path "$export_dir"

  # xcresulttool names attachments with suffixed UUIDs; the manifest maps
  # them back to the XCTAttachment.name we set in the test. Grab the
  # screenshot attachments (PNGs whose preferred name starts with
  # "phaserings-").
  if [ -f "$export_dir/manifest.json" ]; then
    python3 - "$export_dir" "$out_dir" "$style" <<'PY'
import json, os, shutil, sys
export_dir, out_dir, style = sys.argv[1], sys.argv[2], sys.argv[3]
manifest = json.load(open(os.path.join(export_dir, "manifest.json")))
count = 0
for test in manifest:
    for att in test.get("attachments", []):
        name = att.get("suggestedHumanReadableName") or att.get("exportedFileName") or ""
        if not name.startswith("phaserings-"):
            continue
        src = os.path.join(export_dir, att["exportedFileName"])
        dst = os.path.join(out_dir, f"phaserings-{style}.png")
        shutil.copyfile(src, dst)
        count += 1
        print(f"   wrote {dst}")
if count == 0:
    print("   WARNING: no phaserings-* attachments found in manifest", file=sys.stderr)
    sys.exit(1)
PY
  else
    echo "   WARNING: no manifest.json in $export_dir" >&2
    exit 1
  fi
}

for device in "${DEVICES[@]}"; do
  for style in "${STYLES[@]}"; do
    run_one "$device" "$style"
  done
done

echo
echo "Done. Screenshots in $OUT_ROOT/"
find "$OUT_ROOT" -name '*.png' -print
