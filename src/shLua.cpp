#include <shLua.hpp>
#include <shSys.hpp>

bool sh::lua::LuaCheck(lua_State *L, int r)
{
    if (r != LUA_OK)
    {
        std::string errormsg = lua_tostring(L, -1);
        std::cout << errormsg << std::endl;
        return false;
    }
    return true;
}

//Global lua machine
lua_State *LGlobal;
bool isInitialized = false;

void sh::lua::InitLuaGlobal()
{
    if(!isInitialized){
    LGlobal = luaL_newstate();
    luaL_openlibs(LGlobal);
    if(sh::lua::LuaCheck(LGlobal, luaL_dofile(LGlobal, "./lua/initialize.lua"))) isInitialized = true;
    else shSys::panic(sh::sh_Panic::panic_init_fail);
    }
    else std::cout << "[SHADOW - INFO] A global lua VM already exists." << std::endl;
}

void sh::lua::CloseLuaGlobal()
{
    lua_close(LGlobal);
}

lua_State* sh::lua::GetLuaGlobal()
{
    return LGlobal;
}