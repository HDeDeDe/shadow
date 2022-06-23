// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shSys.hpp>
// ---------- Shadow ----------

//Variables -----
int m_width = 0;
int m_height = 0;
std::string m_name = { 0 };
bool m_active = false;
bool m_vsync = false;
bool m_MSAA = false;
//Sys calls -----
void shSys::initAuditorium()
{
    SetExitKey(KEY_NULL);
    m_width = 360;
    m_height = 240;
    m_name = "[SHADOW] Starting...";
    sh::auditorium::createWindow();
    shSys::initTextureMan();
}

bool sh::play::Exit(bool killApp)
{
    if (WindowShouldClose() || killApp)
        {
            sh::gameLoopActive = false;
            sh::auditorium::closeWindow();
            return true;
        }
    return false;
}
//Auditorium ----
void sh::auditorium::createWindow()
{
    if ((m_width < 360) || (m_height < 240))
    {
        shSys::panic(sh::sh_Panic::panic_resolution);
    }
    if(m_vsync) SetConfigFlags(FLAG_VSYNC_HINT);
    if(m_MSAA) SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(m_width, m_height, m_name.c_str());
    
    m_active = true;
    textReloadAll();
}

void sh::auditorium::closeWindow()
{
    m_active = false;
    textDeloadAll();
    CloseWindow();
}

void sh::auditorium::reloadWindow()
{
    sh::auditorium::closeWindow();
    sh::auditorium::createWindow();
}

void sh::auditorium::resizeWindow(int width, int height)
{
    if (width < 360)
    {
        std::cout << "[SHADOW - WARNING] Window width is too small, setting to valid size." << std::endl;
        width = 360;
    }
    if (height < 240)
    {
        std::cout << "[SHADOW - WARNING] Window height is too small, setting to valid size." << std::endl;
        height = 240;
    }
    m_width = width;
    m_height = height;
    SetWindowSize(m_width, m_height);
}

void sh::auditorium::renameWindow(const char* name)
{
    m_name = name;
    SetWindowTitle(m_name.c_str());
}

bool sh::auditorium::isActive()
{
    return m_active;
}

void sh::auditorium::setVsync(bool flag)
{
    m_vsync = flag;
    if(m_vsync == true) SetWindowState(FLAG_VSYNC_HINT);
    else ClearWindowState(FLAG_VSYNC_HINT);
}

void sh::auditorium::setMSAA(bool flag)
{
    m_MSAA = flag;
    reloadWindow();
}