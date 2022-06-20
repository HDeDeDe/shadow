#pragma once
// ---------- Include ----------
#include <shadow.hpp>
// ---------- Shadow ----------
namespace sh{namespace file{
    #if (_WIN64 == 1)
    std::string getAppdata();
    #endif
    #if (__APPLE__ == 1)
    std::string getHome();
    #endif
    void createSettingsFolder(const char* settingsFolder);
}
}