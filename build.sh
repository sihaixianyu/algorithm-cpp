#!/bin/sh

set -e

if [ $# -gt 0 ] && [ $1 -eq 1 ]; then
    rm -rf build
fi

cmake -S . -B build \
    -DCMAKE_CXX_COMPILER="$HOMEBREW_PREFIX/bin/clang++" \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_HOME/scripts/buildsystems/vcpkg.cmake" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cd build
make
