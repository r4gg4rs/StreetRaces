#include "camera_base.h"

Camera_Base::Camera_Base()
{

}

Camera_Base::~Camera_Base()
{

}

Matrix4& Camera_Base::GetViewMatrix()
{
  return m_viewMatrix;
}

Matrix Camera_Base::GetProjectionMatrix()
{
  return m_projectionMatrix;
}


