--This file is called when the engine is started. Anything defined here can be called with GetGlobalLua()
--Be sure to put your moduels in lua/packages and invoke them with: local myPackage = require('lua/packages/myPackage')
local inifile = require('lua/packages/inifile')
--This is recomended so that you can access INI saving
TextToDisplay = "Hello World!"
PictureToLoad = "./Test.png"
ModelToLoad = "./Test.iqm"