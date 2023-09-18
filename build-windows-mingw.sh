#!/bin/bash

if [[ -z "$RAYLIB_MINGW_PATH" ]]; then
    echo "You need to install raylib-mingw build (from official builds) and specify the path with RAYLIB_MINGW_PATH."
    echo "https://github.com/raysan5/raylib/releases/download/4.5.0/raylib-4.5.0_win64_mingw-w64.zip"
    echo

    echo "Error: RAYLIB_MINGW_PATH is not defined."
    echo "Terminating."
    exit
fi

rm -rf build
mkdir -p build
x86_64-w64-mingw32-gcc -mwindows -Wall -Wextra -ggdb -I$RAYLIB_MINGW_PATH/include -I./src -L$RAYLIB_MINGW_PATH/lib src/*.c -o build/cubebase -static -lraylib -lopengl32 -lgdi32 -lwinmm
cp -r resources/* build

echo "Done."
