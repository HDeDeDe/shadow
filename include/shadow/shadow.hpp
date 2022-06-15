#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unordered_map>
#include <shSys.hpp>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "raylib.h"
}

//Load into game
namespace shGame
{
    //Main loop
    void ShadowGame();
}