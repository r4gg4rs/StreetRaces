#ifndef STREETRACER_CAMERA_BASE_H
#define STREETRACER_CAMERA_BASE_H

#include "icamera.h"

class Camera_Base : public ICamera
{

 public:
  Camera_Base();
  ~Camera_Base();
  

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
};
#endif
