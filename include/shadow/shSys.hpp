#pragma once

#include <shDefinitions.hpp>

namespace shSys
{
    //Panic handlers
    void panic(sh::sh_Panic issue);
    bool isPanicing();

	//Initialize window manager
	void initAuditorium();
	//Initialize texture manager
	void initTextureMan();
	//Initialize model manager
	void initModelMan();
	//Clean up texture manager
	void cleanTextureMan();
}