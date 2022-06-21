#Not Defined
WIN64MINGWLIBS = /c/msys64/mingw64/x86_64-w64-mingw32/lib
SHADOWNAME = shadow
#Predefined
GCCWIN = g++
GCCMACOS = g++-11
TARGET = -o ./Shadow
SRC = ./src/*.cpp
CFLAGS = -fdiagnostics-color=always -std=c++17 -DSHADOWNAME='"'${SHADOWNAME}'"'
LIBFOLDER = -L./platform/
INCLUDE = -I./include/shadow -I./include/lua -I./include/raylib
SHADOWLIB = -llua54 -lraylib

Default:
	@echo "Please state which platform you would like to compile for by appending WIN64 or MACOS to the make command."

WIN64: 
	${GCCWIN} ${CFLAGS} -g ${SRC} ${LIBFOLDER}Win64 ${SHADOWLIB} -L${WIN64MINGWLIBS} -lopengl32 -lgdi32 -lwinmm ${INCLUDE} ${TARGET}Debug.exe

MACOS: 
	${GCCMACOS} ${CFLAGS} -g ${SRC} ${LIBFOLDER}MacOS ${SHADOWLIB} -framework IOKit -framework Cocoa -framework OpenGL ${INCLUDE} ${TARGET}Debug

WIN64RELEASE:
	${GCCWIN} ${CFLAGS} -s ${SRC} ${LIBFOLDER}Win64 ${SHADOWLIB} -L${WIN64MINGWLIBS} -lopengl32 -lgdi32 -lwinmm ${INCLUDE} ${TARGET}.exe

MACOSRELEASE:
	${GCCMACOS} ${CFLAGS} -s ${SRC} ${LIBFOLDER}MacOS ${SHADOWLIB} -framework IOKit -framework Cocoa -framework OpenGL ${INCLUDE} ${TARGET}