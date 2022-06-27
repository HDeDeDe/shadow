// ---------- Include ----------
#include <shAuditorium.hpp>
#include <shSys.hpp>
#include <vector>
// ---------- Shadow ----------

bool modelManInit = false;
Model missing = { 0 };

void shSys::initModelMan()
{
    if(FileExists("./missing.iqm"))
    {
        missing = LoadModel("./missing.iqm");
        modelManInit = true;
    }
    else shSys::panic(sh::sh_Panic::panic_init_fail);
}

struct sh_material
{
    sh::auditorium::texture::sh_Texture* m_texture;
    int m_materialMap;
};

struct sh_Model
{
    Model m_model = { 0 };
    std::vector<sh_material> m_materials;
    sh_Model() = delete;
    sh_Model(std::string file_location)
    {
        if(!FileExists(file_location.c_str()))
        {
            std::cout << "[SHADOW - WARNING] The requested model does not exist, loading missing." << std::endl;
            m_model = missing;
            return;
        }
        m_model = LoadModel(file_location.c_str());
    }
    ~sh_Model()
    {
        UnloadModel(m_model);
    }
    void addMaterial(int material, int materialMap, std::string texture_reference)
    {
        auto matPos = m_materials.begin() + material;
        m_materials.insert(matPos, sh_material{sh::auditorium::texture::sh_TextureManager::GetTexturePointer(texture_reference), materialMap});
    }
    void generateMaterials()
    {
        for (int i = 0; i < m_materials.size(); i++)
        {
            m_model.materials[i] = LoadMaterialDefault();
            SetMaterialTexture(&m_model.materials[i], m_materials[i].m_materialMap, m_materials[i].m_texture->getTexture());
        }
    }
    void regenerateModel()
    {
        
        for(int i = 0; i < m_model.meshCount; i++)
        {
            m_model.meshes[i].vaoId = 0;
            MemFree(m_model.meshes[i].vboId);
            m_model.meshes[i].vboId = NULL;
            UploadMesh(&m_model.meshes[i], (m_model.meshes[i].boneWeights != nullptr));
        }
    }
};

std::unordered_map<std::string, sh_Model*> modelMap;

void sh::auditorium::model::Load(std::string model_reference, std::string file_location)
{
	using namespace sh::auditorium::model;
	typedef std::pair<const char*, sh_Model*> modelPtr;
    if (model_reference == "missing")
	{
		std::cout << "[SHADOW - WARNING] \"missing\" is a reserved model name." << std::endl;
		return;
	}
    if (modelMap.find(model_reference) != modelMap.end())
	{
		std::cout << "[SHADOW - WARNING] " << model_reference << " conflicts with an already existing model." << std::endl;
		return;
	}
	sh_Model* temp_ptr = new sh_Model(file_location);
    modelMap.insert(modelPtr(model_reference.c_str(), temp_ptr));
	std::cout << "[SHADOW - INFO] " << model_reference << " was created." << std::endl;
	return;
}

void sh::auditorium::model::Unload(std::string model_reference)
{
    using namespace sh::auditorium::model;
    if (model_reference == "missing")
	{
		std::cout << "[SHADOW - WARNING] \"missing\" is a reserved model name." << std::endl;
		return;
	}
    if (modelMap.find(model_reference) == modelMap.end())
	{
		std::cout << "[SHADOW - WARNING] " << model_reference << " is not a valid model." << std::endl;
		return;
	}
    sh_Model* temp_ptr = modelMap.at(model_reference);
    delete temp_ptr;
    modelMap.erase(model_reference);
    std::cout << "[SHADOW - INFO] " << model_reference << " was destroyed." << std::endl;
    return;
}

Model sh::auditorium::model::GetModel(std::string model_reference)
{
    using namespace sh::auditorium::model;
    if (model_reference == "missing")
	{
		return missing;
	}
    if (modelMap.find(model_reference) == modelMap.end())
	{
		std::cout << "[SHADOW - WARNING] " << model_reference << " is not a valid model. Returning missing model." << std::endl;
		return missing;
	}
    sh_Model* temp_ptr = modelMap.at(model_reference);
    return temp_ptr->m_model;
}

void sh::auditorium::model::UnloadAll()
{
    using namespace sh::auditorium::model;
	UnloadModel(missing);
	return;
}

void sh::auditorium::model::SetModelMaterial(std::string model_reference, std::string texture_reference, int material, int materialMap)
{
    using namespace sh::auditorium::model;
    if (model_reference == "missing")
	{
		std::cout << "[SHADOW - WARNING] \"missing\" is a reserved model name." << std::endl;
		return;
	}
    if (modelMap.find(model_reference) == modelMap.end())
	{
		std::cout << "[SHADOW - WARNING] " << model_reference << " is not a valid model." << std::endl;
		return;
	}
    sh_Model* temp_ptr = modelMap.at(model_reference);
    temp_ptr->addMaterial(material, materialMap, texture_reference);
    temp_ptr->generateMaterials();
    return;
}

void sh::auditorium::model::RegenerateModels()
{
    for(auto& [model_reference, model_store] : modelMap)
    {
        model_store->regenerateModel();
        model_store->generateMaterials();
    }
    if(modelManInit) missing = LoadModel("./missing.iqm");
    std::cout << "[SHADOW - INFO] Models reloaded." << std::endl;
}