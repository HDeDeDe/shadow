// ---------- Include ----------

#include <shTexture.hpp>
#include <shSys.hpp>
#include <missing.c>

// ---------- Shadow ----------

Image missing_ram = Image{ MISSING_DATA, MISSING_WIDTH, MISSING_HEIGHT, 1, MISSING_FORMAT };
Texture missing_vram = Texture{ 0 };

//sh_Texture
sh::texture::sh_Texture::sh_Texture(std::string texture_location, std::string texture_reference) 
{
	m_ram = LoadImage(texture_location.c_str());
    m_texture_reference = texture_reference;
}

// Texture& sh::texture::sh_Texture::getTextureAddress()
// {
//     if(!sh::auditorium::isActive())
//     {
//         shSys::panic(sh::sh_Panic::panic_no_gl_context);
//     }
//     if(!m_vram_loaded)
//     {
//         std::cout << "[SHADOW - WARNING] An unloaded texture was referenced, returning missing texture." << std::endl;
//         return *missing_vram;
//     }
//     return *m_vram;
// }
std::string sh::texture::sh_Texture::getTextureReference()
{
    return m_texture_reference;
}
bool sh::texture::sh_Texture::isLoadedVram()
{
    return m_vram_loaded;
}
//sh_TextureManager
std::unordered_map<std::string, sh::texture::sh_Texture> texture_map;

sh::texture::sh_TextureManager::sh_TextureManager()
{
	
}
sh::texture::sh_TextureManager& sh::texture::sh_TextureManager::Get() 
{
	using namespace sh::texture;
	static sh_TextureManager s_Instance;
	return s_Instance;
}
void sh::texture::sh_TextureManager::in_Create(std::string texture_reference, const char* file_location)
{
    if (texture_reference == "missing")
	{
		std::cout << "[SHADOW - WARNING] \"missing\" is a reserved texture name." << std::endl;
		return;
	}
    if (texture_map.find(texture_reference) != texture_map.end())
	{
		std::cout << "[SHADOW - WARNING] " << texture_reference << " conflicts with an already existing texture." << std::endl;
		return;
	}
    sh::texture::sh_Texture temp_texture = sh::texture::sh_Texture{file_location, texture_reference};
    texture_map[texture_reference] = temp_texture;
}
void sh::texture::sh_TextureManager::in_Destroy(std::string texture_reference)
{
    
}
void sh::texture::sh_TextureManager::in_Load(std::string texture_reference)
{
    
}
void sh::texture::sh_TextureManager::in_Unload(std::string texture_reference)
{
    
}
//sh::texture::sh_Texture* sh::texture::sh_TextureManager::in_getTexturePointer(std::string texture_reference)
//{
//    
//}