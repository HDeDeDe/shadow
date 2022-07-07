#pragma once
// ---------- Include ----------
#include <shadow.hpp>
// ---------- Shadow ----------
namespace sh{namespace file{
    std::string getEnvironment();
    void createSettingsFolder(const char* settingsFolder);
}
}