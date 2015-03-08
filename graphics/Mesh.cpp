#include "Mesh.h"

using namespace SR;

Mesh::Mesh()
{
  
}

Mesh::~Mesh()
{
  
}

void Mesh::SetVertices(std::vector<Vector3>& vertices)
{
  m_vertices = vertices;
}

void Mesh::SetIndices(std::vector<unsigned int>& indices)
{
  m_indices = indices;
}

std::vector<Vector3>& Mesh::GetVertices()
{
  return m_vertices;
}

std::vector<unsigned int>&  Mesh::GetIndices()
{
  return m_indices;
}