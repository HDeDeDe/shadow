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
    namespace input
    {
        typedef enum inputType : unsigned char
        {
            //Input has been pressed
            INPUT_PRESSED = 0,
            //Input is being pressed
            INPUT_DOWN,
            //Input has been released
            INPUT_RELEASE,
            //Input is not being pressed
            INPUT_UP
        } inputType;
        bool checkInput(KeyboardKey key, inputType input);
        bool checkInput(MouseButton key, inputType input);
        //Will return false if the requested gamepad is not available
        bool checkInput(GamepadButton key, int gamepad, inputType input);
        //Will return NaN if the requested gamepad is not available
        float checkInput(GamepadAxis key, int gamepad);
    }
}