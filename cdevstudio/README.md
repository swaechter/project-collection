# CDevStudio

## Introduction
A C/C++ IDE based on Qt5. CDevStudio is cross compatible and runs under Linux, Unix, OS X and Windows. The functionality is given by a plugin system.

## Install build environment
Required
* Setup a C/C++ toolchain and add it to the system path. C++11 features are required
* Setup Qt5 and add it to the system path. Version 5.2.0 or higher is required
* Setup CMake and add it to the system path. Version 2.8.11 or higher is required

Optional
* Setup doxygen and add it to the system path

## Prepare CDevStudio
Download and prepare CDevStudio
* git clone https://github.com/swaechter/cdevstudio
* cd cdevstudio
* mkdir build
* cd build

For development switch to the develop branch. A typical Git workflow (master/develop/feature/bugfix) is used
* git checkout -b develop origin/develop

## Compile CDevStudio
Normal build
* cmake ..
* make
* ./src/cdevstudio/cdevstudio

## Packaging/Installing CDevStudio
The following package systems are supported. For more information read the instructions.txt in each package system directory
* Linux: Make for all distributions via a pure 'make install'
* Linux: DEB for Debian via debuild
* Linux: RPM for Fedora via rpmbuild
* Linux: TAR.XZ for Arch Linux via makepkg
* Windows: EXE for Windows Vista, 7 and 8 via NSIS

## Notes
Important notes
* The platform API is not binary compatible

## TODO

### Documentation

### Codebase

### Packages
* Unix: Create a package
* OS X: Create a package
* Windows: Improve the current package
