--This file is called when the engine is started. Anything defined here can be called with GetGlobalLua()
--Be sure to put your moduels in lua/packages and invoke them with: local myPackage = require('lua/packages/myPackage')
--Be aware that the default libraries are loaded with this file
local inifile = require('lua/packages/inifile')
-- ^ Required to access ini files 
TextToDisplay = "Hello World!"
PictureToLoad = "./Test.png"
ModelToLoad = "./Test.iqm"