#ifndef STREETRACER_MESH_H
#define STREETRACER_MESH_H

#include "../vertex.h"

#include <string>

class Mesh
{
 public:
  Mesh();
  ~Mesh();
  void Render();
  void SetData(std::vector<Vertex> vertices, std::vector<int> indices);
  const std::vector<Vertex>& GetVertices();
  const std::vector<int>& GetIndics();
 private:
  std::vector<Vertex> m_vertices;
  std::vector<int>    m_indices;
};
#endif
