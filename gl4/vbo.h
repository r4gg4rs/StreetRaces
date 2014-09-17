#ifndef STREETRACER_GL_VBO_H
#define STREETRACER_GL_VBO_H

class Vbo
{
 public:
  Vbo();
  ~Vbo();
  void SetData(std::vector<Vertex>& vertices);
 private:
  GLuint m_handle;
};
#endif
