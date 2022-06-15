// ---------- Include ----------
#include <shadow.hpp>

// ---------- Shadow ----------

void sh::play::ShadowPlay()
{
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
}