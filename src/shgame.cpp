#include <shadow.hpp>
void sh::play::ShadowPlay()
{
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
}