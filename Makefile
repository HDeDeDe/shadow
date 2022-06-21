#Not Defined
WIN64MINGWLIBS = /c/msys64/mingw64/x86_64-w64-mingw32/lib
SHADOWNAME = Shadow
#Predefined
GCCWIN = g++
GCCMACOS = g++-11
TARGET = -o ./${SHADOWNAME}
SRC = ./src/*.cpp
CFLAGS = -fdiagnostics-color=always -std=c++17 -DSHADOWNAME='"'${SHADOWNAME}'"' -DDEBUGGING=
LIBFOLDER = -L./platform/
INCLUDE = -I./include/shadow -I./include/lua -I./include/raylib
SHADOWLIB = -llua54 -lraylib

Default:
	@echo "Please state which platform you would like to compile for by appending WIN64 or MACOS to the make command."

WIN64: 
	${GCCWIN} ${CFLAGS}1 -g ${SRC} ${LIBFOLDER}Win64 ${SHADOWLIB} -L${WIN64MINGWLIBS} -lopengl32 -lgdi32 -lwinmm ${INCLUDE} ${TARGET}Debug.exe

MACOS: 
	${GCCMACOS} ${CFLAGS}1 -g ${SRC} ${LIBFOLDER}MacOS ${SHADOWLIB} -framework IOKit -framework Cocoa -framework OpenGL ${INCLUDE} ${TARGET}Debug

WIN64RELEASE:
	${GCCWIN} ${CFLAGS}0 -s -mwindows ${SRC} ${LIBFOLDER}Win64 ${SHADOWLIB} -L${WIN64MINGWLIBS} -lopengl32 -lgdi32 -lwinmm ${INCLUDE} ${TARGET}.exe

MACOSRELEASE:
	${GCCMACOS} ${CFLAGS}0 ${SRC} ${LIBFOLDER}MacOS ${SHADOWLIB} -framework IOKit -framework Cocoa -framework OpenGL ${INCLUDE} ${TARGET}
	mkdir temp
	mkdir temp/Contents
	mkdir temp/Contents/MacOS
	cp -R Resources temp/Contents/Resources
	cp Info.plist temp/Contents/Info.plist
	mv Shadow temp/Contents/MacOS/Shadow
	rm -rf Shadow.app; mv temp Shadow.app
	
cleanWin:
	del ${SHADOWNAME}.exe
	
clean:
	rm -rf ${SHADOWNAME}.app