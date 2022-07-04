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
        bool Exit();
        void Exit(bool killApp);
        //This is run after the global lua virtual machine is initialized, but before the game loops
        void GameInit();
        //This is run every frame
        void GameLoop();
        #if (DEBUGGING == 1)
        //This will only run if you are in debugging mode
        void ImguiDebugDraw();
        #endif
    }
}