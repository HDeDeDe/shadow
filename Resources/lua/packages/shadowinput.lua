local shadowinput = {
    _VERSION = "Shadow Input 1.0",
    _DESCRIPTION = "Converts Shadow Engine input values to their respective strings and vice versa.",
    _URL = "https://github.com/HDeDeDe/shadow"
}

local inputTable = {
    [1]  = "KB_APOSTROPHE",
    [2]  = "KB_COMMA",
    [3]  = "KB_MINUS",
    [4]  = "KB_PERIOD",
    [5]  = "KB_SLASH",
    [6]  = "KB_0",
    [7]  = "KB_1",
    [8]  = "KB_2",
    [9]  = "KB_3",
    [10] = "KB_4",
    [11] = "KB_5",
    [12] = "KB_6",
    [13] = "KB_7",
    [14] = "KB_8",
    [15] = "KB_9",
    [16] = "KB_SEMICOLON",
    [17] = "KB_EQUAL",
    [18] = "KB_A",
    [19] = "KB_B",
    [20] = "KB_C",
    [21] = "KB_D",
    [22] = "KB_E",
    [23] = "KB_F",
    [24] = "KB_G",
    [25] = "KB_H",
    [26] = "KB_I",
    [27] = "KB_J",
    [28] = "KB_K",
    [29] = "KB_L",
    [30] = "KB_M",
    [31] = "KB_N",
    [32] = "KB_O",
    [33] = "KB_P",
    [34] = "KB_Q",
    [35] = "KB_R",
    [36] = "KB_S",
    [37] = "KB_T",
    [38] = "KB_U",
    [39] = "KB_V",
    [40] = "KB_W",
    [41] = "KB_X",
    [42] = "KB_Y",
    [43] = "KB_Z",
    [44] = "KB_LEFT_BRACKET",
    [45] = "KB_BACKSLASH",
    [46] = "KB_RIGHT_BRACKET",
    [47] = "KB_GRAVE",
    [110]= "KB_KP_INSERT",
    [48] = "KB_KP_END",
    [49] = "KB_KP_DOWN",
    [50] = "KB_KP_PAGE_DOWN",
    [51] = "KB_KP_LEFT",
    [52] = "KB_KP_5",
    [53] = "KB_KP_RIGHT",
    [54] = "KB_KP_HOME",
    [55] = "KB_KP_UP",
    [56] = "KB_KP_PAGE_UP",
    [57] = "KB_KP_DELETE",
    [58] = "KB_KP_DIVIDE",
    [59] = "KB_KP_MULTIPLY",
    [60] = "KB_KP_SUBTRACT",
    [61] = "KB_KP_ADD",
    [62] = "KB_KP_ENTER",
    [63] = "KB_KP_EQUAL",
    [64] = "KB_SPACE",
    [65] = "KB_ENTER",
    [66] = "KB_TAB",
    [67] = "KB_BACKSPACE",
    [68] = "KB_INSERT",
    [69] = "KB_DELETE",
    [70] = "KB_RIGHT",
    [71] = "KB_LEFT",
    [72] = "KB_DOWN",
    [73] = "KB_UP",
    [74] = "KB_PAGE_UP",
    [75] = "KB_PAGE_DOWN",
    [76] = "KB_HOME",
    [77] = "KB_END",
    [78] = "KB_CAPS_LOCK",
    [79] = "KB_SCROLL_LOCK",
    [80] = "KB_PAUSE",
    [81] = "KB_F1",
    [82] = "KB_F2",
    [83] = "KB_F3",
    [84] = "KB_F4",
    [85] = "KB_F5",
    [86] = "KB_F6",
    [87] = "KB_F7",
    [88] = "KB_F8",
    [89] = "KB_F9",
    [90] = "KB_F10",
    [91] = "KB_F11",
    [92] = "KB_F12",
    [93] = "KB_LEFT_SHIFT",
    [94] = "KB_LEFT_ALT",
    [95] = "KB_RIGHT_SHIFT",
    [96] = "KB_RIGHT_ALT",
    [107]= "KB_MENU_KEY",
    [97] = "MOUSE_1",
    [98] = "MOUSE_2",
    [99] = "MOUSE_3",
    [100]= "MOUSE_4",
    [101]= "MOUSE_5",
    [111]= "MOUSE_WHEEL_UP",
    [112]= "MOUSE_WHEEL_DOWN"
}

function shadowinput.InputToString(InputNum)
    if (inputTable[InputNum] == nil) then
        return "NULL_INPUT"
    end
    return inputTable[InputNum]
end

function shadowinput.StringToInput(InputString)
    for keys, values in pairs(inputTable) do
        if (InputString == values) then
            return keys
        end
    end
    return 0
end

return shadowinput