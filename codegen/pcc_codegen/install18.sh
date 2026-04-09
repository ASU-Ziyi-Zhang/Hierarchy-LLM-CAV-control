#!/bin/sh

## Run cmake and install the built files to lib/
if [ -d build ]; then
    rm -r build
fi

if [ -d lib ]; then
    rm -r lib
fi

# Settings
BUILD_TYPE=Release # Debug, RelWithDebInfo, Release

# cmake
mkdir lib
mkdir build
cd build

cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE

cd ..

cmake --build build --config $BUILD_TYPE
cmake --install build --config $BUILD_TYPE

# Custom Install
mv ./build/libpcc_so.so ./lib/
mv ./build/libpcc_so.so.1 ./lib/
mv ./build/libpcc_so.so.1.0 ./lib/

## Run tests
sh ./test.sh

## Clean up build files
#rm -r build
