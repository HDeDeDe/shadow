// ---------- Include ----------
#include <shInit.hpp>
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shFiles.hpp>
#include <luaDefault.c>
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

	if (FileExists("./Test.bin")) sh::auditorium::wrkDir = "Success";
	else sh::auditorium::wrkDir = "Failed";
	
	sh::play::ShadowStart();
	shSys::cleanTextureMan();
	std::cout << "[SHADOW - INFO] Exiting..." << std::endl;
}



bool LuaCheck(lua_State *L, int r)
{
	if (r!= LUA_OK)
	{
		std::string errormsg = lua_tostring(L, -1);
		std::cout << errormsg << std::endl;
		return false;
	}
	return true;
}

void loadSettings()
{
	//set temporary values
	int l_resX = 360;
	int l_resY = 240;
	std::string winName = "Super Vergil";
	bool l_vsync = false;
	bool l_MSAA = false;
	lua_State *L = luaL_newstate();
	//Load default values
	if(LuaCheck(L, luaL_dostring(L, lua_default_video)))
	{
		lua_getglobal(L, "window");
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
		}
		else{shSys::panic(sh::sh_Panic::panic_default_corrupted);}
	}
	else
	{
		shSys::panic(sh::sh_Panic::panic_default_corrupted);
	}
	//Check for settings file depending on platform
	#if (_WIN64 == 1)
		std::string settingsLoc = sh::file::getAppdata();
		settingsLoc.append("\\." SHADOWNAME);
		std::string settingsFolder = settingsLoc;
		settingsLoc.append("\\settings.lua");
		if(FileExists(settingsLoc.c_str()))
		{
			if(LuaCheck(L, luaL_dofile(L, settingsLoc.c_str())))
			{
				lua_getglobal(L, "window");
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
					std::cout << "[SHADOW - INFO] Settings file loaded." << std::endl;
				}
				else{std::cout << "[SHADOW - WARNING] The settings file is corrupt. Continuing with defaults." << std::endl;}
			}
			else{std::cout << "[SHADOW - WARNING] The settings file is corrupt. Continuing with defaults." << std::endl;}
		}
		else
		{
			std::cout << "[SHADOW - INFO] There is no settings file. Attempting to create one." << std::endl;
			std::cout << "[SHADOW - INFO] Checking for folder." << std::endl;
			if(DirectoryExists(settingsFolder.c_str()));
			else {
				std::cout << "[SHADOW - INFO] Folder does not exist, creating." << std::endl;
				sh::file::createSettingsFolder(settingsFolder.c_str());
			}
			if(SaveFileText(settingsLoc.c_str(), settingsFile))
			{
				std::cout << "[SHADOW - INFO] Settings file created successfully." << std::endl;
			}
			else std::cout << "[SHADOW - INFO] Could not create settings file." << std::endl;
		}
	#endif

	#if (__APPLE__ == 1)
		std::string settingsLoc = sh::file::getHome();
		settingsLoc.append("/." SHADOWNAME);
		std::string settingsFolder = settingsLoc;
		settingsLoc.append("/settings.lua");
		if(FileExists(settingsLoc.c_str()))
		{
			if(LuaCheck(L, luaL_dofile(L, settingsLoc.c_str())))
			{
				lua_getglobal(L, "window");
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
					std::cout << "[SHADOW - INFO] Settings file loaded." << std::endl;
				}
				else{std::cout << "[SHADOW - WARNING] The settings file is corrupt. Continuing with defaults." << std::endl;}
			}
			else{std::cout << "[SHADOW - WARNING] The settings file is corrupt. Continuing with defaults." << std::endl;}
		}
		else
		{
			std::cout << "[SHADOW - INFO] There is no settings file. Attempting to create one." << std::endl;
			std::cout << "[SHADOW - INFO] Checking for folder." << std::endl;
			if(DirectoryExists(settingsFolder.c_str()));
			else {
				std::cout << "[SHADOW - INFO] Folder does not exist, creating." << std::endl;
				sh::file::createSettingsFolder(settingsFolder.c_str());
			}
			if(SaveFileText(settingsLoc.c_str(), settingsFile))
			{
				std::cout << "[SHADOW - INFO] Settings file created successfully." << std::endl;
			}
			else std::cout << "[SHADOW - INFO] Could not create settings file." << std::endl;
		}
	#endif

	#if (__gnu_linux__ == 1)

	#endif
	
	lua_close(L);
	sh::auditorium::resizeWindow(l_resX, l_resY);
	sh::auditorium::renameWindow(winName.c_str());
	sh::auditorium::setVsync(l_vsync);
	sh::auditorium::setMSAA(l_MSAA);
}