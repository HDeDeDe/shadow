--This file is called when the engine is started. Anything defined here can be called with GetGlobalLua()
--Be sure to put your moduels in lua/packages and invoke them with: local myPackage = require('lua/packages/myPackage')
--Be aware that the default libraries are loaded with this file
local inifile = require('lua/packages/inifile')
-- ^ Required to access ini files 
local shadowinput = require('lua/packages/shadowinput')
-- ^ Required to save and load shadow input bindings
TextToDisplay = "Hello World!"
PictureToLoad = "./Test.png"
ModelToLoad = "./Test.iqm"
ExampleInput = shadowinput.StringToInput("MOUSE_1")
TextX = 40
TextY = 50
TextSize = 50