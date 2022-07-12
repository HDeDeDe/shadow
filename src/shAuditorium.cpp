// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shSys.hpp>
#if (DEBUGGING == 1)
#include <rlImGui.h>
#endif
// ---------- Shadow ----------

//Variables -----
int m_width = 0;
int m_height = 0;
std::string m_name = { 0 };
bool m_active = false;
bool m_vsync = false;
bool m_MSAA = false;
bool m_fullscreen = false;
bool m_borderless = false;
float m_2DFactor = 1.0f;
bool killApp = false;
//Sys calls -----
void shSys::initAuditorium()
{
    sh::auditorium::createWindow();
    shSys::initTextureMan();
    shSys::initModelMan();
}

bool sh::play::Exit()
{
    if (WindowShouldClose() || killApp)
        {
            sh::gameLoopActive = false;
            sh::auditorium::closeWindow();
            return true;
        }
    return false;
}
void sh::play::Exit(bool quit)
{
    killApp = quit;
}
//Auditorium ----
void sh::auditorium::createWindow()
{
    if ((m_width < 640) || (m_height < 480))
    {
        shSys::panic(sh::sh_Panic::panic_resolution);
    }
    if(m_vsync) SetConfigFlags(FLAG_VSYNC_HINT);
    if(m_MSAA) SetConfigFlags(FLAG_MSAA_4X_HINT);
    if(m_fullscreen) SetConfigFlags(FLAG_FULLSCREEN_MODE);
    if(m_borderless) SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(m_width, m_height, m_name.c_str());
    
    
    m_active = true;
    textReloadAll();
    sh::auditorium::model::RegenerateModels();
    sh::auditorium::viewport::GlobalCamera.setOrigin();
    if(IsWindowFullscreen())
    {
        if (GetMonitorHeight(0) >= GetMonitorWidth(0))
        {
            m_2DFactor = (float)GetMonitorWidth(0) / 640.0f;
        }
        else
        {
            m_2DFactor = (float)GetMonitorHeight(0) / 480.0f;
        }
    }
    else
    {
        if (m_height >= m_width)
        {
            m_2DFactor = (float)m_width / 640.0f;
        }
        else
        {
            m_2DFactor = (float)m_height / 480.0f;
        }
    }
    #if (DEBUGGING == 1)
    rlImGuiSetup(true);
    #endif
}

void sh::auditorium::closeWindow()
{
    m_active = false;
    textDeloadAll();
    #if (DEBUGGING == 1)
    rlImGuiShutdown();
    #endif
    CloseWindow();
}

void sh::auditorium::reloadWindow()
{
    sh::auditorium::closeWindow();
    sh::auditorium::createWindow();
}

void sh::auditorium::resizeWindow(int width, int height)
{
    if (width < 640)
    {
        std::cout << "[SHADOW - WARNING] Window width is too small, setting to valid size." << std::endl;
        width = 640;
    }
    if (height < 480)
    {
        std::cout << "[SHADOW - WARNING] Window height is too small, setting to valid size." << std::endl;
        height = 480;
    }
    m_width = width;
    m_height = height;
    if (m_active) SetWindowSize(m_width, m_height);
    if (m_height >= m_width)
    {
       m_2DFactor = (float)m_width / 640.0f;
    }
    else
    {
        m_2DFactor = (float)m_height / 480.0f;
    }
}

void sh::auditorium::renameWindow(const char* name)
{
    m_name = name;
    if (m_active) SetWindowTitle(m_name.c_str());
}

bool sh::auditorium::isActive()
{
    return m_active;
}

void sh::auditorium::setVsync(bool flag)
{
    m_vsync = flag;
}

void sh::auditorium::setMSAA(bool flag)
{
    m_MSAA = flag;
}

void sh::auditorium::setFullscreen(bool flag)
{
    m_fullscreen = flag;

    if(m_fullscreen) 
    {
        if (m_active) SetWindowState(FLAG_FULLSCREEN_MODE);
        if (GetMonitorHeight(0) >= GetMonitorWidth(0))
        {
            m_2DFactor = (float)GetMonitorWidth(0) / 640.0f;
        }
        else
        {
            m_2DFactor = (float)GetMonitorHeight(0) / 480.0f;
        }
    }
    else
    {
        if (m_active) 
        {
            ClearWindowState(FLAG_FULLSCREEN_MODE);
            SetWindowSize(m_width, m_height);
        }
        if (m_height >= m_width)
        {
            m_2DFactor = (float)m_width / 640.0f;
        }
        else
        {
            m_2DFactor = (float)m_height / 480.0f;
        }
    }
}

void sh::auditorium::setBorderless(bool flag)
{
    m_borderless = flag;
}

int sh::auditorium::getResolutionX()
{ 
    if(m_fullscreen) return GetMonitorWidth(0);
    return m_width; 
}

int sh::auditorium::getResolutionY()
{
    if(m_fullscreen) return GetMonitorHeight(0);
    return m_height; 
}

float sh::auditorium::get2DFactor(){ return m_2DFactor; }
bool sh::auditorium::isFullscreen(){ return m_fullscreen; }