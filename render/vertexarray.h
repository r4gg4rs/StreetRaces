#ifndef STREETRACER_VERTEXARRAY_H
#define STREETRACER_VERTEXARRAY_H

#include "../math/math_inc.h"


class VertexArray
{
 public:
  VertexArray();
  ~VertexArray();
  void SetData(std::vector<Vertex>& vertices, std::vector<int>& indices);
 private:
  GLuint m_handle;
}:
#endif
