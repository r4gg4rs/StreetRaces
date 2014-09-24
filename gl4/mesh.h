#ifndef STREETRACER_MESH_H
#define STREETRACER_MESH_H

#include "../vertex.h"
#include <GL/gl.h>
#include "../math/math_inc.h"
#include "../graphics/mesh_generator.h"
#include <string>
#include <vector>


class Mesh
{
 public:
  Mesh();
  ~Mesh();
  void Load(std::string name);
  void Render();
  void SetData(std::vector<Vertex> vertices, std::vector<int> indices);
  const std::vector<Vertex>& GetVertices() const;
  const std::vector<Vector3>& GetVertexArray() const;
  const std::vector<int>& GetIndices() const;

	private:
		void CalculateSize();

 private:
 	float m_width;
 	float m_height;
 	float m_lenght;
 
  std::vector<Vertex> m_vertices;
  std::vector<Vector3> m_vert;
  std::vector<int>    m_indices;
  GLenum m_renderMode;
  GLuint m_vbo;
  GLuint m_vao;
};
#endif
