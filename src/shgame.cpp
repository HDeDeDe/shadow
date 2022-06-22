// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shLua.hpp>
// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    sh::auditorium::viewport::sh_camera GlobalCamera;
    lua_State *L = luaL_newstate();

    if(sh::lua::LuaCheck(L, luaL_dofile(L, "./lua/initialize.lua")))
    {

    }
    else
    {
        shSys::panic(sh::sh_Panic::panic_init_fail);
    }
    while (sh::gameLoopActive)
    {
        if(sh::play::Exit())break;
        sh::auditorium::drawScreen(GlobalCamera);
    }
}