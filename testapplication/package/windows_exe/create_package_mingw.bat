rmdir /Q /S ..\..\build
mkdir ..\..\build
cd ..\..\build
cmake .. -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
mingw32-make
cd ..\package\windows_exe\
makensis /DMINGW-MAKE package.nsis
