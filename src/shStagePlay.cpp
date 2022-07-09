// ---------- Include ----------
#include <shStagePlay.hpp>
#include <shAuditorium.hpp>
#include <vector>
// ---------- Shadow ----------

std::vector<sh::theatrics::actor*> actorList;

sh::theatrics::actor::~actor()
{}

sh::theatrics::actor::actor(unsigned int type)
{
    if(type == 0) delete this;
    for(unsigned int i = 1; i < actorList.size(); i++)
    {
        if(actorList[i] == nullptr)
        {
            actorList[i] = this;
            actorType = type;
            actorID = i;
            return;
        }
    }
    actorType = type;
    actorList.push_back(this);
    actorID = actorList.size() - 1;
}

sh::theatrics::actorHelper::~actorHelper()
{
    lua_close(L);
}

void sh::theatrics::start()
{
    if(actorList.begin() == actorList.end())
    {
        actorList.push_back(nullptr);
    }
    else std::cout << "[SHADOW - WARNING] Actor list has already been initialized." << std::endl;
}

void sh::theatrics::update()
{
    for(unsigned int i = 1; i < actorList.size(); i++)
    {
        if(actorList[i] != nullptr)actorList[i]->update();
    }
}

void sh::theatrics::clear()
{
    for(unsigned int i = 1; i < actorList.size(); i++)
    {
        if(actorList[i] != nullptr) {
            delete actorList[i];
            actorList[i] = nullptr;
            }
    }
    actorList.clear();
}

sh::theatrics::actor* sh::theatrics::getActorPointer(unsigned int actorID)
{
    return actorList[actorID];
}

void sh::theatrics::clearSlot(unsigned int actorID)
{
    delete actorList[actorID];
    actorList[actorID] = nullptr;
}