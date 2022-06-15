#pragma once
// ---------- Shadow ----------
//All high level data should be stored here
namespace sh
{
    //used for fatal error handling
	typedef enum class sh_Panic : unsigned char
	{
		//Unknown issue
		panic_unknown = 0,
		//A texture was destroyed while loaded in video memory
		panic_loaded_texture,
		//A manual crash was initiated
		panic_manual,
        //An unsuported resolution was provided 
        panic_resolution
	} sh_Panic;
}