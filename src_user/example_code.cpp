// ---------- Includes ----------
#include <shadow.hpp> //Main engine functions
#include <shLua.hpp> //Access to LuaCheck and the global lua virtual machine
#include <shStagePlay.hpp> //Entity manager
#include <shAuditorium.hpp> //Window and texture manager
#include <shInput.hpp> //Input functions

// ---------- Your Variables / Functions ----------

class ExampleCube : public sh::theatrics::actor
{
    friend class ExampleCubeHelper;
    sh::theatrics::actorHelper* m_helper;
public:
    ExampleCube(unsigned int Type, sh::theatrics::actorHelper* helper) 
    : actor(Type)
    {
        m_helper = helper;
    }
    void renderMe()
    {
        DrawModelEx(sh::auditorium::model::GetModel("Test"), Vector3{m_dimension.X, m_dimension.Y, m_dimension.Z}, Vector3{0.0f, 0.0f, 0.0f}, 0.0f, Vector3{m_dimension.Length, m_dimension.Width, m_dimension.Height}, WHITE);
    }
    void update()
    {
        m_helper->update(this);
    }
};

class ExampleCubeHelper : public sh::theatrics::actorHelper
{
    Ray spaget = { 0 };
    Vector3 g0 = { -10.0f, 0.0f, -10.0f };
    Vector3 g1 = { -10.0f, 0.0f, 10.0f };
    Vector3 g2 = { 10.0f, 0.0f, 10.0f };
    Vector3 g3 = { 10.0f, 0.0f, -10.0f };

    ExampleCubeHelper()
    {
        actorType = 1;
        Init();
    }
public:
    unsigned int ExampleID = 0;
    bool active = false;
    ExampleCubeHelper(const ExampleCubeHelper&) = delete;
    
    static ExampleCubeHelper& Get()
    {
        static ExampleCubeHelper instance;
        return instance;
    }

    void Init()
    {
        CreateActor();
    }
    void CreateActor()
    {
        ExampleCube* temp_ptr = new ExampleCube(actorType, this);
        ExampleID = temp_ptr->actorID;
    }
    void DestroyActor(unsigned int actorID)
    {
        sh::theatrics::actor* act_ptr = sh::theatrics::getActorPointer(actorID);
        if(act_ptr != nullptr && act_ptr->getActorType() == actorType)
        {
            delete (ExampleCube*)act_ptr;
            sh::theatrics::clearSlot(actorID);
        }
    }
    void DestroyActor(ExampleCube* act_ptr)
    {
        delete act_ptr;
    }
    void update(sh::theatrics::actor* act_ptr)
    {
        if(act_ptr != nullptr)
            if(act_ptr->getActorType() == actorType)
                update((ExampleCube*)act_ptr);
    }
    void update(ExampleCube* act_ptr)
    {
        if(active)
        {
            spaget = GetMouseRay(GetMousePosition(), sh::auditorium::viewport::GlobalCamera.getCamera3D());
            RayCollision hitGround = GetRayCollisionQuad(spaget, g0, g1, g2, g3);
            if (hitGround.hit) {
                act_ptr->m_dimension.X = hitGround.point.x;
                act_ptr->m_dimension.Y = hitGround.point.y;
                act_ptr->m_dimension.Z = hitGround.point.z;
            }
            active = false;
        }
    }
};

std::string ExampleText;
sh::Dimension ExampleDimensionText;

sh::input::inputKey ExampleInput;
bool ExampleInputPressed = false;

// ---------- Shadow ----------

void sh::play::GameInit() //This is where you initialize any nesecary code
{
    sh::auditorium::renameWindow("Super Vergil");
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
    
    lua_getglobal(sh::lua::GetLuaGlobal(), "ExampleInput");
    ExampleInput = (sh::input::inputKey)(unsigned char)(int)lua_tonumber(sh::lua::GetLuaGlobal(), -1);
    lua_pop(sh::lua::GetLuaGlobal(), -1);
}

void sh::play::GameLoopPriority() //This is where priority events happen, use this to do things like check for input
{
    if(sh::input::checkInput(ExampleInput, sh::input::INPUT_DOWN)) ExampleInputPressed = true;
    for(int i = 0; (i < frameDiff) && ExampleInputPressed; i++)
    {
        ExampleCubeHelper::Get().active = true;
        ExampleInputPressed = false;
    }
}

void sh::play::GameLoop() //This is where the main game loop occurrs, rendering is handled outside of this loop
{
    sh::auditorium::draw::queueHUD(DTEXTURE, "Test");
    sh::auditorium::draw::queueHUD(DTEXT, ExampleText, 0, ExampleDimensionText, RED);
    sh::auditorium::draw::queue3D(DTHEATRIC, sh::theatrics::getActorPointer(ExampleCubeHelper::Get().ExampleID), 1);
    sh::auditorium::draw::queue2D(DTESTRECT, "", 0);
    sh::auditorium::viewport::GlobalCamera.updateCameras();
    if(sh::input::checkInputSpecial(sh::input::KB_ESCAPE, sh::input::INPUT_PRESSED)) sh::play::Exit(true);
}

//This is where you put any code relating to Dear imgui
#if (DEBUGGING == 1)
#include <shImGuiBuiltin.hpp>
void sh::play::ImguiDebugDraw()
{
    sh::debug::DebugImgui();
}
#endif