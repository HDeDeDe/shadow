// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
#include <shLua.hpp>
// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    sh::lua::InitLuaGlobal();
    sh::play::GameInit();
    while (sh::gameLoopActive)
    {
        if(sh::play::Exit())break;
        sh::play::GameLoop();
        sh::auditorium::draw::drawScreen(sh::auditorium::viewport::GlobalCamera);
    }
    sh::lua::CloseLuaGlobal();
}
