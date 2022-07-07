// ---------- Includes ----------
#include <shadow.hpp>
#include <shLua.hpp>
#include <shStagePlay.hpp>
#include <shAuditorium.hpp>
#include <shImGuiBuiltin.hpp>

// ---------- Shadow ----------

void sh::debug::DebugImgui()
{
    ImGui::Text("FPS: %d", GetFPS());
    ImGui::Checkbox("Render Background", &isBG);
    ImGui::Checkbox("Render 2D", &is2D);
    ImGui::Checkbox("Render 3D", &is3D);
    ImGui::Checkbox("Render HUD", &isHUD);

    float dbg_colors[4] = {((float)sh::auditorium::draw::bgDefault.r / 255.0f), ((float)sh::auditorium::draw::bgDefault.g  / 255.0f), ((float)sh::auditorium::draw::bgDefault.b / 255.0f), ((float)sh::auditorium::draw::bgDefault.a / 255.0f)};
    ImGui::ColorEdit4("Background Color", dbg_colors);
    sh::auditorium::draw::bgDefault = CLITERAL(Color){(unsigned char)(dbg_colors[0] * 255.0f),(unsigned char)(dbg_colors[1] * 255.0f),(unsigned char)(dbg_colors[2]* 255.0f),(unsigned char)255};
    
    sh::Dimension temp_cam2D =  sh::auditorium::viewport::GlobalCamera.getDimension2D();
    sh::Dimension temp_cam3D =  sh::auditorium::viewport::GlobalCamera.getDimension3D();
    Vector3 temp_3DTarg = sh::auditorium::viewport::GlobalCamera.get3DTarget();

    float dbg_3dCamPos[3] = {temp_cam3D.X, temp_cam3D.Y, temp_cam3D.Z};
    ImGui::DragFloat3("Camera3D Position", dbg_3dCamPos);

    float dbg_3dCamRot[3] = {temp_cam3D.Roll, temp_cam3D.Yaw, temp_cam3D.Pitch};
    ImGui::DragFloat3("Camera3D Rotation", dbg_3dCamRot);

    float dbg_3dCamTarg[3] = {temp_3DTarg.x, temp_3DTarg.y, temp_3DTarg.z};
    // ImGui::Text("Camera3D Target X: %f", dbg_3dCamTarg[0]);
    // ImGui::Text("Camera3D Target Y: %f", dbg_3dCamTarg[1]);
    // ImGui::Text("Camera3D Target Z: %f", dbg_3dCamTarg[2]);

    float dbg_2dCamPos[2] = {temp_cam2D.X, temp_cam2D.Y};
    ImGui::DragFloat2("Camera2D Position", dbg_2dCamPos);

    temp_cam2D.X = dbg_2dCamPos[0];
    temp_cam2D.Y = dbg_2dCamPos[1];
    
    temp_cam3D.X = dbg_3dCamPos[0];
    temp_cam3D.Y = dbg_3dCamPos[1];
    temp_cam3D.Z = dbg_3dCamPos[2];

    // temp_3DTarg.x = dbg_3dCamTarg[0];
    // temp_3DTarg.y = dbg_3dCamTarg[1];
    // temp_3DTarg.z = dbg_3dCamTarg[2];

    temp_cam3D.Roll = dbg_3dCamRot[0];
    temp_cam3D.Yaw = dbg_3dCamRot[1];
    temp_cam3D.Pitch = dbg_3dCamRot[2];

    sh::auditorium::viewport::GlobalCamera.setDimension3D(temp_cam3D);
    sh::auditorium::viewport::GlobalCamera.setDimension2D(temp_cam2D);
    // sh::auditorium::viewport::GlobalCamera.set3DTarget(temp_3DTarg);

    if(ImGui::Button("Quit")) sh::play::Exit(true);
}