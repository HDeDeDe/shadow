#include <shAuditorium.hpp>

void sh::auditorium::viewport::sh_camera::updateCameras()
{
    m_2DCam.rotation = m_dimension2D.Roll;
    m_2DCam.zoom = m_dimension2D.Size();
    
}