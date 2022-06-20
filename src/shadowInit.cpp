// ---------- Include ----------
#include <shInit.hpp>
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <luaDefault.c>
// ---------- Shadow ----------
void startApp()
{
	std::cout << "[SHADOW - INFO] Starting..." << std::endl;
	shSys::initAuditorium();
	loadSettings();
	sh::gameLoopActive = true;
	sh::play::ShadowStart();
	shSys::cleanTextureMan();
	std::cout << "[SHADOW - INFO] Exiting..." << std::endl;
}

void loadSettings()
{
	lua_State *L = luaL_newstate();

	int r = luaL_dostring(L, lua_default_video);

	if(r == LUA_OK)
	{
		int l_resX = 360;
		int l_resY = 240;
		std::string l_winName = { 0 };
		bool l_vsync = false;
		bool l_MSAA = false;
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

			lua_pushstring(L, "name");
			lua_gettable(L, -2);
			l_winName = lua_tostring(L, -1);
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
		sh::auditorium::resizeWindow(l_resX, l_resY);
		sh::auditorium::renameWindow(l_winName.c_str());
		sh::auditorium::setVsync(l_vsync);
		sh::auditorium::setMSAA(l_MSAA);
	}
	else
	{
		std::string errormsg = lua_tostring(L, -1);
		std::cout << errormsg << std::endl;
		shSys::panic(sh::sh_Panic::panic_default_corrupted);
	}

	lua_close(L);
}