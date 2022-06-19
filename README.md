# Shadow Engine
Shadow is a game engine built on lua 5.4.2 and raylib with the goal of being easy to use and easy to port. 

## Requirements
[Raylib 4.0.0](https://github.com/raysan5/raylib/releases/tag/4.0.0) (Get source code download)  
[VSCode](https://code.visualstudio.com/) (peferably)  
### Windows
[MSYS2](https://www.msys2.org/) (Need for make, gcc, and libraries)  
[git](https://git-scm.com/download/win) (Need for git)  
### MacOS
[Homebrew](https://brew.sh/) (Need for gcc)  
**Shadow will not support 32 bit systems**  
## Setup
### Windows
1. Install MSYS2. It will default to `C:\msys64`, if your copy is not installed there, be sure to remember where it is installed.
2. Add the following to your user environment variables (replace with location of install):
```
C:\msys64\mingw64\bin
```
3. Open a terminal and type `gcc --version`, if it says there is no command or file retry step 2.
4. If you have git, simply type:
```
git clone https://github.com/HDeDeDe/shadow
```
otherwise download the master as a zip and extract to a prefered location.
5. Download the Raylib 4.0.0 source and extract to a prefered known location.
### MacOS
**ONLY TESTED ON MONTERY**
1. Follow the instructions on [brew.sh](https://brew.sh/) to install homebrew, then make sure it is up to date
2. Install gcc with:
```
brew install gcc
```
3. Type `gcc-11` in a terminal, if you get an error retry step 2.
4. Type:
```
git clone https://github.com/HDeDeDe/shadow
```
in a prefered location, or download the master as zip.
5. Download the Raylib 4.0.0 source and extract to a prefered known location.

### Compilation
To compile a working executable, navigate to the root folder of the project and run:
```
make PLATFORM RAYLIB=/path/to/raylib/src
```
where `PLATFORM` is either `WIN64`, `MACOS`, or `LINUX`(eventually), and `/path/to/raylib/src` is the path to your copy of /raylib/src.  
If you are on windows, replace `make` with `C:\msys64\usr\bin\make.exe` or its equivalent path. If you do have a different install directory for MSYS2, append:
```
WIN64MINGWLIBS=/path/to/msys64/mingw64/x86_64-w64-mingw32/lib
```
to the above command.
## Setup VSCode
Install [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack), [Makefile Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.makefile-tools), and [Lua](https://marketplace.visualstudio.com/items?itemName=sumneko.lua).  
Clone the repository, then copy the files from .vscodeExample to .vscode and replace any instances of /path/to/ or platform with the apropriate values.
## Goals
Shadow will have the following features at minimum:  
- Window management (Auditorium)
- Texture management
- Model management
- Shader management
- Lua implementation
- Entity/Environment management (Stage Play)
- Data compression
- Steam integration
- Netcode (maybe, hoplefully, I really want to add this but have no clue how)
- VR (pipedream, not at all a priority)  
