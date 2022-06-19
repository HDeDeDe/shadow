#Not Defined
RAYLIB = check
#Predefined
GCCWIN = g++
GCCOSX = g++-11
TARGETOSX = -o ./Shadow
TARGETWIN32 = -o ./Shadow.exe
SRC = ./src
CFLAGS = -fdiagnostics-color=always -std=c++17
OSXLIB = -L./platform/osx
RM = rm -rf
INCLUDE = -I./include/shadow -I./include/lua
SHADOWLIB = -llua54 -lraylib

WIN32:
	${GCCWIN} 

OSX:
	${GCCOSX} ${CFLAGS} -g ${SRC}/*.cpp ${OSXLIB} ${SHADOWLIB} -framework IOKit -framework Cocoa -framework OpenGL ${INCLUDE} -I${RAYLIB} ${TARGETOSX}
#	@echo "cd 'dirname $$0'\n./Shadow" > Shadow.command
