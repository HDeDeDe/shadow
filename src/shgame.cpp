// ---------- Include ----------
#include <shadow.hpp>

// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    std::string wrkDir = { 0 };
    if (FileExists("./Test.bin")) wrkDir = "Success";
    else wrkDir = "Failed";
    while (sh::gameLoopActive)
    {
        if(sh::play::Exit())break;
        //sh::play::ShadowGameLoop();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(0,0);
        DrawText(wrkDir.c_str(), 0, 20, 15, BLUE);
        EndDrawing();
    }
}