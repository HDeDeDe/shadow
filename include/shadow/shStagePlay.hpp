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
            bool m_is3D = false;
        public:
            sh::Dimension getDimension() { return m_dimension; }
        };
    }
    //Actors have lua virtual machines attatched to them
    class actor : public detail::theatric{
        lua_State *L;
        
    };
    class prop : public detail::theatric{
        
    };
    class stage : public detail::theatric{
        sh::auditorium::texture::sh_Texture* m_texture;
        Mesh m_mesh = { 0 };
    public:
        bool visible = true;
        virtual void renderReady() = 0;
    };
}}