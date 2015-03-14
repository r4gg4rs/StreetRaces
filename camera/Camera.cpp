#include "Camera.h"
#include "../core/CoreEngine.h"
#include "../framework/IRenderer.h"
#include <iostream>

using namespace SR;

Camera::Camera()// : m_fov(45), m_near(0.1), m_far(1000), m_matrixNeedsUpdate(true)
{
 int* view = new int[4];
 view[2] = 100;
 view[3] = 100;
 
 IRenderer* renderer = Singleton<CoreEngine>::GetSingletonPtr()->GetRenderer();
 if(renderer != NULL) view = renderer->GetViewport();

 // std::cout << "x " << view[2] << " y " << view[3] << std::endl;
  
   m_aspect = view[2] / view[3];
  m_fov = 45;
  m_near = 0.1f;
  m_far = 1000.0f;
  
  m_position = Vector3(0.0f, 1.0f,10.0f);
  //m_target =Vector3(m_position.x, m_position.y, m_position.z + 1.0f);
  m_target = Vector3(0.0, 0.0, 0.0);
  m_up = Vector3(0.0f, 1.0f, 0.0f);
  m_up.Normalize();
  
  m_matrixNeedsUpdate = true;
}

Camera::~Camera()
{
  
}

void Camera::SetProjection(Real fov, Real aspect, Real near, Real far)
{
  m_fov = fov;
  m_aspect = aspect;
  m_near = near;
  m_far = far;
  m_matrixNeedsUpdate = true;
  
  /*
  // Moved to UpdateMatrix
    Real f = 1.0f/ tan(fov/2);
  m_projectionMatrix.Set( f/aspect,   0.0f,   0.0f,                   0.0f,
                          0.0f,       f,      0.0f,                   0.0f,
                          0.0f,       0.0f,   -(far+near)/(near-far), 2*far*near/(near-far),
                          0.0f,       0.0f,   0.0f,                   1.0f
  );
  */
}

void Camera::LookAt(const Vector3& eye, const Vector3& target, const Vector3& up)
{
  m_position = eye;
  m_target = target;
  m_up = up;
  m_matrixNeedsUpdate = true;
  
  /*
  // Moved to UpdateMatrix
    m_position = eye;
    m_target = target;
    m_up = up;
    
    Vector3 orient = target - eye;
    orient.Normalize();
    
    m_up.Normalize();
    Vector3 s = orient.Cross(m_up);
  */
  
  
    
}

Matrix4& Camera::GetProjectionMatrix()
{
  if(m_matrixNeedsUpdate) UpdateMatrix();
  return m_projectionMatrix;
}


Matrix4& Camera::GetViewMatrix()
{
   if(m_matrixNeedsUpdate) UpdateMatrix();
  return m_viewMatrix;
}

/*
const Matrix4& Camera::GetProjectionMatrix() const
{

  return m_projectionMatrix;
}


const Matrix4& Camera::GetViewMatrix() const
{
 
  return m_viewMatrix;
}
*/
bool Camera::MatrixNeedsUpdate()
{
  return m_matrixNeedsUpdate;
}


void Camera::UpdateMatrix()
{
  m_projectionMatrix = glm::perspective(m_fov,m_aspect,m_near,m_far);
  
  glm::vec3 pos(m_position.x, m_position.y, m_position.z);
  glm::vec3 target(m_target.x, m_target.y, m_target.z);
  glm::vec3 up(m_up.x, m_up.y, m_up.z);
  m_viewMatrix = glm::lookAt(pos, target, up);
  
  
  // 0ad method
  //Vector3 orient = m_target - m_position;// row 354 LookAt
  
  //orient.Normalize(); // row 362 LookAlong
  
  //Vector3 s = orient.CrossProduct(m_up); // row 364
  /*
  Matrix4 orientation(
      -s.x,   m_up.x,   orient.x,   0,
      -s.y,   m_up.y,   orient.y,   0,
      -s.z,   m_up.z,   orient.z,   0,
      0,      0,        0,          1
    );
*/
/*
 Matrix4 both(
 // this work's whit view * projection * model
      -s.x,   m_up.x,   orient.x,   0,
      -s.y,   m_up.y,   orient.y,   0,
      -s.z,   m_up.z,   orient.z,   0,
      m_position.x,     m_position.y, m_position.z,          1
  );
  */
  /*
   Matrix4 both(
      -s.x,   m_up.x,   orient.x,   m_position.x,
      -s.y,   m_up.y,   orient.y,   m_position.y,
      -s.z,   m_up.z,   orient.z,   m_position.z,
      0,      0,        0,          1
  );
  
  m_viewMatrix = both;
  */
  /*
    // Caclulate View Matrix
  Vector3 z = m_position - m_target; // orient
  z.Normalize();
  
  Vector3 x = m_up.CrossProduct(z);

  x.Normalize();
  
  Vector3 y = z.CrossProduct(x);
  
  
  Matrix4 orientation(  x.x,  y.x,  z.x,  0,
                        x.y,  y.y,  z.y,  0,
                        x.z,  y.z,  z.z,  0,
                        0,    0,    0,    1
  );
*/


  
//  Real f = 1.0f / tan(m_fov/2);
  /*
  Matrix4 orientation(
    f/m_aspect,     0,    0,                                  0,
    0,              f,    0,                                  0,
    0,              0,    -(m_far+m_near) / (m_near-m_far),   2*m_far*m_near / (m_near-m_far),
    0,              0,    0,                                  ,1
    );
  
  */
  
  //Matrix4 orientation();
  /*
  Matrix4 in;


  Matrix4 translation(  1,            0,            0,            0,
                        0,            1,            0,            0,
                        0,            0,            1,            0,
                        m_position.x, m_position.y, m_position.z,             1);

  
  
  
  
  */
  /**
  Matrix4 translation(  1,            0,            0,            m_position.x,
                        0,            1,            0,            m_position.y,
                        0,            0,            1,            m_position.z,
                        0,            0,            0,             1);
  **/
  /*
  
  std::cout << "==== ORIENTATION ==== "<<std::endl;
  orientation.Print();
  
  std::cout << "==== TRANSLATION ====" << std::endl;
  translation.Print();
  
  m_viewMatrix = orientation * translation;
  
  std::cout << "==== VIEW MATRIX ====" <<std::endl;
  m_viewMatrix.Print();
  */
  // Calculate Projection Matrix
  /*  
  Real f = 1.0f/ tan(m_fov/2);
  
  m_projectionMatrix.Set( f/m_aspect,   0.0f,   0.0f,                   0.0f,
                          0.0f,       f,      0.0f,                   0.0f,
                          0.0f,       0.0f,   -(m_far+m_near)/(m_near-m_far), 2*m_far*m_near/(m_near-m_far),
                          0.0f,       0.0f,   0.0f,                   1.0f
  );
  */
// m_projectionMatrix.MakeFrustum(m_fov,m_aspect,m_near,m_far);


  m_matrixNeedsUpdate = false;
}




