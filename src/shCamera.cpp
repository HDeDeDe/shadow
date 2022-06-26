#include <shAuditorium.hpp>

sh::auditorium::viewport::sh_camera::sh_camera(int fov)
{
    m_dimension3D.Size((float)(fov));
    m_dimension3D.Yaw = 1.0f;
    m_3DCam.projection = CAMERA_PERSPECTIVE;
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

    m_3DCam.fovy = m_dimension3D.Size();
    m_3DCam.position = Vector3{m_dimension3D.X, m_dimension3D.Y, m_dimension3D.Z};
    m_3DCam.up = Vector3{m_dimension3D.Roll, m_dimension3D.Yaw, m_dimension3D.Pitch};
    m_3DCam.target = m_target3D;
}