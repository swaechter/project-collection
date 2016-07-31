rmdir /Q /S ..\..\build
mkdir ..\..\build
cd ..\..\build
cmake .. -DCMAKE_BUILD_TYPE=Release
msbuild testapplication.sln /p:Configuration=Release
cd ..\package\windows_exe\
makensis /DMSVC-MSBUILD package.nsis
