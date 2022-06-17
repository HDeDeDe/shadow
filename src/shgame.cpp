// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>

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