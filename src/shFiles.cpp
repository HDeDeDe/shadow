// ---------- Include ----------
#include <shFiles.hpp>
#include <filesystem>
// ---------- Shadow ----------
#if (_WIN64 == 1)
std::string appdata = getenv("APPDATA");

std::string sh::file::getAppdata()
{
    return appdata;
}
#endif

void sh::file::createSettingsFolder(const char* settingsFolder)
{
    if(std::filesystem::create_directory(settingsFolder))std::cout << "[SHADOW - INFO] Folder created successfully" << std::endl;
    else std::cout << "[SHADOW - WARNING] Folder could not be created." << std::endl;
}