#Not Defined
WIN64MINGWLIBS = /c/msys64/mingw64/x86_64-w64-mingw32/lib
SHADOWNAME = Shadow
#Predefined
GCCWIN = g++
GCCMACOS = g++-11
TARGET = -o ./${SHADOWNAME}
SRC = ./src/*.cpp
USRSRC = ./src_user/*.cpp
DBGSRC = ./src_dear_imgui/*.cpp
CFLAGS = -fdiagnostics-color=always -std=c++17 -DSHADOWNAME='"'${SHADOWNAME}'"' -DDEBUGGING=
LIBFOLDER = -L./platform/
INCLUDE = -I./include/shadow -I./include/lua -I./include/raylib
WIN64LIB = -lopengl32 -lgdi32 -lwinmm
INCLUDEDBG = -I./include/dear_imgui
SHADOWLIB = -llua54 -lraylib
MACOSFRAMEWORK = -framework IOKit -framework Cocoa -framework OpenGL

Default:
	@echo "Please state which platform you would like to compile for by appending WIN64 or MACOS to the make command."

WIN64: 
	${GCCWIN} ${CFLAGS}1 -g ${SRC} -g ${USRSRC} -g ${DBGSRC} ${LIBFOLDER}Win64 ${SHADOWLIB} ${WIN64LIB} ${INCLUDE} ${INCLUDEDBG} ${TARGET}Debug.exe

MACOS: 
	${GCCMACOS} ${CFLAGS}1 -g ${SRC} -g ${USRSRC} -g ${DBGSRC} ${LIBFOLDER}MacOS ${SHADOWLIB} ${MACOSFRAMEWORK} ${INCLUDE} ${INCLUDEDBG} ${TARGET}Debug

WIN64_RELEASE:
	${GCCWIN} ${CFLAGS}0 -s -mwindows ${SRC} ${USRSRC} ${LIBFOLDER}Win64 ${SHADOWLIB} ${WIN64LIB} ${INCLUDE} ${TARGET}.exe

MACOS_RELEASE:
	${GCCMACOS} ${CFLAGS}0 ${SRC} ${USRSRC} ${LIBFOLDER}MacOS ${SHADOWLIB} ${MACOSFRAMEWORK} ${INCLUDE} ${TARGET}
	mkdir temp
	mkdir temp/Contents
	mkdir temp/Contents/MacOS
	cp -R Resources temp/Contents/Resources
	cp Info.plist temp/Contents/Info.plist
	mv ${SHADOWNAME} temp/Contents/MacOS/${SHADOWNAME}
	rm -rf ${SHADOWNAME}.app; mv temp ${SHADOWNAME}.app
