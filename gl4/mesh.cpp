#include "mesh.h"

#include <iostream>
Mesh::Mesh()
{
  m_renderMode = GL_QUADS;
  m_vert.push_back( Vector3(-0.24f, 0.0f,-0.3f));

  m_vert.push_back(Vector3(-0.24f, 0.0f, 0.3f));
  m_vert.push_back(Vector3( 0.24f, 0.0f, 0.3f));
  m_vert.push_back(Vector3( 0.24f, 0.0f,-0.3));

  m_indices.push_back(0);
  m_indices.push_back(1);
  m_indices.push_back(2);
  m_indices.push_back(3);
}

Mesh::~Mesh()
{

}


void Mesh::Render()
{
  //std::cout<< "rendering" << std::endl;
  // For testing
  glColor4f(1.0f,1.0f,1.0f,1.0f);
  glBegin(GL_QUADS);
    glVertex3f(-0.3f,-0.3f,0.0f);
    glVertex3f(-0.3f, 0.3f,0.0f);
    glVertex3f( 0.3f, 0.3f,0.0f);
    glVertex3f( 0.3f,-0.3f,0.0f);
  glEnd();
}

void Mesh::SetData( std::vector<Vertex> vertices, std::vector<int> indices)
{
  m_vertices = vertices;
  m_indices = indices;
}

const std::vector<Vertex>& Mesh::GetVertices() const
{
  return m_vertices;
}

const std::vector<Vector3>& Mesh::GetVertexArray() const
{
  return m_vert;
}

const std::vector<int>& Mesh::GetIndices() const
{
  return m_indices;
}
