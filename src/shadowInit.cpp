// ---------- Include ----------
#include <shInit.hpp>
#include <shadow.hpp>

// ---------- Shadow ----------
void startApp()
{
	std::cout << "[SHADOW - INFO] Starting..." << std::endl;
	shSys::initAuditorium();
	
	sh::play::ShadowPlay();
	std::cout << "[SHADOW - INFO] Exiting..." << std::endl;
}