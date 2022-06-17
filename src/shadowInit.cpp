// ---------- Include ----------
#include <shInit.hpp>
#include <shadow.hpp>

// ---------- Shadow ----------
void startApp()
{
	std::cout << "[SHADOW - INFO] Starting..." << std::endl;
	shSys::initAuditorium();
	sh::play::ShadowStart();
	//shSys::cleanTextureMan();
	std::cout << "[SHADOW - INFO] Exiting..." << std::endl;
}