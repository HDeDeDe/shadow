// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shLua.hpp>
#include <shInput.hpp>
#include <math.h>
// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    float frameTime = 0.0f;
    sh::lua::InitLuaGlobal();
    sh::play::GameInit();
    while (sh::gameLoopActive)
    {
        frameDiff = 0;
        if(sh::play::Exit())break;
        while(previousInternalFrame != sh::globalTimer)
        {
            previousInternalFrame++;
            frameDiff++;
        }
        frameTime += GetFrameTime();
        while(frameTime > fixedDeltaTime)
        {
            sh::globalTimer++;
            frameTime -= fixedDeltaTime;
        }
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
    switch (key)//This is a really bad way of doing this
    {
    //Regular Keys
    case KB_APOSTROPHE:     return checkInput(KEY_APOSTROPHE, input);
    case KB_COMMA:          return checkInput(KEY_COMMA, input);
    case KB_MINUS:          return checkInput(KEY_MINUS, input);
    case KB_PERIOD:         return checkInput(KEY_PERIOD, input);
    case KB_SLASH:          return checkInput(KEY_SLASH, input);
    case KB_0:              return checkInput(KEY_ZERO, input);
    case KB_1:              return checkInput(KEY_ONE, input);
    case KB_2:              return checkInput(KEY_TWO, input);
    case KB_3:              return checkInput(KEY_THREE, input);
    case KB_4:              return checkInput(KEY_FOUR, input);
    case KB_5:              return checkInput(KEY_FIVE, input);
    case KB_6:              return checkInput(KEY_SIX, input);
    case KB_7:              return checkInput(KEY_SEVEN, input);
    case KB_8:              return checkInput(KEY_EIGHT, input);
    case KB_9:              return checkInput(KEY_NINE, input);
    case KB_SEMICOLON:      return checkInput(KEY_SEMICOLON, input);
    case KB_EQUAL:          return checkInput(KEY_EQUAL, input);
    case KB_A:              return checkInput(KEY_A, input);
    case KB_B:              return checkInput(KEY_B, input);
    case KB_C:              return checkInput(KEY_C, input);
    case KB_D:              return checkInput(KEY_D, input);
    case KB_E:              return checkInput(KEY_E, input);
    case KB_F:              return checkInput(KEY_F, input);
    case KB_G:              return checkInput(KEY_G, input);
    case KB_H:              return checkInput(KEY_H, input);
    case KB_I:              return checkInput(KEY_I, input);
    case KB_J:              return checkInput(KEY_J, input);
    case KB_K:              return checkInput(KEY_K, input);
    case KB_L:              return checkInput(KEY_L, input);
    case KB_M:              return checkInput(KEY_M, input);
    case KB_N:              return checkInput(KEY_N, input);
    case KB_O:              return checkInput(KEY_O, input);
    case KB_P:              return checkInput(KEY_P, input);
    case KB_Q:              return checkInput(KEY_Q, input);
    case KB_R:              return checkInput(KEY_R, input);
    case KB_S:              return checkInput(KEY_S, input);
    case KB_T:              return checkInput(KEY_T, input);
    case KB_U:              return checkInput(KEY_U, input);
    case KB_V:              return checkInput(KEY_V, input);
    case KB_W:              return checkInput(KEY_W, input);
    case KB_X:              return checkInput(KEY_X, input);
    case KB_Y:              return checkInput(KEY_Y, input);
    case KB_Z:              return checkInput(KEY_Z, input);
    case KB_LEFT_BRACKET:   return checkInput(KEY_LEFT_BRACKET, input);
    case KB_BACKSLASH:      return checkInput(KEY_BACKSLASH, input);
    case KB_RIGHT_BRACKET:  return checkInput(KEY_RIGHT_BRACKET, input);
    case KB_GRAVE:          return checkInput(KEY_GRAVE, input);
    //Keypad Keys
    case KB_KP_INSERT:      return checkInput(KEY_KP_0, input);
    case KB_KP_END:         return checkInput(KEY_KP_1, input);
    case KB_KP_DOWN:        return checkInput(KEY_KP_2, input);
    case KB_KP_PAGE_DOWN:   return checkInput(KEY_KP_3, input);
    case KB_KP_LEFT:        return checkInput(KEY_KP_4, input);
    case KB_KP_5:           return checkInput(KEY_KP_5, input);
    case KB_KP_RIGHT:       return checkInput(KEY_KP_6, input);
    case KB_KP_HOME:        return checkInput(KEY_KP_7, input);
    case KB_KP_UP:          return checkInput(KEY_KP_8, input);
    case KB_KP_PAGE_UP:     return checkInput(KEY_KP_9, input);
    case KB_KP_DELETE:      return checkInput(KEY_KP_DECIMAL, input);
    case KB_KP_DIVIDE:      return checkInput(KEY_KP_DIVIDE, input);
    case KB_KP_MULTIPLY:    return checkInput(KEY_KP_MULTIPLY, input);
    case KB_KP_SUBTRACT:    return checkInput(KEY_KP_SUBTRACT, input);
    case KB_KP_ADD:         return checkInput(KEY_KP_ADD, input);
    case KB_KP_ENTER:       return checkInput(KEY_KP_ENTER, input);
    case KB_KP_EQUAL:       return checkInput(KEY_KP_EQUAL, input);
    //Function keys
    case KB_SPACE:          return checkInput(KEY_SPACE, input);
    case KB_ENTER:          return checkInput(KEY_ENTER, input);
    case KB_TAB:            return checkInput(KEY_TAB, input);
    case KB_BACKSPACE:      return checkInput(KEY_BACKSPACE, input);
    case KB_INSERT:         return checkInput(KEY_INSERT, input);
    case KB_DELETE:         return checkInput(KEY_DELETE, input);
    case KB_RIGHT:          return checkInput(KEY_RIGHT, input);
    case KB_LEFT:           return checkInput(KEY_LEFT, input);
    case KB_UP:             return checkInput(KEY_UP, input);
    case KB_DOWN:           return checkInput(KEY_DOWN, input);
    case KB_PAGE_UP:        return checkInput(KEY_PAGE_UP, input);
    case KB_PAGE_DOWN:      return checkInput(KEY_PAGE_DOWN, input);
    case KB_HOME:           return checkInput(KEY_HOME, input);
    case KB_END:            return checkInput(KEY_END, input);
    case KB_CAPS_LOCK:      return checkInput(KEY_CAPS_LOCK, input);
    case KB_SCROLL_LOCK:    return checkInput(KEY_SCROLL_LOCK, input);
    case KB_PAUSE:          return checkInput(KEY_PAUSE, input);
    case KB_F1:             return checkInput(KEY_F1, input);
    case KB_F2:             return checkInput(KEY_F2, input);
    case KB_F3:             return checkInput(KEY_F3, input);
    case KB_F4:             return checkInput(KEY_F4, input);
    case KB_F5:             return checkInput(KEY_F5, input);
    case KB_F6:             return checkInput(KEY_F6, input);
    case KB_F7:             return checkInput(KEY_F7, input);
    case KB_F8:             return checkInput(KEY_F8, input);
    case KB_F9:             return checkInput(KEY_F9, input);
    case KB_F10:            return checkInput(KEY_F10, input);
    case KB_F11:            return checkInput(KEY_F11, input);
    case KB_F12:            return checkInput(KEY_F12, input);
    case KB_LEFT_SHIFT:     return checkInput(KEY_LEFT_SHIFT, input);
    case KB_LEFT_ALT:       return checkInput(KEY_LEFT_ALT, input);
    case KB_RIGHT_SHIFT:    return checkInput(KEY_RIGHT_SHIFT, input);
    case KB_RIGHT_ALT:      return checkInput(KEY_RIGHT_ALT, input);
    case KB_MENU_KEY:       return checkInput(KEY_KB_MENU, input);
    //Mouse buttons
    case MOUSE_1:           return checkInput(MOUSE_BUTTON_LEFT, input);
    case MOUSE_2:           return checkInput(MOUSE_BUTTON_RIGHT, input);
    case MOUSE_3:           return checkInput(MOUSE_BUTTON_MIDDLE, input);
    case MOUSE_4:           return checkInput(MOUSE_BUTTON_BACK, input);
    case MOUSE_5:           return checkInput(MOUSE_BUTTON_FORWARD, input);
    case MOUSE_WHEEL_UP:    
        if(GetMouseWheelMove() > 0.0f) return true; 
        break;
    case MOUSE_WHEEL_DOWN:    
        if(GetMouseWheelMove() < 0.0f) return true; 
        break;
    //Special keys, null, and invalid keys
    default:                break;
    }
    return false;
}

bool sh::input::checkInputSpecial(inputKey key, inputType input)
{
    switch(key)
    {
    case KB_NUM_LOCK:       return checkInput(KEY_NUM_LOCK, input);
    case KB_PRINT_SCREEN:   return checkInput(KEY_PRINT_SCREEN, input);
    case KB_ESCAPE:         return checkInput(KEY_ESCAPE, input);
    case KB_LEFT_SUPER:     return checkInput(KEY_LEFT_SUPER, input);
    case KB_RIGHT_SUPER:    return checkInput(KEY_RIGHT_SUPER, input);
    case MOUSE_SIDE:        return checkInput(MOUSE_BUTTON_SIDE, input);
    case MOUSE_EXTRA:       return checkInput(MOUSE_BUTTON_EXTRA, input);
    default:                return false;
    }
}

sh::input::inputKey sh::input::getInput()
{
    switch(GetKeyPressed())
    {
        //Regular Keys
        case KEY_APOSTROPHE:    return KB_APOSTROPHE;
        case KEY_COMMA:         return KB_COMMA;
        case KEY_MINUS:         return KB_MINUS;
        case KEY_PERIOD:        return KB_PERIOD;
        case KEY_SLASH:         return KB_SLASH;
        case KEY_ZERO:          return KB_0;
        case KEY_ONE:           return KB_1;
        case KEY_TWO:           return KB_2;
        case KEY_THREE:         return KB_3;
        case KEY_FOUR:          return KB_4;
        case KEY_FIVE:          return KB_5;
        case KEY_SIX:           return KB_6;
        case KEY_SEVEN:         return KB_7;
        case KEY_EIGHT:         return KB_8;
        case KEY_NINE:          return KB_9;
        case KEY_SEMICOLON:     return KB_SEMICOLON;
        case KEY_EQUAL:         return KB_EQUAL;
        case KEY_A:             return KB_A;
        case KEY_B:             return KB_B;
        case KEY_C:             return KB_C;
        case KEY_D:             return KB_D;
        case KEY_E:             return KB_E;
        case KEY_F:             return KB_F;
        case KEY_G:             return KB_G;
        case KEY_H:             return KB_H;
        case KEY_I:             return KB_I;
        case KEY_J:             return KB_J;
        case KEY_K:             return KB_K;
        case KEY_L:             return KB_L;
        case KEY_M:             return KB_M;
        case KEY_N:             return KB_N;
        case KEY_O:             return KB_O;
        case KEY_P:             return KB_P;
        case KEY_Q:             return KB_Q;
        case KEY_R:             return KB_R;
        case KEY_S:             return KB_S;
        case KEY_T:             return KB_T;
        case KEY_U:             return KB_U;
        case KEY_V:             return KB_V;
        case KEY_W:             return KB_W;
        case KEY_X:             return KB_X;
        case KEY_Y:             return KB_Y;
        case KEY_Z:             return KB_Z;
        case KEY_LEFT_BRACKET:  return KB_LEFT_BRACKET;
        case KEY_BACKSLASH:     return KB_BACKSLASH;
        case KEY_RIGHT_BRACKET: return KB_RIGHT_BRACKET;
        case KEY_GRAVE:         return KB_GRAVE;
        //Keypad Keys
        case KEY_KP_0:          return KB_KP_INSERT;
        case KEY_KP_1:          return KB_KP_END;
        case KEY_KP_2:          return KB_KP_DOWN;
        case KEY_KP_3:          return KB_KP_PAGE_DOWN;
        case KEY_KP_4:          return KB_KP_LEFT;
        case KEY_KP_5:          return KB_KP_5;
        case KEY_KP_6:          return KB_KP_RIGHT;
        case KEY_KP_7:          return KB_KP_HOME;
        case KEY_KP_8:          return KB_KP_UP;
        case KEY_KP_9:          return KB_KP_PAGE_UP;
        case KEY_KP_DECIMAL:    return KB_KP_DELETE;
        case KEY_KP_DIVIDE:     return KB_KP_DIVIDE;
        case KEY_KP_MULTIPLY:   return KB_KP_MULTIPLY;
        case KEY_KP_SUBTRACT:   return KB_KP_SUBTRACT;
        case KEY_KP_ADD:        return KB_KP_ADD;
        case KEY_KP_ENTER:      return KB_KP_ENTER;
        case KEY_KP_EQUAL:      return KB_KP_EQUAL;
        //Function keys
        case KEY_SPACE:         return KB_SPACE;
        case KEY_ENTER:         return KB_ENTER;
        case KEY_TAB:           return KB_TAB;
        case KEY_BACKSPACE:     return KB_BACKSPACE;
        case KEY_INSERT:        return KB_INSERT;
        case KEY_DELETE:        return KB_DELETE;
        case KEY_RIGHT:         return KB_RIGHT;
        case KEY_LEFT:          return KB_LEFT;
        case KEY_UP:            return KB_UP;
        case KEY_DOWN:          return KB_DOWN;
        case KEY_PAGE_UP:       return KB_PAGE_UP;
        case KEY_PAGE_DOWN:     return KB_PAGE_DOWN;
        case KEY_HOME:          return KB_HOME;
        case KEY_END:           return KB_END;
        case KEY_CAPS_LOCK:     return KB_CAPS_LOCK;
        case KEY_SCROLL_LOCK:   return KB_SCROLL_LOCK;
        case KEY_PAUSE:         return KB_PAUSE;
        case KEY_F1:            return KB_F1;
        case KEY_F2:            return KB_F2;
        case KEY_F3:            return KB_F3;
        case KEY_F4:            return KB_F4;
        case KEY_F5:            return KB_F5;
        case KEY_F6:            return KB_F6;
        case KEY_F7:            return KB_F7;
        case KEY_F8:            return KB_F8;
        case KEY_F9:            return KB_F9;
        case KEY_F10:           return KB_F10;
        case KEY_F11:           return KB_F11;
        case KEY_F12:           return KB_F12;
        case KEY_LEFT_SHIFT:    return KB_LEFT_SHIFT;
        case KEY_LEFT_ALT:      return KB_LEFT_ALT;
        case KEY_RIGHT_SHIFT:   return KB_RIGHT_SHIFT;
        case KEY_RIGHT_ALT:     return KB_RIGHT_ALT;
        case KEY_KB_MENU:       return KB_MENU_KEY;
        //Special keys, null, and invalid keys
        default: break;
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) return MOUSE_1;
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) return MOUSE_2;
    if(IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) return MOUSE_3;
    if(IsMouseButtonPressed(MOUSE_BUTTON_BACK)) return MOUSE_4;
    if(IsMouseButtonPressed(MOUSE_BUTTON_FORWARD)) return MOUSE_5;
    if(GetMouseWheelMove() > 0.0f) return MOUSE_WHEEL_UP;
    if(GetMouseWheelMove() < 0.0f) return MOUSE_WHEEL_DOWN;
    return NULL_INPUT;
}