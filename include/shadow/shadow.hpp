#pragma once
// ---------- Include ----------
#include <string>
#include <unordered_map>
#include <stdlib.h>
#include <iostream>

// ---------- Include C----------
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "raylib.h"
}
// ---------- Shadow ----------
#include <shDefinitions.hpp>

//Shadow Library
namespace sh
{
    //Load into game
    namespace play
    {
        //Main loop
        void ShadowStart();
        //Exit the game
        bool Exit(bool killApp = false);
        //Do not loop this code
        //void ShadowGameLoop();
    }
}