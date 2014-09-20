#ifndef STREETRACER_MESH_H
#define STREETRACER_MESH_H

#include "../vertex.h"
#include <GL/gl.h>

#include <string>
#include <vector>

class Mesh
{
 public:
  Mesh();
  ~Mesh();
  void Render();
  void SetData(std::vector<Vertex> vertices, std::vector<int> indices);
  const std::vector<Vertex>& GetVertices() const;
  const std::vector<int>& GetIndices() const;

 private:
  std::vector<Vertex> m_vertices;
  std::vector<int>    m_indices;

  GLuint m_vbo;
  GLuint m_vao;
};
#endif
