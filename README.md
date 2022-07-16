# Shadow Engine
Shadow is a game engine built on [lua 5.4.2](https://sourceforge.net/projects/luabinaries/files/5.4.2/), [raylib 4.0.0](https://github.com/raysan5/raylib/releases/tag/4.0.0), and [Dear imgui 1.88](https://github.com/ocornut/imgui/releases/tag/v1.88) with the goal of being easy to use and easy to port. 

## Requirements
[VSCode](https://code.visualstudio.com/) (peferably)  
### Windows
[MSYS2](https://www.msys2.org/) (Need for make and gcc)  
[git](https://git-scm.com/download/win) (Need for git)  
### MacOS
[Homebrew](https://brew.sh/) (Need for gcc)  
[XCode](https://developer.apple.com/xcode/) (need for debuging)  
**Shadow will not support 32 bit systems**  
## Setup
### Windows
1. Install MSYS2. It will default to `C:\msys64`, if your copy is not installed there, be sure to remember where it is installed.
2. Open MSYS2 and make sure to run the following commands:  
```
pacman -Syyu
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-gdb
pacman -S mingw-w64-x86_64-gdb-multiarch
pacman -S mingw-w64-x86_64-make
```
ensure that the packages and their dependencies are up to date
3. Add the following to your user environment variables (replace with location of install if necessary):
```
C:\msys64\mingw64\bin
```
4. Open a terminal and type `gcc --version`, if it says there is no command or file retry step 2.
5. If you have git, simply type:
```
git clone https://github.com/HDeDeDe/shadow
```
in a prefered location, otherwise download the master as zip.
### MacOS
**ONLY TESTED ON MONTERY**
1. Follow the instructions on [brew.sh](https://brew.sh/) to install homebrew, then make sure it is up to date
2. Install gcc with:
```
brew install gcc@12
```
3. Type `gcc-12` in a terminal, if you get an error retry step 2.
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
  
If you do have a different install directory for MSYS2 on windows run `make` from its absolute path instead.  
**Warning:** Debugging on MacOS may require you to codesign a copy of gdb.  
**Warning:** Dear imgui will not be rendered in HighDPI mode on MacOS.  
## Setup VSCode
Install [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack), [Native Debug](https://marketplace.visualstudio.com/items?itemName=webfreak.debug) and [Lua](https://marketplace.visualstudio.com/items?itemName=sumneko.lua).  
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
  
### Notes
`SHADOWNAME` Controls the name of the application, which defines where the settings file is located and the name of the resulting executable.  
`BUCKETSIZE` Controls the number of layers the engine has access to. More layers means more time to render so be sure not to set this value too high.  
`INFRAMERATE` Controls how often the global timer increments. This affects fixed delta time.  
  
### A note for linux support
The Linux binary was compiled on Arch Linux running under wsl. The specific steps I took are as follows:  
1. Download [ArchWSL](https://github.com/yuk7/ArchWSL/releases/tag/22.3.18.0) as an appx.
2. Install Arch but do not update any packages or set up user accounts
3. Replace the entire included mirrorlist file with 
```
Server = https://steamdeck-packages.steamos.cloud/archlinux-mirror/$repo/os/$arch
```
4. Run `pacman -Syy`, `pacman -Syu`, `pacman -S gcc`, `pacman -S xorg` (install all), and `pacman -S make`  
  
Binaries compiled with this setup should be compatible with SteamOS 3.0. I don't plan on supporting any other configuration at this time.
