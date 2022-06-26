#pragma once
// ---------- Include ----------
#include <shAuditorium.hpp>
// ---------- Shadow ----------

namespace sh{namespace theatrics{
    //You don't need to define a theatric normally since props do the same thing
    namespace detail {
        class theatric 
        {
            sh::Dimension m_dimension = { 0 };
            bool m_visible = false;
        public:
            sh::Dimension getDimension() { return m_dimension; };
            void setVisible(bool vis = true) { m_visible = vis; };
            virtual void renderMe() = 0;
        };
    }
    //Actors have lua virtual machines attatched to them
    class actor : public detail::theatric{
        lua_State *L;
        
    };
    class prop : public detail::theatric{
        
    };
    class stage : public detail::theatric{

    };
}}