#!/bin/sh

set -e

rm -rf build

cmake -S . -B build \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_C_COMPILER="$HOMEBREW_PREFIX/bin/clang++" \
    -DCMAKE_CXX_COMPILER="$HOMEBREW_PREFIX/bin/clang++" \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_HOME/scripts/buildsystems/vcpkg.cmake"

cd build
make
