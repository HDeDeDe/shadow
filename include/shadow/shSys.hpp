#pragma once
#include <stdlib.h>
#include <iostream>

namespace shSys
{
    //used for fatal error handling
	typedef enum class sh_Panic : unsigned char
	{
		//Unknown issue
		panic_unknown = 0,
		//A texture was destroyed while loaded in video memory
		panic_loaded_texture,
		//A manual crash was initiated
		panic_manual
	} sh_Panic;

    //Panic handlers
    void panic(sh_Panic issue);
    bool isPanicing();

	//Initialize window manager
	void initAuditorium();
}