/**
 * @author    Jani Haippo
 * @version   03.2015
 * 
 * */


#ifndef SR_CAMERA_H
#define SR_CAMERA_H

#define GLM_FORCE_RADIANS 

#include "../framework/ICamera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
typedef float Real;

namespace SR
{
  /**
   * Camera
   **/
  class Camera : public ICamera
  {
    public:
      Camera();
      ~Camera();
      void              SetProjection(Real fov, Real aspect, Real near, Real far);
      
      void              LookAt( const Vector3& eye, const Vector3& target, const Vector3& up);
      
      Matrix4&          GetViewMatrix();
      Matrix4&          GetProjectionMatrix();
  /*    
      const Matrix4&    GetViewMatrix() const;
      const Matrix4&    GetProjectionMatrix() const;
    */  
      bool              MatrixNeedsUpdate();
      void              UpdateMatrix();
      
      
    private:
      Vector3     m_position;
      Vector3     m_up;
      Vector3     m_target;
      
      Matrix4     m_viewMatrix;
      Matrix4     m_projectionMatrix;
      
      bool        m_matrixNeedsUpdate;
      Real        m_fov;
      Real        m_aspect;
      Real        m_near;
      Real        m_far;
  };
}
#endif