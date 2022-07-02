#pragma once
// ---------- Include ----------
#include <shadow.hpp>
#include <vector>
// ---------- Shadow ----------

namespace sh{namespace theatrics{
    //You don't need to define a theatric normally since props do the same thing
    namespace detail {
        class theatric 
        {
        protected:
            sh::Dimension m_dimension = { 0 };
        public:
            sh::Dimension getDimension() { return m_dimension; };
            virtual void renderMe() = 0;
        };
    }

    //Actors have a pointer to their actorHelper
    class actor : public detail::theatric
    {
    protected:
        unsigned int id = 0;
    public:
        unsigned int getId() { return id; }
        //Call your helper function
        virtual void initializeHelper() = 0;
    };

    //Actor helpers should only have 1 instance at a time
    class actorHelper
    {
    protected:
        lua_State *L = luaL_newstate();
        std::vector<sh::theatrics::actor*> actorList;
    public:
        unsigned int assignID(sh::theatrics::actor* newActor);
        virtual void start(unsigned int id) = 0;
        ~actorHelper();
    };
    
    //Props only have a position and render function
    class prop : public detail::theatric
    {

    };
}}