/**
 * @author    Jani Haippo
 * @version   03.2015
 * */
 
 #ifndef STREETRACER_GL_ELEMENT_BUFFER_H
 #define STREETRACER_GL_ELEMENT_BUFFER_H
 
 #include "../framework/IBuffer.h"
  #include "../GLUT/GLUT.inc"
 namespace SR
 {
   class GL_ElementBuffer : public IBuffer
   {
     public:
      GL_ElementBuffer();
      ~GL_ElementBuffer();
      void SetData(std::vector<unsigned int>& indices);
      void Bind();
    private:
      GLuint  m_bufferID;
   };
 }
 #endif