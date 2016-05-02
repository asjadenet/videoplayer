C:\msys64\usr\bin\unix2dos.exe --add-bom ..\executable\MainExecutable.cpp
cmake .. -DCMAKE_BUILD_TYPE=Release
msbuild VideoplayerProject.sln /p:Configuration=Release