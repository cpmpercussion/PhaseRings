#!/usr/bin/env bash
# Install hvcc (Heavy Compiler Collection) into a local Python venv.
#
# hvcc compiles Pure Data patches to self-contained C/C++ classes. We use it
# here only for compatibility checking against the patches under
# PhaseRingSynth/ -- the v3.0 AUv3 work tracked in issue #20.
#
# Output: .venv-hvcc/ at the repo root. Activate with:
#   source .venv-hvcc/bin/activate
# or just call .venv-hvcc/bin/hvcc directly (which is what
# check_hvcc_compat.sh does).

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
VENV_DIR="$REPO_ROOT/.venv-hvcc"
HVCC_VERSION="${HVCC_VERSION:-0.15.0}"

if [ ! -d "$VENV_DIR" ]; then
    echo "Creating venv at $VENV_DIR"
    python3 -m venv "$VENV_DIR"
fi

# shellcheck disable=SC1091
source "$VENV_DIR/bin/activate"

python -m pip install --upgrade pip >/dev/null
python -m pip install "hvcc==$HVCC_VERSION"

echo
echo "hvcc installed:"
hvcc --version || hvcc -h | head -5
echo
echo "Venv: $VENV_DIR"
echo "Run compatibility check with: scripts/check_hvcc_compat.sh"
