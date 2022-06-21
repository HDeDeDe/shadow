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
        public:
            sh::Dimension getDimension() { return m_dimension; }
        }
    }
    //Actors have lua virtual machines attatched to them
    class actor : public detail::theatric{
        
        virtual lua_State *L = 0;
        
    };
    class prop : public detail::theatric{
        
    };
    class stage : public detail::theatric{
        virtual sh::auditorium::texture::sh_Texture* m_texture = 0;
        Mesh m_mesh = { 0 };
    public:
        bool visible = true;
        virtual void renderReady() = 0;
    };
    class practical : public prop {

    }
}}