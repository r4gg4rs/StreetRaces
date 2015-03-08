/**
 * @author    Jani Haippo
 * @version   03.2015
 * */
 
 #ifndef STREETRACER_GL_VAO_H
 #define STREETRACER_GL_VAO_H
 
 namespace SR
 {
   class Vao
   {
    public:
      Vao();
      ~Vao();
      void AddBuffer(IBuffer* buffer);
      void Bind();
   private:
    std::vector<IBuffer*> m_buffers;
    GLuint                m_vaoID;
   
   };
 }
 #endif