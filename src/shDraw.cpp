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
};

std::vector<renderable> HUDQ;

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

void sh::auditorium::draw::drawScreen(sh::auditorium::viewport::sh_camera cam)
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
    DrawFPS(0,0);
    #if (DEBUGGING == 1)
    rlImGuiBegin();
    ImGui::ShowDemoWindow();
    rlImGuiEnd();
    #endif
    EndDrawing();
}