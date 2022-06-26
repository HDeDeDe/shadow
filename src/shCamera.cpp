#include <shAuditorium.hpp>

sh::auditorium::viewport::sh_camera::sh_camera(int fov)
{
    m_dimension3D.Size((float)(fov));
    m_3DCam.fovy = m_dimension3D.Size();
    m_3DCam.up = Vector3{0.0f, 1.0f, 0.0f};
    m_3DCam.projection = CAMERA_PERSPECTIVE;
    m_2DCam.zoom = 1.0f;
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
    //TODO: Figure out how to convert the target system to a yaw-pitch-roll system.

}
void sh::auditorium::viewport::sh_camera::setCamPos(Vector3 pos3, Vector2 pos2)
{
    m_3DCam.position = pos3;
    m_2DCam.target = pos2;
}