@echo off
set arg1=%1
set arg2=%2
set arg3=%3
mingw32-make.exe WIN64_RELEASE %arg1% %arg2% %arg3%
