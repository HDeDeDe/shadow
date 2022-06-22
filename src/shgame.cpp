// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>
// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    sh::auditorium::viewport::sh_camera GlobalCamera;
    while (sh::gameLoopActive)
    {
        if(sh::play::Exit())break;
        sh::auditorium::drawScreen(GlobalCamera);
    }
}