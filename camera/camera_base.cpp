#include "camera_base.h"

Camera_Base::Camera_Base()
{
  m_fieldOfView = MATH::DegToRad(45.0f);
  m_nearPlane = 0.2f;
  m_farPlane = 100.0f;
  m_aspectRatio = 640/480;

  m_target = Vector3(0.0f,0.0f,0.0f);
  m_position = Vector3(0.0f,20.0f,0.0f);
  m_up = Vector3(0.0f,0.0f,1.0f);
  m_viewMatrix = glm::lookAt( m_position, m_target, m_up);
  m_projectionMatrix = glm::perspective( m_fieldOfView,
                                        m_aspectRatio,
                                        m_nearPlane,
                                        m_farPlane);
}

Camera_Base::~Camera_Base()
{

}

void Camera_Base::SetPosition(const Vector3& position)
{
  m_position = position;
}

const Vector3& Camera_Base::GetPosition() const
{
  return m_position;
}

void Camera_Base::SetTarget(const Vector3& target)
{
  m_target = target;
}

const Vector3& Camera_Base::GetTarget() const
{
  return m_target;
}

Matrix4& Camera_Base::GetViewMatrix()
{
  return m_viewMatrix;
}

Matrix4& Camera_Base::GetProjectionMatrix()
{
  return m_projectionMatrix;
}



