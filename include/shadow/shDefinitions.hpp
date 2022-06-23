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
		panic_no_gl_context,
		//The default settings have been corrupted
		panic_default_corrupted,
		//The initialization file is missing or corrupted
		panic_init_fail
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
		void Size(float size) {Width = size; Height = size; Length = size;}
		float Size() {float i; i = (Width + Height + Length) / 3; return i;}
	} Dimension;
	inline bool gameLoopActive = false;
	
	//Launch flags
	namespace flags
	{
		enum class argCase : unsigned char
		{
			none = 0,
			demo,
			windowed,
			novid,
			noSound,
			help
		};
		//Run in demo mode
		inline bool demo = false;
		//Force windowed mode at launch
		inline bool windowed = false;
		//Disable intro videos
		inline bool noVid = false;
		//Disable all audio
		inline bool noSound = false;

	}
	typedef enum class renderType
	{
		texture = 0,
		text
	} renderType;

	//Should auditorium do 3D calls
	inline bool is3D = false;
	//Should auditorium do 2D calls
	inline bool is2D = false;
}

#define DTEXTURE sh::renderType::texture
#define DTEXT sh::renderType::text