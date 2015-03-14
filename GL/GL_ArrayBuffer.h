/**
 * @author    Jani Haippo
 * @version   03.2015
 **/
 
 #ifndef STREETRACER_GL_ARRAYBUFFER_H
 #define STREETRACER_GL_ARRAYBUFFER_H
 
 #include "../core/base.inc"
 #include "../math/math.inc"
 #include "../framework/IBuffer.h"
 #include "../GLUT/GLUT.inc"
//#include "OpenGL.inc"
 namespace SR
 {
  class GL_ArrayBuffer : public IBuffer
  {
    public:
      GL_ArrayBuffer();
      ~GL_ArrayBuffer();
      void SetData(std::vector<Vector3>& data);
      void Bind();
    private:
      GLuint      m_bufferID;
      
  };
 }
 #endif