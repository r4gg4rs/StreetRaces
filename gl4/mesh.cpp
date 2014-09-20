#include "mesh.h"

#include <iostream>
Mesh::Mesh()
{

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

const std::vector<int>& Mesh::GetIndices() const
{
  return m_indices;
}
