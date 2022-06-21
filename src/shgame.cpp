// ---------- Include ----------
#include <shadow.hpp>

// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    while (sh::gameLoopActive)
    {
        if(sh::play::Exit())break;
        //sh::play::ShadowGameLoop();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(0,0);
        EndDrawing();
    }
}