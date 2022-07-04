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
    bool checkInput(KeyboardKey key, inputType input);
    bool checkInput(MouseButton key, inputType input);
    //Will return false if the requested gamepad is not available
    bool checkInput(GamepadButton key, int gamepad, inputType input);
    //Will return NaN if the requested gamepad is not available
    float checkInput(GamepadAxis key, int gamepad);
}}