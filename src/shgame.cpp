// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>

// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
}