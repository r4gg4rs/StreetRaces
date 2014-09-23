#ifndef STREETRACER_CAMERA_BASE_H
#define STREETRACER_CAMERA_BASE_H

#include "icamera.h"

#include "../math/math_inc.h"

class Camera_Base : public ICamera
{

 public:
  Camera_Base();
  ~Camera_Base();

  void SetPosition(const Vector3& position);
  const Vector3& GetPosition() const;

  void SetTarget(const Vector3& target);
  const Vector3& GetTarget() const;

  virtual Matrix4& GetViewMatrix();
  virtual Matrix4& GetProjectionMatrix(); 
 private:

  Matrix4    m_viewMatrix;
  Matrix4    m_projectionMatrix;

  Vector3    m_position;
  Vector3    m_target;
  Vector3    m_up;

  float     m_fieldOfView;
  float     m_nearPlane;
  float     m_farPlane;
  float     m_aspectRatio;

};
#endif
