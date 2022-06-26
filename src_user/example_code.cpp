// ---------- Includes ----------
#include <shadow.hpp> //Main engine functions
#include <shLua.hpp> //Access to LuaCheck and the global lua virtual machine
#include <shStagePlay.hpp> //Entity manager
#include <shAuditorium.hpp> //Window and texture manager

// ---------- Your Variables / Functions ----------

std::string ExampleText;
sh::Dimension ExampleDimension;



// ---------- Shadow ----------

void sh::play::GameInit() //This is where you initialize any nesecary code
{
    lua_getglobal(sh::lua::GetLuaGlobal(), "PictureToLoad");
    sh::auditorium::texture::sh_TextureManager::Create("Test", lua_tostring(sh::lua::GetLuaGlobal(), -1));
    lua_pop(sh::lua::GetLuaGlobal(), -1);

    sh::auditorium::texture::sh_TextureManager::Load("Test");
    ExampleDimension.X = 40.0f;
    ExampleDimension.Y = 50.0f;
    ExampleDimension.Size(50.0f);

    lua_getglobal(sh::lua::GetLuaGlobal(), "TextToDisplay");
    if(lua_isstring(sh::lua::GetLuaGlobal(), -1)) ExampleText = lua_tostring(sh::lua::GetLuaGlobal(), -1);
    else ExampleText = "FAIL";
    lua_pop(sh::lua::GetLuaGlobal(), -1);

    lua_getglobal(sh::lua::GetLuaGlobal(), "ModelToLoad");
    sh::auditorium::model::Load("Test", lua_tostring(sh::lua::GetLuaGlobal(), -1));
    lua_pop(sh::lua::GetLuaGlobal(), -1);
}

void sh::play::GameLoop() //This is where the main game loop occurrs, rendering is handled outside of this loop
{
    sh::auditorium::draw::queueHUD(DTEXTURE, "Test");
    sh::auditorium::draw::queueHUD(DTEXT, ExampleText, ExampleDimension, RED);
    sh::auditorium::draw::queue3D(DMODEL, "Test");
    sh::auditorium::viewport::GlobalCamera.updateCameras();
}

//This is where you put any code relating to Dear imgui
#if (DEBUGGING == 1)
#include <imgui.h>
void sh::play::ImguiDebugDraw()
{
    ImGui::Text("FPS: %d", GetFPS());
    ImGui::Text("Frame Time: %d", GetFrameTime());
    ImGui::Checkbox("Render Background", &isBG);
    ImGui::Checkbox("Render 2D", &is2D);
    ImGui::Checkbox("Render 3D", &is3D);
    ImGui::Checkbox("Render HUD", &isHUD);

    float dbg_colors[4] = {((float)sh::auditorium::draw::bgDefault.r / 255.0f), ((float)sh::auditorium::draw::bgDefault.g  / 255.0f), ((float)sh::auditorium::draw::bgDefault.b / 255.0f), ((float)sh::auditorium::draw::bgDefault.a / 255.0f)};
    ImGui::ColorEdit4("Background Color", dbg_colors);
    sh::auditorium::draw::bgDefault = CLITERAL(Color){(unsigned char)(dbg_colors[0] * 255.0f),(unsigned char)(dbg_colors[1] * 255.0f),(unsigned char)(dbg_colors[2]* 255.0f),(unsigned char)255};
    
    sh::Dimension temp_cam2D =  sh::auditorium::viewport::GlobalCamera.getDimension2D();
    sh::Dimension temp_cam3D =  sh::auditorium::viewport::GlobalCamera.getDimension3D();
    Vector3 temp_3DTarg = sh::auditorium::viewport::GlobalCamera.get3DTarget();

    float dbg_3dCamPos[3] = {temp_cam3D.X, temp_cam3D.Y, temp_cam3D.Z};
    ImGui::DragFloat3("Camera3D Position", dbg_3dCamPos);

    float dbg_3dCamTarg[3] = {temp_3DTarg.x, temp_3DTarg.y, temp_3DTarg.z};
    ImGui::DragFloat3("Camera3D Target", dbg_3dCamTarg);

    float dbg_2dCamPos[2] = {temp_cam2D.X, temp_cam2D.Y};
    ImGui::DragFloat2("Camera2D Position", dbg_2dCamPos);

    temp_cam2D.X = dbg_2dCamPos[0];
    temp_cam2D.Y = dbg_2dCamPos[1];
    
    temp_cam3D.X = dbg_3dCamPos[0];
    temp_cam3D.Y = dbg_3dCamPos[1];
    temp_cam3D.Z = dbg_3dCamPos[2];

    temp_3DTarg.x = dbg_3dCamTarg[0];
    temp_3DTarg.y = dbg_3dCamTarg[1];
    temp_3DTarg.z = dbg_3dCamTarg[2];

    sh::auditorium::viewport::GlobalCamera.setDimension3D(temp_cam3D);
    sh::auditorium::viewport::GlobalCamera.setDimension2D(temp_cam2D);
    sh::auditorium::viewport::GlobalCamera.set3DTarget(temp_3DTarg);
}
#endif