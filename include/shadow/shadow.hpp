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

//Shadow Library
namespace sh
{
    namespace auditorium
    {
        void createWindow();
        void closeWindow();
        void reloadWindow();
        void resizeWindow();
    }

    //Load into game
    namespace play
    {
        //Main loop
        void ShadowPlay();
    }
}