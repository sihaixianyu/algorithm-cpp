#!/bin/sh

set -e

cmake -S . -B build \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_HOME/scripts/buildsystems/vcpkg.cmake"

cd build
make
