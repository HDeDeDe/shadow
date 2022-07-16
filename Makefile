#You can change these
SHADOWNAME ?= Shadow
BUCKETSIZE ?= 4
INFRAMERATE ?= 60
#Predefined
GCC = g++
GCCWIN = g++
GCCMACOS = g++-12
TARGET = -o ./${SHADOWNAME}
SRC = ./src/*.cpp
USRSRC = ./user/src/*.cpp
DBGSRC = ./src_dear_imgui/*.cpp
CFLAGS = -fdiagnostics-color=always -std=c++23 -m64 -DSHADOWNAME='"'${SHADOWNAME}'"' -DINFRAMERATE=${INFRAMERATE} -DBUCKETSIZE=${BUCKETSIZE} -DDEBUGGING=
LIBFOLDER = -L./platform/
INCLUDE = -I./include/shadow -I./include/lua -I./include/raylib -I./user/headers
WIN64LIB = -lopengl32 -lgdi32 -lwinmm
LINUXLIB = -pthread -lGL -lm -ldl -lrt -lX11
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
	${GCCWIN} ${CFLAGS}0 -O2 -s -mwindows ${SRC} ${USRSRC} ${LIBFOLDER}Win64 ${SHADOWLIB} ${WIN64LIB} ${INCLUDE} ${TARGET}.exe

MACOS_RELEASE:
	${GCCMACOS} ${CFLAGS}0 -O2 ${SRC} ${USRSRC} ${LIBFOLDER}MacOS ${SHADOWLIB} ${MACOSFRAMEWORK} ${INCLUDE} ${TARGET}
	mkdir temp
	mkdir temp/Contents
	mkdir temp/Contents/MacOS
	cp -R Resources temp/Contents/Resources
	rm -rf temp/Contents/Resources/README
	rm -rf temp/Contents/Resources/imgui.ini
	cp Info.plist temp/Contents/Info.plist
	mv ${SHADOWNAME} temp/Contents/MacOS/${SHADOWNAME}
	rm -rf ${SHADOWNAME}.app; mv temp ${SHADOWNAME}.app

LINUX:
	${GCC} ${CFLAGS}1 -g ${SRC} -g ${USRSRC} -g ${DBGSRC} ${LINUXLIB} ${LIBFOLDER}Linux64 ${SHADOWLIB} ${INCLUDE} ${INCLUDEDBG} ${TARGET}Debug
	
LINUX_RELEASE:
	${GCC} ${CFLAGS}0 -O2 ${SRC} ${USRSRC} ${LINUXLIB} ${LIBFOLDER}Linux64 ${SHADOWLIB} ${INCLUDE} ${TARGET}