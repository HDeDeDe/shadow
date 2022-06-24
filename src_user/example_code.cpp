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
    sh::auditorium::texture::sh_TextureManager::Create("Test", "./Test.png");
    sh::auditorium::texture::sh_TextureManager::Load("Test");
    ExampleDimension.X = 40.0f;
    ExampleDimension.Y = 50.0f;
    ExampleDimension.Size(50.0f);
    float tempFloat = ExampleDimension.Size();
    lua_getglobal(sh::lua::GetLuaGlobal(), "a");
    if(lua_isstring(sh::lua::GetLuaGlobal(), -1)) ExampleText = lua_tostring(sh::lua::GetLuaGlobal(), -1);
    else ExampleText = "FAIL";
    lua_pop(sh::lua::GetLuaGlobal(), -1);
}

void sh::play::GameLoop() //This is where the main game loop occurrs, rendering is handled outside of this loop
{
    sh::auditorium::draw::queueHUD(DTEXTURE, "Test");
    sh::auditorium::draw::queueHUD(DTEXT, ExampleText, ExampleDimension, RED);
}