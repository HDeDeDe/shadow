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
        panic_resolution,
		//A texture was loaded without a proper opengl context
		panic_no_gl_context
	} sh_Panic;
	//Stores relevant Theatric position data
	typedef struct Dimension {
		float X = 0.0f;
		float Y = 0.0f;
		float Z = 0.0f;
		float Width = 1.0f;
		float Height = 1.0f;
		float Length = 1.0f;
		float Roll = 0.0f;
		float Pitch = 0.0f;
		float Yaw = 0.0f;
	} Dimension;
	inline bool gameLoopActive = false;
}