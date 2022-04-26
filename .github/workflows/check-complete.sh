#!/bin/bash
set -e

if grep -q README.md; then
  echo "Replace all the _enter with your input"
  exit 1
fi
