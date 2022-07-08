#pragma once
// ---------- Include ----------
#include <shadow.hpp>
// ---------- Shadow ----------

namespace sh{namespace theatrics{
    //You don't need to define a theatric normally since props do the same thing
    namespace detail {
        class theatric 
        {
        protected:
            sh::Dimension m_dimension = { 0 };
        public:
            sh::Dimension getDimension() { return m_dimension; }
            void setDimension(sh::Dimension i_dimension) { m_dimension = i_dimension; }
            virtual void renderMe() = 0;
        };
    }

    //Actors have a pointer to their actorHelper
    class actor : public detail::theatric
    {
    private:
        friend void clear();
    protected:
        virtual ~actor();
        unsigned int actorType = 0;
        unsigned int actorID = 0;
    public:
        //Call your helper function
        unsigned int getActorType() { return actorType; };
        virtual void update() = 0;
        actor() = delete;
        actor(unsigned int type);
    };

    //Actor helpers should only have 1 instance at a time
    class actorHelper
    {
    protected:
        lua_State *L = luaL_newstate();
        unsigned int actorType = 0;
    public:
        virtual void CreateActor() = 0;
        virtual void DestroyActor(unsigned int actorID) = 0;
        virtual ~actorHelper();
        virtual void update(sh::theatrics::actor* act_ptr) = 0;
    };
    
    //Props only have a position and render function
    class prop : public detail::theatric
    {

    };

    sh::theatrics::actor* getActorPointer(unsigned int actorID);
    //Run at startup
    void start();
    //This is run every frame after GameLoopPriority
    void update();
    //Clear out the actor list
    void clear();
    //Clears actor slot
    void clearSlot(unsigned int actorID);
}}