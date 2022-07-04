@echo off
set arg1=%1
set arg2=%2
C:\msys64\mingw64\bin\mingw32-make.exe WIN64_RELEASE %arg1% %arg2%
