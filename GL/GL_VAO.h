/**
 * @author    Jani Haippo
 * @version   03.2015
 * */
 
 #ifndef STREETRACER_GL_VAO_H
 #define STREETRACER_GL_VAO_H
 
 #include "../framework/IBuffer.h"
 #include "../GLUT/GLUT.inc"
 #include "../core/base.inc"
 #include "../math/math.inc"
 
 
 namespace SR
 {
   class Vao : public IBuffer
   {
    public:
      Vao();
      ~Vao();
      void AddBuffer(IBuffer* buffer);
      void Init();
      void SetData(std::vector<Vector3>& vertices, std::vector<unsigned int>& indices);
      void Bind();
   private:
    std::vector<IBuffer*> m_buffers;
    GLuint                m_vaoID;
   
   };
 }
 #endif