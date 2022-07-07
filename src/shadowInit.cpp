// ---------- Include ----------
#include <shInit.hpp>
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shFiles.hpp>
#include <luaDefault.c>
#include <shLua.hpp>
// ---------- Shadow ----------
void startApp()
{
	std::cout << "[SHADOW - INFO] Starting..." << std::endl;
	#if (__APPLE__ == 1 && DEBUGGING == 0)
	ChangeDirectory(GetApplicationDirectory());
	ChangeDirectory("../");
	#endif
	ChangeDirectory("./Resources");
	shSys::initAuditorium();
	loadSettings();
	sh::gameLoopActive = true;
	sh::play::ShadowStart();
	sh::auditorium::model::UnloadAll();
	shSys::cleanTextureMan();
	std::cout << "[SHADOW - INFO] Exiting..." << std::endl;
}


void loadSettings()
{
	//set temporary values
	int l_resX = 640;
	int l_resY = 480;
	std::string winName = "Shadow Engine Game";
	bool l_vsync = false;
	bool l_MSAA = false;
	bool l_fullscreen = false;
	bool l_borderless = false;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	//Load default values
	if(sh::lua::LuaCheck(L, luaL_dostring(L, lua_default_video)))
	{
		lua_getglobal(L, "Window");
		if(lua_istable(L, -1))
		{
			lua_pushstring(L, "x");
			lua_gettable(L, -2);
			l_resX = (int)lua_tonumber(L, -1);
			lua_pop(L, 1);

			lua_pushstring(L, "y");
			lua_gettable(L, -2);
			l_resY = (int)lua_tonumber(L, -1);
			lua_pop(L, 1);

			lua_pushstring(L, "vsync");
			lua_gettable(L, -2);
			l_vsync = lua_toboolean(L, -1);
			lua_pop(L, 1);

			lua_pushstring(L, "MSAA");
			lua_gettable(L, -2);
			l_MSAA = lua_toboolean(L, -1);
			lua_pop(L, 1);

			lua_pushstring(L, "fullscreen");
			lua_gettable(L, -2);
			l_fullscreen = lua_toboolean(L, -1);
			lua_pop(L, 1);

			lua_pushstring(L, "borderless");
			lua_gettable(L, -2);
			l_borderless = lua_toboolean(L, -1);
			lua_pop(L, 1);

			lua_pop(L, -1);
		}
		else{shSys::panic(sh::sh_Panic::panic_default_corrupted);}
	}
	else
	{
		shSys::panic(sh::sh_Panic::panic_default_corrupted);
	}
	const char* settings = "settings.ini";
	sh::file::settingsLoc = sh::file::getEnvironment();
	//Check for settings file depending on platform
	#if (_WIN64 == 1)
		sh::file::settingsLoc.append("\\." SHADOWNAME);
		sh::file::settingsFolder = sh::file::settingsLoc;
		sh::file::settingsLoc.append("\\");
		sh::file::settingsLoc.append(settings);
	#endif

	#if (__APPLE__ == 1)
		sh::file::settingsLoc.append("/." SHADOWNAME);
		sh::file::settingsFolder = sh::file::settingsLoc;
		sh::file::settingsLoc.append("/");
		sh::file::settingsLoc.append(settings);
	#endif

	#if (__gnu_linux__ == 1)

	#endif
	//if(!sh::lua::LuaCheck(L, lua_do(L, "./lua/inifile.lua"))) shSys::panic(sh::sh_Panic::panic_init_fail);

	if(FileExists(sh::file::settingsLoc.c_str()))
		{
			if(sh::lua::LuaCheck(L, luaL_dostring(L, lua_ini_load)))
			{
				lua_getglobal(L, "LoadSettings");
				if(lua_isfunction(L, -1))
				{
					lua_pushstring(L, sh::file::settingsLoc.c_str());
					if(sh::lua::LuaCheck(L, lua_pcall(L, 1, 0, 0)))
					{
						lua_pop(L, -1);
						lua_getglobal(L, "Window");
						if(lua_istable(L, -1))
						{
							lua_pushstring(L, "x");
							lua_gettable(L, -2);
							l_resX = (int)lua_tonumber(L, -1);
							lua_pop(L, 1);

							lua_pushstring(L, "y");
							lua_gettable(L, -2);
							l_resY = (int)lua_tonumber(L, -1);
							lua_pop(L, 1);

							lua_pushstring(L, "vsync");
							lua_gettable(L, -2);
							l_vsync = lua_toboolean(L, -1);
							lua_pop(L, 1);

							lua_pushstring(L, "MSAA");
							lua_gettable(L, -2);
							l_MSAA = lua_toboolean(L, -1);
							lua_pop(L, 1);

							lua_pushstring(L, "fullscreen");
							lua_gettable(L, -2);
							l_fullscreen = lua_toboolean(L, -1);
							lua_pop(L, 1);

							lua_pushstring(L, "borderless");
							lua_gettable(L, -2);
							l_borderless = lua_toboolean(L, -1);
							lua_pop(L, 1);
							std::cout << "[SHADOW - INFO] Settings file loaded." << std::endl;
						}
						else{std::cout << "[SHADOW - WARNING] The settings file is corrupt. Continuing with defaults." << std::endl;}
					}
					else{std::cout << "[SHADOW - WARNING] The settings file is corrupt. Continuing with defaults." << std::endl;}
				}
				
			}
			else{std::cout << "[SHADOW - WARNING] The settings file is corrupt. Continuing with defaults." << std::endl;}
		}
		else
		{
			std::cout << "[SHADOW - INFO] There is no settings file. Attempting to create one." << std::endl;
			std::cout << "[SHADOW - INFO] Checking for folder." << std::endl;
			if(DirectoryExists(sh::file::settingsFolder.c_str()));
			else {
				std::cout << "[SHADOW - INFO] Folder does not exist, creating." << std::endl;
				sh::file::createSettingsFolder(sh::file::settingsFolder.c_str());
			}
			if(sh::lua::LuaCheck(L, luaL_dostring(L, lua_ini_create)))
			{
				lua_getglobal(L, "CreateSettings");
				if(lua_isfunction(L, -1)) 
				{
					lua_pushstring(L, sh::file::settingsLoc.c_str());
					if(sh::lua::LuaCheck(L, lua_pcall(L, 1, 0, 0)))
					{
						std::cout << "[SHADOW - INFO] Settings file created successfully." << std::endl;
					}
					else { std::cout << "[SHADOW - INFO] Could not create settings file." << std::endl; sh::flags::noSave = true;}
				}
				else { std::cout << "[SHADOW - INFO] Could not create settings file." << std::endl; sh::flags::noSave = true;}
			}
			else { std::cout << "[SHADOW - INFO] Could not create settings file." << std::endl; sh::flags::noSave = true;}
		}
	
	lua_close(L);
	sh::auditorium::resizeWindow(l_resX, l_resY);
	sh::auditorium::renameWindow(winName.c_str());
	sh::auditorium::setVsync(l_vsync);
	sh::auditorium::setBorderless(l_borderless);
	sh::auditorium::setMSAA(l_MSAA);
	sh::auditorium::reloadWindow();
	sh::auditorium::setFullscreen(l_fullscreen);
}