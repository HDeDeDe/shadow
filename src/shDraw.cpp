// ---------- Include ----------
#include <shAuditorium.hpp>
#if (DEBUGGING == 1)
//#include <shDearImgui.hpp>
#endif
// ---------- Shadow ----------




void sh::auditorium::drawScreen(sh::auditorium::viewport::sh_camera cam)
{
    BeginDrawing();
    ClearBackground(BLACK);
    if(sh::is3D == true)
    {
        BeginMode3D(cam.getCamera3D());

        EndMode3D();
    }
    
    if(sh::is2D == true)
    {
        BeginMode2D(cam.getCamera2D());

        EndMode2D();
    }

    //DrawHUD
    DrawFPS(0,0);
    DrawText(sh::auditorium::wrkDir.c_str(), 0, 20, 15, BLUE);

    #if (DEBUGGING == 1)

    #endif
    EndDrawing();
}