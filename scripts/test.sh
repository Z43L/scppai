#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "Cleaning..."
make -C "$ROOT_DIR" clean

echo "Building..."
make -C "$ROOT_DIR"

echo "Running smoke test..."
"$ROOT_DIR/build/sc++" "var x = 1;"
