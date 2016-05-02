cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=MINSIZEREL
mingw32-make.exe
strip videoplayer.exe
strip VideoplayerProject_test.exe
strip videoplayer_settings.exe
