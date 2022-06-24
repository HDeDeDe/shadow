// ---------- Include ----------
#include <shAuditorium.hpp>
#include <missing.c>
#include <shSys.hpp>

// ---------- Shadow ----------

Image missing_ram = Image{ MISSING_DATA, MISSING_WIDTH, MISSING_HEIGHT, 1, MISSING_FORMAT };
Texture missing_vram = Texture{ 0 };

void shSys::initTextureMan()
{
	missing_vram = LoadTextureFromImage(missing_ram);
}

//sh_Texture
sh::auditorium::texture::sh_Texture::sh_Texture(std::string texture_location, std::string texture_reference) 
{
	if(FileExists(texture_location.c_str()))
	{
		m_ram = LoadImage(texture_location.c_str());
	}
	else
	{
		std::cout << "[SHADOW - WARNING] " << texture_location << " could not be found, loading missing texture."<< std::endl;
		m_ram = ImageCopy(missing_ram);
	}
    m_texture_reference = texture_reference;
}

Texture sh::auditorium::texture::sh_Texture::getTexture()
{
    if(!sh::auditorium::isActive())
    {
        shSys::panic(sh::sh_Panic::panic_no_gl_context);
    }
    if(!m_vram_loaded)
    {
        std::cout << "[SHADOW - WARNING] An unloaded texture was referenced, returning missing texture." << std::endl;
        return missing_vram;
    }
    return m_vram;
}
std::string sh::auditorium::texture::sh_Texture::getTextureReference()
{
    return m_texture_reference;
}
bool sh::auditorium::texture::sh_Texture::isLoadedVram()
{
    return m_vram_loaded;
}
sh::auditorium::texture::sh_Texture::~sh_Texture()
{
	m_texture_reference.erase();
	UnloadImage(m_ram);
	//Textures must be unloaded from video memory before destroying them
	if (m_vram_loaded == true) {
		m_vram_loaded = false;
		UnloadTexture(m_vram);
		if (!shSys::isPanicing() && sh::auditorium::isActive()) {
			shSys::panic(sh::sh_Panic::panic_loaded_texture);
		}
	}
}
//sh_TextureManager ----------------------

std::unordered_map<std::string, sh::auditorium::texture::sh_Texture*> texture_map;

sh::auditorium::texture::sh_TextureManager::sh_TextureManager()
{
	using namespace sh::auditorium::texture;
	typedef std::pair<const char*, sh_Texture*> texturePtr;
	sh_Texture* temp_ptr = new sh_Texture("", "missing");
    texture_map.insert(texturePtr("missing", temp_ptr));
}

sh::auditorium::texture::sh_TextureManager& sh::auditorium::texture::sh_TextureManager::Get() 
{
	using namespace sh::auditorium::texture;
	static sh_TextureManager s_Instance;
	return s_Instance;
}

void sh::auditorium::texture::sh_TextureManager::in_Create(std::string texture_reference, std::string file_location)
{
	using namespace sh::auditorium::texture;
	typedef std::pair<const char*, sh_Texture*> texturePtr;
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
	sh_Texture* temp_ptr = new sh_Texture(file_location, texture_reference);
    texture_map.insert(texturePtr(texture_reference.c_str(), temp_ptr));
	std::cout << "[SHADOW - INFO] " << texture_reference << " was created." << std::endl;
	return;
}

void sh::auditorium::texture::sh_TextureManager::in_Destroy(std::string texture_reference)
{
	using namespace sh::auditorium::texture;
    if (texture_reference == "missing")
	{
		std::cout << "[SHADOW - WARNING] \"missing\" is a reserved texture name." << std::endl;
		return;
	}
    if (texture_map.find(texture_reference) == texture_map.end())
	{
		std::cout << "[SHADOW - WARNING] " << texture_reference << " does not exist in the texture map." << std::endl;
		return;
	}
	sh_Texture* temp_ptr = texture_map.at(texture_reference);
	delete temp_ptr;
	texture_map.erase(texture_reference);
	std::cout << "[SHADOW - INFO] " << texture_reference << " was destroyed." << std::endl;
	return;
}

void sh::auditorium::texture::sh_TextureManager::in_Load(std::string texture_reference)
{
    using namespace sh::auditorium::texture;
    if (texture_reference == "missing")
	{
		std::cout << "[SHADOW - WARNING] \"missing\" is a reserved texture name." << std::endl;
		return;
	}
    if (texture_map.find(texture_reference) == texture_map.end())
	{
		std::cout << "[SHADOW - WARNING] " << texture_reference << " does not exist in the texture map." << std::endl;
		return;
	}
	sh_Texture *temp_ptr = texture_map.at(texture_reference);
	if(temp_ptr->m_vram_loaded == true)
	{
		std::cout << "[SHADOW - WARNING] " << texture_reference << " is already loaded into video memory." << std::endl;
		return;
	}
	temp_ptr->m_vram = LoadTextureFromImage(temp_ptr->m_ram);
	temp_ptr->m_vram_loaded = true;
	std::cout << "[SHADOW - INFO] " << texture_reference << " was loaded." << std::endl;
	return;
}

void sh::auditorium::texture::sh_TextureManager::in_Unload(std::string texture_reference)
{
    using namespace sh::auditorium::texture;
    if (texture_reference == "missing")
	{
		std::cout << "[SHADOW - WARNING] \"missing\" is a reserved texture name." << std::endl;
		return;
	}
    if (texture_map.find(texture_reference) == texture_map.end())
	{
		std::cout << "[SHADOW - WARNING] " << texture_reference << " does not exist in the texture map." << std::endl;
		return;
	}
	sh_Texture* temp_ptr = texture_map.at(texture_reference);
	if(temp_ptr->m_vram_loaded == false)
	{
		std::cout << "[SHADOW - WARNING] " << texture_reference << " is not loaded into video memory." << std::endl;
		return;
	}
	UnloadTexture(temp_ptr->m_vram);
	temp_ptr->m_vram_loaded = false;
	std::cout << "[SHADOW - INFO] " << texture_reference << " was unloaded." << std::endl;
	return;
}

sh::auditorium::texture::sh_Texture* sh::auditorium::texture::sh_TextureManager::in_GetTexturePointer(std::string texture_reference)
{
	using namespace sh::auditorium::texture;
    if (texture_map.find(texture_reference) == texture_map.end())
	{
		std::cout << "[SHADOW - WARNING] " << texture_reference << " does not exist in the texture map, returning missing." << std::endl;
		return texture_map.at("missing");
	}
	return texture_map.at(texture_reference);
}

Texture sh::auditorium::texture::sh_TextureManager::in_GetTexture(std::string texture_reference)
{
	using namespace sh::auditorium::texture;
    if (texture_map.find(texture_reference) == texture_map.end())
	{
		std::cout << "[SHADOW - WARNING] " << texture_reference << " does not exist in the texture map, returning missing." << std::endl;
		return missing_vram;
	}
	sh_Texture* temp_ptr = texture_map.at(texture_reference);
	return temp_ptr->getTexture();
}

void sh::auditorium::texture::sh_TextureManager::in_TextureDeloadAll()
{
	using namespace sh::auditorium::texture;
	for (auto& [texture_reference, texture_store] : texture_map)
	{
		if(texture_store->m_vram_loaded)
		{
			UnloadTexture(texture_store->m_vram);
		}
	}
	UnloadTexture(missing_vram);
	return;
}

void sh::auditorium::texture::sh_TextureManager::in_TextureReloadAll()
{
	using namespace sh::auditorium::texture;
	for (auto& [texture_reference, texture_store] : texture_map)
	{
		if(texture_store->m_vram_loaded)
		{
			texture_store->m_vram = LoadTextureFromImage(texture_store->m_ram);
		}
	}
	missing_vram = LoadTextureFromImage(missing_ram);
	return;
}

//Cleanup
void shSys::cleanTextureMan()
{
	sh::auditorium::texture::sh_TextureManager::CleanTextureMan();
}

void sh::auditorium::texture::sh_TextureManager::in_CleanTextureMan()
{
	for (auto& [texture_reference, texture_store] : texture_map)
	{
		delete texture_store;
	}
	texture_map.clear();
}