#pragma once
// ---------- Include ----------
#include <string>
#include <unordered_map>
#include <shSys.hpp>
// ---------- Include C----------
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "raylib.h"
}
// ---------- Shadow ----------
//Load into game
namespace shPlay
{
    //Main loop
    void ShadowPlay();
}

