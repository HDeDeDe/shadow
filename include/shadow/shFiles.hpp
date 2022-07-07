#pragma once
// ---------- Include ----------
#include <shadow.hpp>
// ---------- Shadow ----------
namespace sh{namespace file{
    inline std::string settingsLoc = { 0 };
    inline std::string settingsFolder = { 0 };
    std::string getEnvironment();
    void createSettingsFolder(const char* settingsFolder);
}
}