#include "mesh.h"

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}


void Mesh::Render()
{

}

void Mesh::SetData( std::vector<Vertex> vertices, std::vector<int> indices)
{
  m_vertices = vertices;
  m_indices = indices;
}
