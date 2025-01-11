#!/bin/bash

set -e

if [ $# -gt 0 ] && [ $1 = "-r" ]; then
    echo "[WARN] All previous build files will be removed!"
    rm -rf build
fi

cmake -S . -B build \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_CXX_COMPILER="clang++" \
    -DCMAKE_TOOLCHAIN_FILE="${VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake" \

cmake --build build --parallel 7
