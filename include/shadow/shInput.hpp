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
    typedef enum inputKey : unsigned char
    {
        NULL_INPUT      = 0,    //No Input, will always return false
        KB_APOSTROPHE   = 1,    //Key: '
        KB_COMMA        = 2,    //Key: ,
        KB_MINUS        = 3,    //Key: -
        KB_PERIOD       = 4,    //Key: .
        KB_SLASH        = 5,    //Key: /
        KB_0            = 6,    //Key: 0
        KB_1            = 7,    //Key: 1
        KB_2            = 8,    //Key: 2
        KB_3            = 9,    //Key: 3
        KB_4            = 10,   //Key: 4
        KB_5            = 11,   //Key: 5
        KB_6            = 12,   //Key: 6
        KB_7            = 13,   //Key: 7
        KB_8            = 14,   //Key: 8
        KB_9            = 15,   //Key: 9
        KB_SEMICOLON    = 16,   //Key: ;
        KB_EQUAL        = 17,   //Key: =
        KB_A            = 18,   //Key: a
        KB_B            = 19,   //Key: b
        KB_C            = 20,   //Key: c
        KB_D            = 21,   //Key: d
        KB_E            = 22,   //Key: e
        KB_F            = 23,   //Key: f
        KB_G            = 24,   //Key: g
        KB_H            = 25,   //Key: h
        KB_I            = 26,   //Key: i
        KB_J            = 27,   //Key: j
        KB_K            = 28,   //Key: k
        KB_L            = 29,   //Key: l
        KB_M            = 30,   //Key: m
        KB_N            = 31,   //Key: n
        KB_O            = 32,   //Key: o
        KB_P            = 33,   //Key: p
        KB_Q            = 34,   //Key: q
        KB_R            = 35,   //Key: r
        KB_S            = 36,   //Key: s
        KB_T            = 37,   //Key: y
        KB_U            = 38,   //Key: u
        KB_V            = 39,   //Key: v
        KB_W            = 40,   //Key: w
        KB_X            = 41,   //Key: x
        KB_Y            = 42,   //Key: y
        KB_Z            = 43,   //Key: z
        KB_LEFT_BRACKET = 44,   //Key: [
        KB_BACKSLASH    = 45,   //Key: '\'
        KB_RIGHT_BRACKET= 46,   //Key: ]
        KB_GRAVE        = 47,   //Key: `
        //Keypad keys
        KB_KP_INSERT    = 110,  //Key: Keypad 0
        KB_KP_END       = 48,   //Key: Keypad 1
        KB_KP_DOWN      = 49,   //Key: Keypad 2
        KB_KP_PAGE_DOWN = 50,   //Key: Keypad 3
        KB_KP_LEFT      = 51,   //Key: Keypad 4
        KB_KP_5         = 52,   //Key: Keypad 5
        KB_KP_RIGHT     = 53,   //Key: Keypad 6
        KB_KP_HOME      = 54,   //Key: Keypad 7
        KB_KP_UP        = 55,   //Key: Keypad 8
        KB_KP_PAGE_UP   = 56,   //Key: Keypad 9
        KB_KP_DELETE    = 57,   //Key: Keypad .
        KB_KP_DIVIDE    = 58,   //Key: Keypad /
        KB_KP_MULTIPLY  = 59,   //Key: Keypad *
        KB_KP_SUBTRACT  = 60,   //Key: Keypad -
        KB_KP_ADD       = 61,   //Key: Keypad +
        KB_KP_ENTER     = 62,   //Key: Keypad Enter
        KB_KP_EQUAL     = 63,   //Key: Keypad = (maybe)
        //Function Keys 
        KB_SPACE        = 64,   //Key: Space
        KB_ENTER        = 65,   //Key: Enter / Return
        KB_TAB          = 66,   //Key: Tab
        KB_BACKSPACE    = 67,   //Key: Bakcspace
        KB_INSERT       = 68,   //Key: Insert
        KB_DELETE       = 69,   //Key: Delete
        KB_RIGHT        = 70,   //Key: Right Arrow
        KB_LEFT         = 71,   //Key: Left Arrow
        KB_DOWN         = 72,   //Key: Down Arrow
        KB_UP           = 73,   //Key: Up Arrow
        KB_PAGE_UP      = 74,   //Key: Page up
        KB_PAGE_DOWN    = 75,   //Key: Page Down
        KB_HOME         = 76,   //Key: Home
        KB_END          = 77,   //Key: End
        KB_CAPS_LOCK    = 78,   //Key: Caps
        KB_SCROLL_LOCK  = 79,   //Key: Scroll Lock
        KB_PAUSE        = 80,   //Key: Pause / Break
        KB_F1           = 81,   //Key: F1
        KB_F2           = 82,   //Key: F2
        KB_F3           = 83,   //Key: F3
        KB_F4           = 84,   //Key: F4
        KB_F5           = 85,   //Key: F5
        KB_F6           = 86,   //Key: F6
        KB_F7           = 87,   //Key: F7
        KB_F8           = 88,   //Key: F8
        KB_F9           = 89,   //Key: F9
        KB_F10          = 90,   //Key: F10
        KB_F11          = 91,   //Key: F11
        KB_F12          = 92,   //Key: F12
        KB_LEFT_SHIFT   = 93,   //Key: Left Shift
        KB_LEFT_ALT     = 94,   //Key: Left Alt
        KB_RIGHT_SHIFT  = 95,   //Key: Right Shift
        KB_RIGHT_ALT    = 96,   //Key: Right Alt
        KB_MENU_KEY     = 107,  //Key: Menu button
        //Mouse buttons
        MOUSE_1         = 97,   //Key: Left
        MOUSE_2         = 98,   //Key: Right
        MOUSE_3         = 99,   //Key: Middle
        MOUSE_4         = 100,  //Key: Forward
        MOUSE_5         = 101,  //Key: Back
        //Special Keys
        //These are ignored by check input and get input
        KB_NUM_LOCK     = 102,  //Key: Num Lock
        KB_PRINT_SCREEN = 103,  //Key: Print Screen
        KB_ESCAPE       = 104,  //Key: Escape
        KB_LEFT_SUPER   = 105,  //Key: IDK
        KB_RIGHT_SUPER  = 106,  //Key: IDK
        MOUSE_SIDE      = 108,  //Key: IDK
        MOUSE_EXTRA     = 109   //Key: IDK
    } inputKey;
    bool checkInput(inputKey key, inputType input);
    bool checkInput(KeyboardKey key, inputType input);
    bool checkInput(MouseButton key, inputType input);
    //Will return false if the requested gamepad is not available
    bool checkInput(GamepadButton key, int gamepad, inputType input);
    //Will return NaN if the requested gamepad is not available
    float checkInput(GamepadAxis key, int gamepad);
}}