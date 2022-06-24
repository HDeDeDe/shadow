#pragma once
// ---------- Include ----------

#include <shadow.hpp>

// ---------- Shadow ----------
namespace sh {
    namespace auditorium{
        void createWindow();
        void closeWindow();
        void reloadWindow();
        void resizeWindow(int width, int height);
        void renameWindow(const char* name);
        bool isActive();
        void setVsync(bool flag);
        void setMSAA(bool flag);
        int getResolutionX();
        int getResolutionY();

        //Textures are actively managed by Auditorium
        namespace texture
        {
            class sh_Texture
            {
            public:
                sh_Texture() = delete;
                bool isLoadedVram();
                Texture getTexture();
                std::string getTextureReference();
            private:
                //Check for if loaded into video memory
                bool m_vram_loaded = false;
                //Texture stored in cpu memory
                Image m_ram = { 0 };
                //Texture stored in video memory (CAN NOT EXIST WITHOUT OPENGL CONTEXT)
                Texture m_vram = { 0 };
                //Texture string stored for easy access
                std::string m_texture_reference = { 0 };
                //Block constructors
                ~sh_Texture();
                sh_Texture& operator=(sh_Texture const&);
                sh_Texture(const sh_Texture&);
                sh_Texture(std::string texture_location, std::string texture_reference);
                friend class sh_TextureManager;
            };
            class sh_TextureManager
            {
            public:
                //Create a new texture from a file
                inline static void Create(std::string texture_reference, std::string file_location) { return Get().in_Create(texture_reference, file_location); };
                //Destroy referenced texture
                inline static void Destroy(std::string texture_reference) { return Get().in_Destroy(texture_reference); };
                //Load texture into video memory
                inline static void Load(std::string texture_reference) { return Get().in_Load(texture_reference); };
                //Unload texture from video memory
                inline static void Unload(std::string texture_reference) { return Get().in_Unload(texture_reference); };
                //Loads any textures designated to be loaded into vram
                inline static void TextureReloadAll() { return Get().in_TextureReloadAll(); };
                //Unloads any textures designated to be loaded into vram
                inline static void TextureDeloadAll() { return Get().in_TextureDeloadAll(); };
                //Get reference to texture, it's recomended to cache this for later use
                inline static sh_Texture* GetTexturePointer(std::string texture_reference) { return Get().in_GetTexturePointer(texture_reference); };
                //Get texture
                inline static Texture GetTexture(std::string texture_reference) { return Get().in_GetTexture(texture_reference); };
                //Clean up textures
                inline static void CleanTextureMan() { return Get().in_CleanTextureMan(); };
            private:
                //Access functions
                static sh_TextureManager& Get();
                //Internal functions
                void in_Create(std::string texture_reference, std::string file_location);
                void in_Destroy(std::string texture_reference);
                void in_Load(std::string texture_reference);
                void in_Unload(std::string texture_reference);
                void in_TextureReloadAll();
                void in_TextureDeloadAll();
                sh_Texture* in_GetTexturePointer(std::string texture_reference);
                Texture in_GetTexture(std::string texture_reference);
                void in_CleanTextureMan();
                //Block constructors
                sh_TextureManager& operator=(sh_TextureManager const&);
                sh_TextureManager();
                sh_TextureManager(const sh_TextureManager&);
            };
        }

        namespace viewport
        {
            class sh_camera
            {
                sh::Dimension m_dimension2D = { 0 };
                sh::Dimension m_dimension3D = { 0 };
                Camera3D m_3DCam = { 0 };
                Camera2D m_2DCam = { 0 };
            public:
                Camera2D getCamera2D() { return m_2DCam; };
                Camera3D getCamera3D() { return m_3DCam; };
                void setDimension2D(sh::Dimension dimension) { m_dimension2D = dimension; };
                sh::Dimension getDimension2D() { return m_dimension2D; };
                void setDimension3D(sh::Dimension dimension) { m_dimension2D = dimension; };
                sh::Dimension getDimension3D() { return m_dimension3D; };
                void updateCameras();
                void setOrigin();
                sh_camera(int fov = 45);
            };

            inline sh_camera GlobalCamera;
        }

        inline static void textDeloadAll() { return texture::sh_TextureManager::TextureDeloadAll(); };
        inline static void textReloadAll() { return texture::sh_TextureManager::TextureReloadAll(); };
        namespace draw
        {
            void queueHUD(sh::renderType type, std::string content, sh::Dimension dDimension = sh::Dimension{ 0 }, Color dColor = WHITE);
            void drawScreen(sh::auditorium::viewport::sh_camera cam);
        }
    }
}
