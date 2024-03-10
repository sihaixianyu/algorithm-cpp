#!/bin/sh

set -e

rm -rf build

cmake -S . -B build \
    -G Ninja \
    -DCMAKE_CXX_COMPILER="$HOMEBREW_PREFIX/bin/clang++" \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_HOME/scripts/buildsystems/vcpkg.cmake" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cd build
ninja -v
