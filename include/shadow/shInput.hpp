#include <shadow.hpp>

namespace sh {namespace input
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

    //Used for keyboard and mouse detection
    typedef enum inputKey : unsigned short
    {
        KB_NULL = 0, //No Input
        KB_APOSTROPHE = 1,
        KB_COMMA = 2,
        KB_MINUS = 3,
        KB_PERIOD = 4,
        KB_SLASH = 5,
        KB_0 = 6,
        KB_1 = 7,
        KB_2 = 8,
        KB_3 = 9,
        KB_4 = 10,
        KB_5 = 11,
        KB_6 = 12,
        KB_7,
        KB_8,
        KB_9,
        KB_SEMICOLON,
        KB_EQUAL,
        KB_A,
        KB_B,
        KB_C,
        KB_D,
        KB_E,
        KB_F,
        KB_G,
        KB_H,
        KB_I,
        KB_J,
        KB_K,
        KB_L,
        KB_M,
        KB_N,
        KB_O,
        KB_P,
        KB_Q,
        KB_R,
        KB_S,
        KB_T,
        KB_U,
        KB_V,
        KB_W,
        KB_X,
        KB_Y,
        KB_Z,
        KB_LEFT_BRACKET,
        KB_BACKSLASH,
        KB_RIGHT_BRACKET,
        KB_GRAVE,
        //Keypad keys
        KB_KP_END,
        KB_KP_DOWN,
        KB_KP_PAGE_DOWN,
        KB_KP_LEFT,
        KB_KP_5,
        KB_KP_RIGHT,
        KB_KP_HOME,
        KB_KP_UP,
        KB_KP_PAGE_UP,
        KB_KP_DECIMAL,
        KB_KP_DIVIDE,
        KB_KP_MULTIPLY,
        KB_KP_SUBTRACT,
        KB_KP_ADD,
        KB_KP_ENTER,
        KB_KP_EQUAL,
        //Function Keys
        KB_SPACE,
        KB_ENTER,
        KB_TAB,
        KB_BACKSPACE,
        KB_INSERT,
        KB_DELETE,
        KB_RIGHT,
        KB_LEFT,
        KB_DOWN,
        KB_UP,
        KB_PAGE_UP,
        KB_PAGE_DOWN,
        KB_HOME,
        KB_END,
        KB_CAPS_LOCK,
        KB_SCROLL_LOCK,
        KB_PAUSE,
        KB_F1,
        KB_F2,
        KB_F3,
        KB_F4,
        KB_F5,
        KB_F6,
        KB_F7,
        KB_F8,
        KB_F9,
        KB_F10,
        KB_F11,
        KB_F12,
        KB_LEFT_SHIFT,
        KB_LEFT_ALT,
        KB_RIGHT_SHIFT,
        KB_RIGHT_ALT,
        //Mouse keys
        M_LEFT,
        M_RIGHT,
        M_MIDDLE,
        M_FORWARD,
        M_BACK,
        //Special Keys
        //These are ignored by check input and get input
        KB_NUM_LOCK,
        KB_PRINT_SCREEN,
        KB_ESCAPE,
        KB_LEFT_SUPER,
        KB_RIGHT_SUPER,
        KB_MENU_KEY,
        M_SIDE,
        M_EXTRA
    } inputKey;
    bool checkInput(inputKey key, inputType input);
    bool checkInput(KeyboardKey key, inputType input);
    bool checkInput(MouseButton key, inputType input);
    //Will return false if the requested gamepad is not available
    bool checkInput(GamepadButton key, int gamepad, inputType input);
    //Will return NaN if the requested gamepad is not available
    float checkInput(GamepadAxis key, int gamepad);
}}