// ---------- Include ----------
#include <shAuditorium.hpp>
#include <shStagePlay.hpp>
#include <vector>
#if (DEBUGGING == 1)
#include <rlImGui.h>
#include <imgui.h>
#endif
// ---------- Shadow ----------

struct sh::auditorium::draw::theatricPtr
{
    sh::theatrics::detail::theatric* m_ptr;
    theatricPtr(sh::theatrics::detail::theatric* ptr)
    {
        m_ptr = ptr;
    }
};

struct renderable
{
    sh::renderType m_type;
    std::string m_content = { 0 };
    Color m_color;
    sh::Dimension m_dimension;
    sh::theatrics::detail::theatric* m_theatric;
};

struct renderBucket
{
    bool enabled = false;
    std::vector<renderable> QHUD;
    std::vector<renderable> Q3D;
    std::vector<renderable> Q2D;
    std::vector<renderable> QBG;
};

renderBucket bucket[16];

void sh::auditorium::draw::queueHUD(sh::renderType type, std::string content, unsigned int layer, sh::Dimension dDimension, Color dColor)
{
    switch(type)
    {
    case DTEXT:
        bucket[layer].QHUD.push_back({type, content, dColor, dDimension});
        break;
    case DTEXTURE:
        bucket[layer].QHUD.push_back({type, content, dColor, dDimension});
        break;
    default: break;
    }
}
void sh::auditorium::draw::queueHUD(sh::renderType type, theatricPtr theatric, unsigned int layer)
{
    switch(type)
    {
    case DTHEATRIC:
        bucket[layer].QHUD.push_back({type, "", BLACK, ZERODIMENSION, theatric.m_ptr});
        break;
    default: break;
    }
}

void sh::auditorium::draw::queue2D(sh::renderType type, std::string content, unsigned int layer, sh::Dimension dDimension, Color dColor)
{
    switch(type)
    {
    case DTEXT:
        bucket[layer].Q2D.push_back({type, content, dColor, dDimension});
        break;
    case DTEXTURE:
        bucket[layer].Q2D.push_back({type, content, dColor, dDimension});
        break;
    case DTESTRECT:
        bucket[layer].Q2D.push_back({type, content, dColor, dDimension});
        break;
    default: break;
    }
}
void sh::auditorium::draw::queue2D(sh::renderType type, theatricPtr theatric, unsigned int layer)
{
    switch(type)
    {
    case DTHEATRIC:
        bucket[layer].Q2D.push_back({type, "", BLACK, ZERODIMENSION, theatric.m_ptr});
        break;
    default: break;
    }
}

void sh::auditorium::draw::queue3D(sh::renderType type, std::string content, unsigned int layer, sh::Dimension dDimension, Color dColor)
{
    switch(type)
    {
    case DMODEL:
        bucket[layer].Q3D.push_back({type, content, dColor, dDimension});
        break;
    default: break;
    }
}

void sh::auditorium::draw::queue3D(sh::renderType type, theatricPtr theatric, unsigned int layer)
{
    switch(type)
    {
    case DTHEATRIC:
        bucket[layer].Q3D.push_back({type, "", BLACK, ZERODIMENSION, theatric.m_ptr});
        break;
    default: break;
    }
}

void sh::auditorium::draw::drawScreen(sh::auditorium::viewport::sh_camera cam)
{
    BeginDrawing();
    if(sh::isBG == true)
    {
        ClearBackground(bgDefault);
    }

    for (int i = 0; i < 16; i++)
    {
        if(bucket[i].enabled)
        {
            //Draw 3D
            if(sh::is3D == true)
            {
                BeginMode3D(cam.getCamera3D());
                DrawGrid(20, 1.0f);
                
                for (renderable& r : bucket[i].Q3D)
                {
                    switch (r.m_type)
                    {
                    case DMODEL:
                        DrawModelEx(sh::auditorium::model::GetModel(r.m_content), Vector3{r.m_dimension.X, r.m_dimension.Y, r.m_dimension.Z}, Vector3{0.0f, 0.0f, 0.0f}, 0.0f, Vector3{r.m_dimension.Length, r.m_dimension.Width, r.m_dimension.Height}, r.m_color);
                        break;
                    case DTHEATRIC:
                        r.m_theatric->renderMe();
                        break;
                    default: break;
                    }
                }
                bucket[i].Q3D.clear();
                
                EndMode3D();
            }

            //Draw 2D
            if(sh::is2D == true)
            {
                BeginMode2D(cam.getCamera2D());
                for (renderable& r : bucket[i].Q2D)
                {
                    switch (r.m_type)
                    {
                    case DTEXT:
                        DrawText(r.m_content.c_str(), (int)r.m_dimension.X, (int)r.m_dimension.Y, (int)r.m_dimension.Size(), r.m_color);
                        break;
                    case DTEXTURE:
                        DrawTexture(sh::auditorium::texture::sh_TextureManager::GetTexture(r.m_content), (int)r.m_dimension.X, (int)r.m_dimension.Y, r.m_color);
                        break;
                    case DTHEATRIC:
                        r.m_theatric->renderMe();
                        break;
                    case DTESTRECT:
                        DrawRectanglePro(Rectangle{0.0f, 0.0f, 40.0f, 40.0f}, Vector2{0.5f, 0.5f}, 0.0f, RED);
                        break;
                    default: break;
                    }
                }
                bucket[i].Q2D.clear();
                EndMode2D();
            }
        }
    }
    //DrawHUD
    if(sh::isHUD == true)
    {
        for (int i = 0; i < 16; i++)
        {
            if(bucket[i].enabled)
            {
                for (renderable& r : bucket[i].QHUD)
                {
                    switch (r.m_type)
                    {
                    case DTEXT:
                        DrawText(r.m_content.c_str(), (int)r.m_dimension.X, (int)r.m_dimension.Y, (int)r.m_dimension.Size(), r.m_color);
                        break;
                    case DTEXTURE:
                        DrawTexture(sh::auditorium::texture::sh_TextureManager::GetTexture(r.m_content), (int)r.m_dimension.X, (int)r.m_dimension.Y, r.m_color);
                        break;
                    case DTHEATRIC:
                        r.m_theatric->renderMe();
                        break;
                    default: break;
                    }
                }
                bucket[i].QHUD.clear();
            }
        }
    }
    #if (DEBUGGING == 1)
    rlImGuiBegin();
    sh::play::ImguiDebugDraw();
    rlImGuiEnd();
    #endif
    EndDrawing();
}

void sh::auditorium::draw::enableLayer(int layer)
{
    bucket[layer].enabled = true;
}

void sh::auditorium::draw::disableLayer(int layer)
{
    bucket[layer].enabled = false;
}