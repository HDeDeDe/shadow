#pragma once
#include <shadow.hpp>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

namespace sh{namespace lua{
    bool LuaCheck(lua_State *L, int r);
    void InitLuaGlobal();
    void CloseLuaGlobal();
}}