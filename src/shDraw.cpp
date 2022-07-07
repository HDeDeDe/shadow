// ---------- Include ----------
#include <shAuditorium.hpp>
#include <shStagePlay.hpp>
#include <vector>
#if (DEBUGGING == 1)
#include <rlImGui.h>
#include <imgui.h>
#endif
// ---------- Shadow ----------

unsigned int bucketClamp(unsigned int layer)
{
    if(layer >= BUCKETSIZE) layer = BUCKETSIZE - 1;
    return layer;
}

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
    bool enabledHUD = false;
    bool enabled3D = false;
    bool enabled2D = false;
    std::vector<renderable> QHUD;
    std::vector<renderable> Q3D;
    std::vector<renderable> Q2D;
    std::vector<renderable> QBG;
};

renderBucket bucket[BUCKETSIZE];

void sh::auditorium::draw::queueHUD(sh::renderType type, std::string content, unsigned int layer, sh::Dimension dDimension, Color dColor)
{   
    unsigned int clampedLayer = bucketClamp(layer);
    switch(type)
    {
    case DTEXT:
        bucket[clampedLayer].QHUD.push_back({type, content, dColor, dDimension});
        bucket[clampedLayer].enabledHUD = true;
        break;
    case DTEXTURE:
        bucket[clampedLayer].QHUD.push_back({type, content, dColor, dDimension});
        bucket[clampedLayer].enabledHUD = true;
        break;
    default: break;
    }
}
void sh::auditorium::draw::queueHUD(sh::renderType type, sh::theatrics::detail::theatric* theatric, unsigned int layer)
{
    unsigned int clampedLayer = bucketClamp(layer);
    switch(type)
    {
    case DTHEATRIC:
        bucket[clampedLayer].QHUD.push_back({type, "", BLACK, ZERODIMENSION, theatric});
        bucket[clampedLayer].enabledHUD = true;
        break;
    default: break;
    }
}

void sh::auditorium::draw::queue2D(sh::renderType type, std::string content, unsigned int layer, sh::Dimension dDimension, Color dColor)
{
    unsigned int clampedLayer = bucketClamp(layer);
    switch(type)
    {
    case DTEXT:
        bucket[clampedLayer].Q2D.push_back({type, content, dColor, dDimension});
        bucket[clampedLayer].enabled2D = true;
        break;
    case DTEXTURE:
        bucket[clampedLayer].Q2D.push_back({type, content, dColor, dDimension});
        bucket[clampedLayer].enabled2D = true;
        break;
    case DTESTRECT:
        bucket[clampedLayer].Q2D.push_back({type, content, dColor, dDimension});
        bucket[clampedLayer].enabled2D = true;
        break;
    default: break;
    }
}
void sh::auditorium::draw::queue2D(sh::renderType type, sh::theatrics::detail::theatric* theatric, unsigned int layer)
{
    unsigned int clampedLayer = bucketClamp(layer);
    switch(type)
    {
    case DTHEATRIC:
        bucket[clampedLayer].Q2D.push_back({type, "", BLACK, ZERODIMENSION, theatric});
        bucket[clampedLayer].enabled2D = true;
        break;
    default: break;
    }
}

void sh::auditorium::draw::queue3D(sh::renderType type, std::string content, unsigned int layer, sh::Dimension dDimension, Color dColor)
{
    unsigned int clampedLayer = bucketClamp(layer);
    switch(type)
    {
    case DMODEL:
        bucket[clampedLayer].Q3D.push_back({type, content, dColor, dDimension});
        bucket[clampedLayer].enabled3D = true;
        break;
    default: break;
    }
}

void sh::auditorium::draw::queue3D(sh::renderType type, sh::theatrics::detail::theatric* theatric, unsigned int layer)
{
    unsigned int clampedLayer = bucketClamp(layer);
    switch(type)
    {
    case DTHEATRIC:
        bucket[clampedLayer].Q3D.push_back({type, "", BLACK, ZERODIMENSION, theatric});
        bucket[clampedLayer].enabled3D = true;
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

    for (int i = 0; i < BUCKETSIZE; i++)
    {
        //Draw 3D
        if(sh::is3D == true && bucket[i].enabled3D)
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
            bucket[i].enabled3D = false;
            EndMode3D();
        }

        //Draw 2D
        if(sh::is2D == true && bucket[i].enabled2D)
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
                    DrawRectanglePro(Rectangle{-20.0f, -20.0f, 20.0f, 20.0f}, Vector2{0.5f, 0.5f}, 0.0f, RED);
                    break;
                default: break;
                }
            }
            bucket[i].Q2D.clear();
            bucket[i].enabled2D = false;
            EndMode2D();
        }
    }
    //DrawHUD
    if(sh::isHUD == true)
    {
        for (int i = 0; i < BUCKETSIZE; i++)
        {
            if(bucket[i].enabledHUD)
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
                bucket[i].enabledHUD = false;
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