#!/bin/bash

set -e

# Compiling for Linux
g++ -o main -O3 -static main.cpp

# Compiling for Windows
x86_64-w64-mingw32-g++ -o main.exe -O3 -static main.cpp

# Zipping the build
zip release.zip main main.exe LICENSE README.md dataset.txt
rm main main.exe

# Creating a GitHub release
gh release create $1 release.zip
