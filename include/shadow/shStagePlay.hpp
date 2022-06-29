#pragma once
// ---------- Include ----------
#include <shAuditorium.hpp>
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
    //Actors have lua virtual machines attatched to them
    class actor : public detail::theatric{
    protected:
        lua_State *L;
    };
    class prop : public detail::theatric{
        
    };
}}