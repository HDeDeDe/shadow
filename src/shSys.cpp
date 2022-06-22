// ---------- Include ----------
#include <shSys.hpp>
#include <iostream>
// ---------- Shadow ----------
bool Panicing = false;
void shSys::panic(sh::sh_Panic issue)
{
	Panicing = true;
	sh::gameLoopActive = false;
	switch (issue)
	{
	case sh::sh_Panic::panic_loaded_texture: 
	{
		std::cout << "[SHADOW - ERROR] A texture was still loaded in video memory when destroyed." << std::endl;
	} break;
	case sh::sh_Panic::panic_unknown:
	{
		std::cout << "[SHADOW - ERROR] An unknown fatal error has occured." << std::endl;
	} break;
	case sh::sh_Panic::panic_manual:
	{
		std::cout << "[SHADOW - ERROR] A manual crash was initiated." << std::endl;
	} break;

	case sh::sh_Panic::panic_resolution:
	{
		std::cout << "[SHADOW - ERROR] An unsuported resolution was provided." << std::endl;
	} break;

	case sh::sh_Panic::panic_no_gl_context:
	{
		std::cout << "[SHADOW - ERROR] A texture was accesed without an OpenGL context." << std::endl;
	} break;

	case sh::sh_Panic::panic_default_corrupted:
	{
		std::cout << "[SHADOW - ERROR] The default settings have been corrupted." << std::endl;
	} break;

	case sh::sh_Panic::panic_init_fail:
	{
		std::cout << "[SHADOW - ERROR] The initialization file is missing or corrupted." << std::endl;
	} break;

	default: break;
	}
	throw issue;
}

bool shSys::isPanicing()
{
	return Panicing;
}