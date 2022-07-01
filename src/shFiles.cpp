// ---------- Include ----------
#include <shFiles.hpp>
#include <filesystem>
// ---------- Shadow ----------
#if (_WIN64 == 1)
std::string environment = getenv("APPDATA");
#endif
#if (__APPLE__ == 1)
std::string environment = getenv("HOME");
#endif
std::string sh::file::getEnvironment()
{
    return environment;
}
void sh::file::createSettingsFolder(const char* settingsFolder)
{
    if(std::filesystem::create_directory(settingsFolder))std::cout << "[SHADOW - INFO] Folder created successfully" << std::endl;
    else std::cout << "[SHADOW - WARNING] Folder could not be created." << std::endl;
}