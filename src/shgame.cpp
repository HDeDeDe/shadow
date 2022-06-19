// ---------- Include ----------
#include <shadow.hpp>
#include <shAuditorium.hpp>

// ---------- Shadow ----------

void sh::play::ShadowStart()
{
    sh::auditorium::texture::sh_TextureManager::Create("super_vergil", "./resource/supe.png");
    sh::auditorium::texture::sh_TextureManager::Load("super_vergil");
    sh::auditorium::texture::sh_Texture *sh_cached = sh::auditorium::texture::sh_TextureManager::GetTexturePointer("super_vergil");
    while (sh::gameLoopActive)
    {
        if (WindowShouldClose())
        {
            sh::gameLoopActive = false;
            sh::auditorium::closeWindow();
            break;
        }
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(sh_cached->getTexture(), 0, 0, WHITE);
        DrawFPS(0, 0);
        EndDrawing();
    }
}