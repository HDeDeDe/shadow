// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shLua.hpp>
// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    float frameTime = 0.0f;
    sh::lua::InitLuaGlobal();
    sh::play::GameInit();
    while (sh::gameLoopActive)
    {
        frameDiff = 0;
        if(sh::play::Exit())break;
        while(previousInternalFrame != sh::globalTimer)
        {
            previousInternalFrame++;
            frameDiff++;
        }
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
