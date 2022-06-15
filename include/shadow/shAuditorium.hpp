#pragma once
// ---------- Include ----------

#include <shadow.hpp>

// ---------- Shadow ----------
namespace sh {namespace auditorium{
    void createWindow();
    void closeWindow();
    void reloadWindow();
    void resizeWindow(int width, int height);
    void renameWindow(const char* name);
}}
