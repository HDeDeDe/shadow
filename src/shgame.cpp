#include <shadow.hpp>
void sh::play::ShadowPlay()
{
    shSys::initAuditorium();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
}