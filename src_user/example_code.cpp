// ---------- Includes ----------
#include <shadow.hpp> //Main engine functions
#include <shLua.hpp> //Access to LuaCheck and the global lua virtual machine
#include <shStagePlay.hpp> //Entity manager
#include <shAuditorium.hpp> //Window and texture manager

// ---------- Your Variables / Functions ----------

std::string ExampleText;
sh::Dimension ExampleDimensionText;
sh::Dimension ExampleDimensionCube;

Ray spaget = { 0 };
Vector3 g0 = { -10.0f, 0.0f, -10.0f };
Vector3 g1 = { -10.0f, 0.0f, 10.0f };
Vector3 g2 = { 10.0f, 0.0f, 10.0f };
Vector3 g3 = { 10.0f, 0.0f, -10.0f };

// ---------- Shadow ----------

void sh::play::GameInit() //This is where you initialize any nesecary code
{
    sh::auditorium::renameWindow("Super Vergil");
    sh::auditorium::draw::enableLayer(0);
    sh::auditorium::draw::enableLayer(1);

    lua_getglobal(sh::lua::GetLuaGlobal(), "PictureToLoad");
    sh::auditorium::texture::sh_TextureManager::Create("Test", lua_tostring(sh::lua::GetLuaGlobal(), -1));
    lua_pop(sh::lua::GetLuaGlobal(), -1);

    sh::auditorium::texture::sh_TextureManager::Load("Test");
    ExampleDimensionText.X = 40.0f;
    ExampleDimensionText.Y = 50.0f;
    ExampleDimensionText.Size(50.0f);

    lua_getglobal(sh::lua::GetLuaGlobal(), "TextToDisplay");
    if(lua_isstring(sh::lua::GetLuaGlobal(), -1)) ExampleText = lua_tostring(sh::lua::GetLuaGlobal(), -1);
    else ExampleText = "FAIL";
    lua_pop(sh::lua::GetLuaGlobal(), -1);

    lua_getglobal(sh::lua::GetLuaGlobal(), "ModelToLoad");
    sh::auditorium::model::Load("Test", lua_tostring(sh::lua::GetLuaGlobal(), -1));
    lua_pop(sh::lua::GetLuaGlobal(), -1);
    sh::auditorium::model::SetModelMaterial("Test", "Test");
}

void sh::play::GameLoop() //This is where the main game loop occurrs, rendering is handled outside of this loop
{
    spaget = GetMouseRay(GetMousePosition(), sh::auditorium::viewport::GlobalCamera.getCamera3D());
    RayCollision hitGround = GetRayCollisionQuad(spaget, g0, g1, g2, g3);
    if (hitGround.hit) {
        ExampleDimensionCube.X = hitGround.point.x;
        ExampleDimensionCube.Y = hitGround.point.y;
        ExampleDimensionCube.Z = hitGround.point.z;
    }
    sh::auditorium::draw::queueHUD(DTEXTURE, "Test");
    sh::auditorium::draw::queueHUD(DTEXT, ExampleText, 0, ExampleDimensionText, RED);
    sh::auditorium::draw::queue3D(DMODEL, "Test", 1, ExampleDimensionCube);
    sh::auditorium::draw::queue2D(DTESTRECT, "", 0);
    sh::auditorium::viewport::GlobalCamera.updateCameras();
}

//This is where you put any code relating to Dear imgui
#if (DEBUGGING == 1)
#include <shImGuiBuiltin.hpp>
void sh::play::ImguiDebugDraw()
{
    sh::debug::DebugImgui();
}
#endif