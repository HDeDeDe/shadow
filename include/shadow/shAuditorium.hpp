#pragma once
// ---------- Include ----------

#include <shadow.hpp>

// ---------- Shadow ----------
namespace sh {
    namespace theatrics{namespace detail {class theatric;}}
    namespace auditorium{
        void createWindow();
        void closeWindow();
        void reloadWindow();
        void resizeWindow(int width, int height);
        void renameWindow(const char* name);
        bool isActive();
        bool isFullscreen();
        void setVsync(bool flag);
        void setMSAA(bool flag);
        void setBorderless(bool flag);
        void setFullscreen(bool flag);
        int getResolutionX();
        int getResolutionY();
        float get2DFactor();

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

        namespace model
        {
            void Load(std::string model_reference, std::string file_location);
            void Unload(std::string model_reference);
            Model GetModel(std::string model_reference);
            void SetModelMaterial(std::string model_reference, std::string texture_reference, int material = 0, int materialMap = MATERIAL_MAP_DIFFUSE);
            void UnloadAll();
            void RegenerateModels();
        }

        namespace viewport
        {
            class sh_camera
            {
                sh::Dimension m_dimension2D = { 0 };
                sh::Dimension m_dimension3D = { 0 };
                //Vector3 m_target3D = { 0 };
                Camera3D m_3DCam = { 0 };
                Camera2D m_2DCam = { 0 };
            public:
                Camera2D getCamera2D() { return m_2DCam; };
                Camera3D getCamera3D() { return m_3DCam; };

                void setDimension2D(sh::Dimension dimension) { m_dimension2D = dimension; };
                sh::Dimension getDimension2D() { return m_dimension2D; };

                void setDimension3D(sh::Dimension dimension) { m_dimension3D = dimension; };
                sh::Dimension getDimension3D() { return m_dimension3D; };

                Vector3 get3DTarget() { return m_3DCam.target; };
                // void set3DTarget(Vector3 target) { m_target3D = target; };

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
            
            inline Color bgDefault = BLACK;
            void queueHUD(sh::renderType type, std::string content, unsigned int layer = 0, sh::Dimension dDimension = sh::Dimension{ 0 }, Color dColor = WHITE);
            void queueHUD(sh::renderType type, sh::theatrics::detail::theatric* theatric, unsigned int layer = 0);
            void queue3D(sh::renderType type, std::string content, unsigned int layer = 0, sh::Dimension dDimension = sh::Dimension{ 0 }, Color dColor = WHITE);
            void queue3D(sh::renderType type, sh::theatrics::detail::theatric* theatric, unsigned int layer = 0);
            void queue2D(sh::renderType type, std::string content, unsigned int layer = 0, sh::Dimension dDimension = sh::Dimension{ 0 }, Color dColor = WHITE);
            void queue2D(sh::renderType type, sh::theatrics::detail::theatric* theatric, unsigned int layer = 0);
            void drawScreen(sh::auditorium::viewport::sh_camera cam);
        }
    }
}
