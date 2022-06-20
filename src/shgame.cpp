// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>

// ---------- Shadow ----------


bool shExit(bool killApp = false)
{
    if (WindowShouldClose() || killApp)
        {
            sh::gameLoopActive = false;
            sh::auditorium::closeWindow();
            return true;
        }
    return false;
}

void sh::play::ShadowStart()
{
    while (sh::gameLoopActive)
    {
        if(shExit())break;

        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawFPS(0, 0);
        EndDrawing();
    }
}