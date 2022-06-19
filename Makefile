#Not Defined
RAYLIB? = ballsToTheWall
WIN64MINGWLIBS? = 3AMFunny
#Predefined
GCCWIN = g++
GCCOSX = g++-11
TARGETOSX = -o ./Shadow
TARGETWIN64 = -o ./Shadow.exe
SRC = ./src/*.cpp
CFLAGS = -fdiagnostics-color=always -std=c++17 -g
LIBFOLDER = -L./platform/
INCLUDE = -I./include/shadow -I./include/lua
SHADOWLIB = -llua54 -lraylib

WIN64: 
	${GCCWIN} ${CFLAGS} ${SRC} ${LIBFOLDER}win64 ${SHADOWLIB} -L${WIN64MINGWLIBS} -lopengl32 -lgdi32 -lwinmm ${INCLUDE} -I${RAYLIB} ${TARGETWIN64}

OSX: 
	${GCCOSX} ${CFLAGS} ${SRC} ${LIBFOLDER}osx ${SHADOWLIB} -framework IOKit -framework Cocoa -framework OpenGL ${INCLUDE} -I${RAYLIB} ${TARGETOSX}
#	@echo "cd 'dirname $$0'\n./Shadow" > Shadow.command
