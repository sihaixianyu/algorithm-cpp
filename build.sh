#!/bin/sh

set -e

if [ $# -gt 0 ] && [ $1 = "-r" ]; then
    echo "[WARN] All previous build files will be removed!"
    rm -rf build
else
    echo "[ERROR] Invaild argument $1 has been passed in!"
    exit 1
fi

cmake -S . -B build \
    -DCMAKE_CXX_COMPILER="$HOMEBREW_PREFIX/bin/clang++" \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_HOME/scripts/buildsystems/vcpkg.cmake" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cd build

make -j 13
