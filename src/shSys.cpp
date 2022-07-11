// ---------- Include ----------
#include <shSys.hpp>
#include <iostream>
#include <fstream>
// ---------- Shadow ----------
bool Panicing = false;
void shSys::panic(sh::sh_Panic issue)
{
	Panicing = true;
	sh::gameLoopActive = false;
	std::ofstream output_file;
	output_file.open("shadow_panic.log", std::ofstream::out | std::ofstream::trunc);
	switch (issue)
	{
	case sh::sh_Panic::panic_loaded_texture: 
	{
		output_file << "[SHADOW - ERROR] A texture was still loaded in video memory when destroyed.";
		std::cout << "[SHADOW - ERROR] A texture was still loaded in video memory when destroyed." << std::endl;
	} break;
	case sh::sh_Panic::panic_unknown:
	{
		output_file << "[SHADOW - ERROR] An unknown fatal error has occured.";
		std::cout << "[SHADOW - ERROR] An unknown fatal error has occured." << std::endl;
	} break;
	case sh::sh_Panic::panic_manual:
	{
		output_file << "[SHADOW - ERROR] A manual crash was initiated.";
		std::cout << "[SHADOW - ERROR] A manual crash was initiated." << std::endl;
	} break;

	case sh::sh_Panic::panic_resolution:
	{
		output_file << "[SHADOW - ERROR] An unsuported resolution was provided.";
		std::cout << "[SHADOW - ERROR] An unsuported resolution was provided." << std::endl;
	} break;

	case sh::sh_Panic::panic_no_gl_context:
	{
		output_file << "[SHADOW - ERROR] A texture was accesed without an OpenGL context.";
		std::cout << "[SHADOW - ERROR] A texture was accesed without an OpenGL context." << std::endl;
	} break;

	case sh::sh_Panic::panic_default_corrupted:
	{
		output_file << "[SHADOW - ERROR] The default settings have been corrupted.";
		std::cout << "[SHADOW - ERROR] The default settings have been corrupted." << std::endl;
	} break;

	case sh::sh_Panic::panic_init_fail:
	{
		output_file << "[SHADOW - ERROR] An initialization file is missing or corrupted.";
		std::cout << "[SHADOW - ERROR] An initialization file is missing or corrupted." << std::endl;
	} break;

	default: break;
	}
	output_file.close();
	throw issue;
}

bool shSys::isPanicing()
{
	return Panicing;
}