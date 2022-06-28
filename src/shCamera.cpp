#include <shAuditorium.hpp>
#include <math.h>


sh::auditorium::viewport::sh_camera::sh_camera(int fov)
{
    m_dimension3D.Size((float)(fov));
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
    // m_3DCam.target = m_target3D;
    //sin(m_dimension3D.Pitch) * sin(m_dimension3D.Yaw), cos(m_dimension3D.Pitch), sin(m_dimension3D.Pitch) * cos(m_dimension3D.Yaw)
    ///m_3DCam.up = Vector3();
    float roll = m_dimension3D.Roll + 90.0f;

    float forward[3];

    forward[0] = sin(m_dimension3D.Yaw * DEG2RAD) * cos(m_dimension3D.Pitch * DEG2RAD);
    forward[1] = sin(m_dimension3D.Pitch * DEG2RAD);
    forward[2] = cos(m_dimension3D.Yaw * DEG2RAD) * cos(m_dimension3D.Pitch * DEG2RAD);

    m_3DCam.target = Vector3{(m_dimension3D.X + forward[0]), (m_dimension3D.Y + forward[1]), (m_dimension3D.Z + forward[2])};

    m_3DCam.up = Vector3{sin(m_dimension3D.Roll * DEG2RAD), cos(m_dimension3D.Roll * DEG2RAD), 0.0f};
}