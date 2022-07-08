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
        //This is run every frame before the main game loop and actor updates.
        void GameLoopPriority();
        //This is run every frame
        void GameLoop();
        #if (DEBUGGING == 1)
        //This will only run if you are in debugging mode
        void ImguiDebugDraw();
        #endif
        //The last frame that was processed
        inline unsigned long previousInternalFrame = 0;
        //The difference between the current fixed frame and last fixed frame
        inline int frameDiff = 0;
    }
    namespace file
    {
        inline std::string settingsLoc = { 0 };
        inline std::string settingsFolder = { 0 };
    }
}