// ---------- Include ----------
#include <shAuditorium.hpp>
#include <vector>
#if (DEBUGGING == 1)
#include <rlImGui.h>
#include <imgui.h>
#endif
// ---------- Shadow ----------

struct renderable
{
    sh::renderType m_type;
    std::string m_content = { 0 };
    Color m_color;
    sh::Dimension m_dimension;
    std::string m_content2 = { 0 };
};

std::vector<renderable> HUDQ;
//std::vector<renderable> 3DQ;

void sh::auditorium::draw::queueHUD(sh::renderType type, std::string content, sh::Dimension dDimension, Color dColor)
{
    switch(type)
    {
    case DTEXT:
        HUDQ.push_back({type, content, dColor, dDimension});
        break;
    case DTEXTURE:
        HUDQ.push_back({type, content, dColor, dDimension});
        break;
    default: break;
    }
}

// void sh::auditorium::draw::queue3D(sh::renderType type, std::string content, sh::Dimension dDimension, Color dColor, std::string content2)
// {
//     switch(type)
//     {
//     case DMODEL:
//         3DQ.push_back({type, content, dColor, dDimension, content2});
//         break;
//     default: break;
//     }
// }

void sh::auditorium::draw::drawScreen(sh::auditorium::viewport::sh_camera cam)
{
    BeginDrawing();
    
    if(sh::isBG == true)
    {
        ClearBackground(bgDefault);
    }

    if(sh::is3D == true)
    {
        BeginMode3D(cam.getCamera3D());
        DrawGrid(20, 1.0f);
        
        EndMode3D();
    }

    if(sh::is2D == true)
    {
        BeginMode2D(cam.getCamera2D());
        DrawRectangle(0, 0, 50, 50, RED);
        EndMode2D();
    }

    //DrawHUD
    if(sh::isHUD == true)
    {
        for (renderable& r : HUDQ)
        {
            switch (r.m_type)
            {
            case DTEXT:
                DrawText(r.m_content.c_str(), (int)r.m_dimension.X, (int)r.m_dimension.Y, (int)r.m_dimension.Size(), r.m_color);
                break;
            case DTEXTURE:
                DrawTexture(sh::auditorium::texture::sh_TextureManager::GetTexture(r.m_content), (int)r.m_dimension.X, (int)r.m_dimension.Y, r.m_color);
                break;
            default: break;
            }
        }
        HUDQ.clear();
    }
    
    #if (DEBUGGING == 1)
    rlImGuiBegin();
    sh::play::ImguiDebugDraw();
    rlImGuiEnd();
    #endif
    EndDrawing();
}