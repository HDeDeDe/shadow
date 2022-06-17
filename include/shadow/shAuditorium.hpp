#pragma once
// ---------- Include ----------

#include <shadow.hpp>
#include <shSys.hpp>

// ---------- Shadow ----------
namespace sh {namespace auditorium{
    void createWindow();
    void closeWindow();
    void reloadWindow();
    void resizeWindow(int width, int height);
    void renameWindow(const char* name);
    bool isActive();
    void textureLoadAll();
    void textureUnloadAll();

    //Textures are actively managed by Auditorium
    namespace texture
    {
        class sh_Texture
        {
        public:
            sh_Texture() = delete;
            bool isLoadedVram();
            //Texture& getTextureAddress();
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
		    //Block constructors
		    sh_TextureManager(const sh_TextureManager&) = delete;

		    //Access functions
		    static sh_TextureManager& Get();
		    //Create a new texture from a file
		    inline static void Create(std::string texture_reference, std::string file_location) { return Get().in_Create(texture_reference, file_location); };
		    //Destroy referenced texture
		    inline static void Destroy(std::string texture_reference) { return Get().in_Destroy(texture_reference); };
		    //Load texture into video memory
		    inline static void Load(std::string texture_reference) { return Get().in_Load(texture_reference); };
		    //Unload texture from video memory
		    inline static void Unload(std::string texture_reference) { return Get().in_Unload(texture_reference); };
		    //Get reference to texture, it's recomended to cache this for later use
		    //inline static sh_Texture* getTexturePointer(std::string texture_reference) { return Get().in_getTexturePointer(texture_reference); };
	    private:
		    //Internal functions
		    void in_Create(std::string texture_reference, std::string file_location);
		    void in_Destroy(std::string texture_reference);
		    void in_Load(std::string texture_reference);
		    void in_Unload(std::string texture_reference);
		    //sh_Texture* in_getTexturePointer(std::string texture_reference);
		    //Block constructors
		    sh_TextureManager& operator=(sh_TextureManager const&);
		    sh_TextureManager();
        };
    }
}}
