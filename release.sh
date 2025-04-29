#!/bin/bash

set -e

# Compiling for Linux
g++ -o main main.cpp

# Compiling for Windows
x86_64-w64-mingw32-g++ -o main.exe main.cpp

# Zipping the build
zip release.zip main main.exe libgcc_s_seh-1.dll libstdc++-6.dll LICENSE README.md dataset.txt
rm main main.exe

# Creating a GitHub release
gh release create $1 release.zip
