# Shadow Engine
Shadow is a game engine built on lua 5.4.2, raylib 4.0.0, and Dear imgui 1.87 with the goal of being easy to use and easy to port. 

## Requirements
[VSCode](https://code.visualstudio.com/) (peferably)  
### Windows
[MSYS2](https://www.msys2.org/) (Need for make, gcc, and libraries)  
[git](https://git-scm.com/download/win) (Need for git)  
### MacOS
[Homebrew](https://brew.sh/) (Need for gcc)  
[XCode](https://developer.apple.com/xcode/) (need for debuging)  
**Shadow will not support 32 bit systems**  
## Setup
### Windows
1. Install MSYS2. It will default to `C:\msys64`, if your copy is not installed there, be sure to remember where it is installed.
2. Add the following to your user environment variables (replace with location of install if necessary):
```
C:\msys64\mingw64\bin
```
3. Open a terminal and type `gcc --version`, if it says there is no command or file retry step 2.
4. If you have git, simply type:
```
git clone https://github.com/HDeDeDe/shadow
```
otherwise download the master as a zip and extract to a prefered location.  
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

### Compilation
To compile a working executable, navigate to the root folder of the project and run:
```
make PLATFORM
```
where `PLATFORM` is either `WIN64`, `MACOS`, or `LINUX`(eventually). 
  
To compile a release version of your executable, navigate to the root folder of the project and run:
```
make PLATFORM_RELEASE
```
where `PLATFORM` is either `WIN64`, `MACOS`, or `LINUX`(eventually). 
  
If you do have a different install directory for MSYS2 on windows, append:
```
WIN64MINGWLIBS=/drive_letter_lowercase/path/to/msys64/mingw64/x86_64-w64-mingw32/lib
```
to the above command and run `make` from its absolute path instead.  
  
**Warning:** Debugging on MacOS may require you to codesign a copy of gdb.  
**Warning:** Dear imgui will not be rendered in HighDPI mode on MacOS.
## Setup VSCode
Install [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) and [Lua](https://marketplace.visualstudio.com/items?itemName=sumneko.lua).  
Clone the repository, then open and select your os.
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
