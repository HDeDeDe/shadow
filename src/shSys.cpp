#include <shSys.hpp>

bool Panicing = false;
void shSys::panic(sh_Panic issue)
{
	Panicing = true;
	switch (issue)
	{
	case shSys::sh_Panic::panic_loaded_texture: 
	{
		std::cout << "[SHADOW - ERROR] A texture was still loaded in video memory when destroyed." << std::endl;
	} break;
	case shSys::sh_Panic::panic_unknown:
	{
		std::cout << "[SHADOW - ERROR] An unknown fatal error has occured." << std::endl;
	} break;
	case shSys::sh_Panic::panic_manual:
	{
		std::cout << "[SHADOW - ERROR] A manual crash was initiated." << std::endl;
	} break;

	default: break;
	}
	throw issue;
}

bool shSys::isPanicing()
{
	return Panicing;
}