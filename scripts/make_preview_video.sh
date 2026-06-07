#!/usr/bin/env bash
#
# Record an App Store preview video for PhaseRings.
#
# Boots a simulator with the canonical status bar (9:41, full battery), runs
# the PhaseRingsPreviewVideoTests choreography (taps, a swirl, taps over the
# top) while capturing the screen with `simctl io recordVideo`, then trims the
# launch/teardown dead time and scales the result to App Store Connect's
# accepted preview size for the device class. ASC previews must be 15-30 s,
# <=30 fps, H.264 — a silent stereo AAC track is added since simctl captures
# no audio (record on a hardware device if the preview should carry sound).
#
# Usage: scripts/make_preview_video.sh [device]
#   Default device: iPad Pro 13-inch (M5).
#
# Output: screenshots/preview/<slug>-preview.mp4 (plus the raw .mov alongside).

set -euo pipefail

cd "$(dirname "$0")/.."

PROJECT="PhaseRings.xcodeproj"
SCHEME="PhaseRings"
TEST="PhaseRingsUITests/PhaseRingsPreviewVideoTests/testPreviewChoreography"
DEVICE="${1:-iPad Pro 13-inch (M5)}"
OUT_ROOT="screenshots/preview"
TMP_ROOT="$(mktemp -d -t phaserings-preview.XXXXXX)"
trap 'rm -rf "$TMP_ROOT"' EXIT

mkdir -p "$OUT_ROOT"

slug=$(echo "$DEVICE" \
  | tr '[:upper:]' '[:lower:]' | tr -d '()' | tr ' ' '-' | tr -s '-' \
  | sed 's/^-//;s/-$//')

# ASC-accepted preview dimensions per device class (portrait).
case "$slug" in
  iphone-*)           TARGET_W=886;  TARGET_H=1920 ;;  # 6.5" iPhone
  ipad-pro-13-inch-*) TARGET_W=1200; TARGET_H=1600 ;;  # 12.9"/13" iPad Pro
  *) echo "no preview dimensions configured for '$slug'" >&2; exit 2 ;;
esac

udid=$(xcrun simctl list -j devices available | python3 -c '
import json, sys
name = sys.argv[1]
data = json.load(sys.stdin)
for devices in data["devices"].values():
    for dev in devices:
        if dev["name"] == name:
            print(dev["udid"]); raise SystemExit
raise SystemExit(f"no available simulator named {name!r}")
' "$DEVICE")

echo "==> $DEVICE ($udid)"
xcrun simctl boot "$udid" 2>/dev/null || true
xcrun simctl bootstatus "$udid" -b >/dev/null
xcrun simctl status_bar "$udid" override \
  --time "9:41" \
  --batteryState charged --batteryLevel 100 \
  --wifiBars 3 --cellularBars 4 --dataNetwork wifi

# Build first so the recording only spans the test run, not compilation.
echo "==> build-for-testing"
xcodebuild build-for-testing \
  -project "$PROJECT" -scheme "$SCHEME" \
  -destination "id=$udid" \
  ONLY_ACTIVE_ARCH=YES ARCHS=arm64 -quiet

raw="$OUT_ROOT/${slug}-raw.mov"
out="$OUT_ROOT/${slug}-preview.mp4"
rm -f "$raw" "$out"

echo "==> recording choreography"
# Clear any recorder a previous (aborted) run left attached to this sim —
# CoreSimulator allows one host recording at a time.
if pkill -INT -f "simctl io $udid recordVideo" 2>/dev/null; then
  echo "   stopped a stale recorder from a previous run"
  sleep 2
fi
xcrun simctl io "$udid" recordVideo --codec h264 --force "$raw" &
rec_pid=$!
sleep 2

# Don't let a failed test abort the script before the recorder is stopped —
# an unfinalized .mov is corrupt and unplayable.
test_status=0
xcodebuild test-without-building \
  -project "$PROJECT" -scheme "$SCHEME" \
  -destination "id=$udid" \
  -only-testing:"$TEST" \
  ONLY_ACTIVE_ARCH=YES ARCHS=arm64 -quiet || test_status=$?

kill -INT "$rec_pid"
wait "$rec_pid" || true

if [ "$test_status" -ne 0 ]; then
  echo "choreography test failed (exit $test_status); raw recording kept at $raw" >&2
  exit "$test_status"
fi

# Trim: anchor on the end of the recording, which is a fixed, known offset
# from the choreography (the recorder is stopped right after xcodebuild
# exits). Drop the teardown tail (app dismissal) and keep the preceding
# CLIP_LEN seconds, which skips the variable-length launch dead time at the
# start. Tune TAIL_TRIM if springboard frames appear at the end.
CLIP_LEN=23
TAIL_TRIM=2.0
duration=$(ffprobe -v error -show_entries format=duration -of csv=p=0 "$raw")
start=$(python3 -c "print(max(0, $duration - $TAIL_TRIM - $CLIP_LEN))")

echo "==> encoding ${TARGET_W}x${TARGET_H} (raw ${duration%s}s, start ${start}s, ${CLIP_LEN}s clip)"
ffmpeg -v error -y \
  -ss "$start" -t "$CLIP_LEN" -i "$raw" \
  -f lavfi -t "$CLIP_LEN" -i anullsrc=channel_layout=stereo:sample_rate=44100 \
  -vf "scale=${TARGET_W}:${TARGET_H}:flags=lanczos,fps=30" \
  -c:v libx264 -profile:v high -pix_fmt yuv420p -crf 18 \
  -c:a aac -b:a 128k -shortest \
  "$out"

echo
echo "Done:"
ffprobe -v error -show_entries format=duration -of csv=p=0 "$out" | xargs -I{} echo "  $out ({}s, ${TARGET_W}x${TARGET_H})"
