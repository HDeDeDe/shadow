// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shLua.hpp>
#include <shInput.hpp>
#include <math.h>
// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    sh::lua::InitLuaGlobal();
    sh::play::GameInit();
    while (sh::gameLoopActive)
    {
        if(sh::play::Exit())break;
        sh::play::GameLoop();
        sh::auditorium::draw::drawScreen(sh::auditorium::viewport::GlobalCamera);
    }
    sh::lua::CloseLuaGlobal();
}



bool sh::input::checkInput(KeyboardKey key, inputType input)
{
    switch(input)
    {
        case INPUT_DOWN:
        {
            return IsKeyDown(key);
        }
        case INPUT_PRESSED:
        {
            return IsKeyPressed(key);
        }
        case INPUT_RELEASE:
        {
            return IsKeyReleased(key);
        }
        case INPUT_UP:
        {
            return IsKeyUp(key);
        }
        default: return false;
    }
}

bool sh::input::checkInput(MouseButton key, inputType input)
{
    switch(input)
    {
        case INPUT_DOWN:
        {
            return IsMouseButtonDown(key);
        }
        case INPUT_PRESSED:
        {
            return IsMouseButtonPressed(key);
        }
        case INPUT_RELEASE:
        {
            return IsMouseButtonReleased(key);
        }
        case INPUT_UP:
        {
            return IsMouseButtonUp(key);
        }
        default: return false;
    }
}

bool sh::input::checkInput(GamepadButton key, int gamepad, inputType input)
{
    if(IsGamepadAvailable(gamepad))
    {
        switch(input)
        {
            case INPUT_DOWN:
            {
                return IsGamepadButtonDown(gamepad, key);
            }
            case INPUT_PRESSED:
            {
                return IsGamepadButtonPressed(gamepad, key);
            }
            case INPUT_RELEASE:
            {
                return IsGamepadButtonReleased(gamepad, key);
            }
            case INPUT_UP:
            {
                return IsGamepadButtonUp(gamepad, key);
            }
            default: return false;
        }
    }
    return false;
}

float sh::input::checkInput(GamepadAxis key, int gamepad)
{
    if(IsGamepadAvailable(gamepad))
    {
        return GetGamepadAxisMovement(gamepad, key);
    }
    return NAN;
}

bool sh::input::checkInput(inputKey key, inputType input)
{
    return false;
}