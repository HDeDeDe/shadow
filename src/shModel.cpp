// ---------- Include ----------
#include <shAuditorium.hpp>
#include <shSys.hpp>
// ---------- Shadow ----------

Model missing = { 0 };

void shSys::initModelMan()
{
    if(FileExists("./missing.iqm"))
    {
        missing = LoadModel("./missing.iqm");
    }
    else shSys::panic(sh::sh_Panic::panic_init_fail);
}

struct sh_Model
{
    Model m_model = { 0 };
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