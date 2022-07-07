// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shLua.hpp>
// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    float timeInc = 1.0f / (int)INFRAMERATE;
    float frameTime = 0.0f;
    sh::lua::InitLuaGlobal();
    sh::play::GameInit();
    while (sh::gameLoopActive)
    {
        if(sh::play::Exit())break;
        if(previousInternalFrame != sh::globalTimer) previousInternalFrame++;
        frameTime += GetFrameTime();
        while(frameTime > timeInc)
        {
            sh::globalTimer++;
            frameTime -= timeInc;
        }
        sh::play::GameLoop();
        sh::auditorium::draw::drawScreen(sh::auditorium::viewport::GlobalCamera);
    }
    sh::lua::CloseLuaGlobal();
}
