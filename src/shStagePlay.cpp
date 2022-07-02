// ---------- Include ----------
#include <shStagePlay.hpp>
#include <shAuditorium.hpp>

// ---------- Shadow ----------

unsigned int sh::theatrics::actorHelper::assignID(sh::theatrics::actor* newActor)
{
    if(newActor->getId() != 0)
    {
        std::cout << "[SHADOW - WARNING] This actor already exists." << std::endl;
        return newActor->getId();
    }
    actorList.push_back(newActor);
    return actorList.size();
}
    
sh::theatrics::actorHelper::~actorHelper()
{
    lua_close(L);
    for(auto inst : actorList)
    {
        delete inst;
    }
    actorList.clear();
}