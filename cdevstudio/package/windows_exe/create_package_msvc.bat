if not exist "..\..\build" mkdir "..\..\build"
cd ..\..\build
cmake .. -DCMAKE_BUILD_TYPE=Release
msbuild cdevstudio-workspace.sln /p:Configuration=Release
cd ..\package\windows_exe
makensis /DMSVC-MSBUILD cdevstudio.nsis
