#Not Defined
WIN64MINGWLIBS = /c/msys64/mingw64/x86_64-w64-mingw32/lib
#Predefined
GCCWIN = g++
GCCMACOS = g++-11
TARGETMACOS = -o ./Shadow
TARGETWIN64 = -o ./Shadow.exe
SRC = ./src/*.cpp
CFLAGS = -fdiagnostics-color=always -std=c++17 -g
LIBFOLDER = -L./platform/
INCLUDE = -I./include/shadow -I./include/lua -I./include/raylib
SHADOWLIB = -llua54 -lraylib

WIN64: 
	${GCCWIN} ${CFLAGS} ${SRC} ${LIBFOLDER}Win64 ${SHADOWLIB} -L${WIN64MINGWLIBS} -lopengl32 -lgdi32 -lwinmm ${INCLUDE} ${TARGETWIN64}

MACOS: 
	${GCCMACOS} ${CFLAGS} ${SRC} ${LIBFOLDER}MacOS ${SHADOWLIB} -framework IOKit -framework Cocoa -framework OpenGL ${INCLUDE} ${TARGETMACOS}
#	@echo "cd 'dirname $$0'\n./Shadow" > Shadow.command
