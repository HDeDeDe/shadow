#include <shAuditorium.hpp>

sh::auditorium::viewport::sh_camera::sh_camera(int fov)
{
    m_dimension3D.Size((float)(fov));
}

void sh::auditorium::viewport::sh_camera::setOrigin()
{
    m_2DCam.offset = Vector2{(float)(sh::auditorium::getResolutionX() / 2), (float)(sh::auditorium::getResolutionY() / 2)};
}

void sh::auditorium::viewport::sh_camera::updateCameras()
{
    m_2DCam.rotation = m_dimension2D.Roll;
    m_2DCam.zoom = m_dimension2D.Size();
    m_2DCam.target = Vector2{m_dimension2D.X, m_dimension2D.Y};
}