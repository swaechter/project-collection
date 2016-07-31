# Testapplication

## Introduction
The idea of testapplication is to give some basic (and required) knowledge to a new Qt or an existing C++ developer. This example is not complete nor does it show every feature of Qt5 or CMake. It is just a cookbook to develop and package a crosscompatible piece of software. As build system I use CMake and not QMake to make the build system as easy as possible and use features that QMake cannot provide. For background information about each toolchain component visit their website. If you encounter a problem or have a question feel free to send me an email.

## Installation
The installation guide is really basic to avoid problems and missunderstandings

### Linux Debian - gcc
* sudo apt-get install make cmake automoc qtbase5-dev qtbase5-dev-tools qt5-qmake qt5-default qttools5-dev qttools5-dev-tools doxygen dh-make devscripts
* Open a console and check for these commands: make cmake doxygen dh_make debuild
* For development you can use Qt Creator or KDevelop

### Mac OS X - clang
* Download and install Xcode
* Download and install Xcode command line tools
* Download and install the OS X version from http://qt-project.org/downloads
* Download and install CMake from http://www.cmake.org/
* Download and install doxygen from http://www.stack.nl/~dimitri/doxygen/download.html
* Open a console and check for these commands: make cmake doxygen
* For development you can use Qt Creator or Xcode

### Windows - MinGW
* Download and install the MinGW version from http://qt-project.org/downloads
* Add the C:\Qt\QtX.X\X.X\mingwY\bin directory to the PATH variable
* Add the C:\Qt\QtX.X\Tools\mingwY\bin directory to the PATH variable
* Download and install CMake from http://www.cmake.org/
* Add the bin directory to the PATH variable
* Download and install doxygen from http://www.stack.nl/~dimitri/doxygen/download.html
* Add the bin directory to the PATH variable
* Download and install NSIS from http://nsis.sourceforge.net/Main_Page
* Add the bin directory to the PATH variable
* Open a console and check for these commands: mingw32-make qmake cmake doxygen makensis
* For development you can use Qt Creator or Visual Studio

### Windows - MSVC
* Download and install the MSVC 2010+ version from http://qt-project.org/downloads
* Add the C:\Qt\QtX.X\msvcY\bin directory to the PATH variable
* Download and install CMake from http://www.cmake.org/
* Add the bin directory to the PATH variable
* Download and install doxygen from http://www.stack.nl/~dimitri/doxygen/download.html
* Add the bin directory to the PATH variable
* Download and install NSIS from http://nsis.sourceforge.net/Main_Page
* Add the bin directory to the PATH variable
* Open a MSVC developer console and check for these commands: msbuild qmake cmake doxygen makensis
* For development you can use Qt Creator or Visual Studio

## Building

### General
Do this on every  platform
* git clone http://github.com/swaechter/testapplication
* cd testapplication
* mkdir build
* cd build

### Linux - gcc
* cmake .. && make
* ./src/testapplication/testapplication

### Mac OS X - clang
* cmake .. -DCMAKE_PREFIX_PATH=/path_to_qt_root_dir/qt_root_dir/version/clang_64/lib/cmake/ && make
* Copy the dylib library src/sharedlibrary to src/testapplication
* ./src/testapplication/testapplication

### Windows - MinGW
* cmake .. -G"MinGW Makefiles" && mingw32-make
* Copy the library from src\sharedlibrary to src\testapplication 
* .\src\testapplication\testapplication.exe

### Windows - MSVC
* cmake .. && msbuild Project.sln
* Copy the library from src\sharedlibrary to src\testapplication
* .\src\testapplication\Debug\testapplication.exe

## Packaging
The following package systems are supported. For more information read the instructions.txt inside each directory:

* General: Pure make install
* Linux: DEB for Debian via debuild
* Linux: RPM for Fedora via rpmbuild
* Windows: EXE for Windows via NSIS

You can also use all Linux packages from the [Open Build Service](http://software.opensuse.org/download/package?project=home:swaechter&package=testapplication):

## Notes
There are a few notes
* Windows: Recompiling Qt with 'configure -developer-build -no-icu' and no webkit (delete both directories) will result in ~25 MB less library size for deployment

## Todos & Known problems
There are a few todos and known problems
* [Todo] Write a package installer for OS X
* [Problem] Windows: At the moment we do not link against a static version of the Microsoft Visual C++ runtime

## License & Donations
The testapplication package is licensed under the GNU GPL v3, the current author is Simon Wächter. Donations to the author are always welcome - how about order a beer from a beer gift store for Switzerland :)
