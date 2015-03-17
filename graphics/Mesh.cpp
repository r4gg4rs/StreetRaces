#include "Mesh.h"
#include <iostream>

using namespace SR;

Mesh::Mesh()
{
  
}

Mesh::~Mesh()
{
  
}

void Mesh::SetVertices(Vertices& vertices)
{
  m_vertices = vertices;
}

void Mesh::SetIndices(Indices& indices)
{
  m_indices = indices;
  m_size = indices.size();
}

Vertices& Mesh::GetVertices()
{
  return m_vertices;
}

TextCoords& Mesh::GetTextCoords()
{
  return m_textCoords;
}



void Mesh::AddVertices(Vertices& vertices)
{
 m_vertices.insert(m_vertices.end(), vertices.begin(),vertices.end());
}

void Mesh::AddVertices(const Vertex& vertex)
{
 m_vertices.push_back( vertex);
}
      
      
void  Mesh::AddIndices(Indices& indices)
{
  m_indices.insert(m_indices.end(), indices.begin(), indices.end());
}


void  Mesh::AddIndices(Index index)
{
  m_indices.push_back(index);
}


void Mesh::AddFace(Face4 face)
{
 // m_faces.push_back(face);
  face.AddToIndices(m_indices);
  
  Vector3 u = m_vertices[face._b] - m_vertices[face._a];
  Vector3 v = m_vertices[face._c] - m_vertices[face._a];
  
  Vector3 normal = u.CrossProduct(v);
      	
  m_normals.push_back( normal);
  m_normals.push_back( normal);
  m_normals.push_back( normal);
  m_normals.push_back( normal);
  m_size = m_indices.size();
}

Indices&  Mesh::GetIndices()
{
  return m_indices;
}


void Mesh::Render(RenderState& state)
{
  for(unsigned int i=0; i< m_buffers.size(); i++)
  {
    m_buffers[i]->Bind();
  }
  
}


void Mesh::Render()
{
  //  std::cout << "Binding buffers " << m_buffers.size() << std::endl;
  for(unsigned int i=0; i< m_buffers.size(); i++)
  {
    m_buffers[i]->Bind();
  }
}

void Mesh::AddBuffer(IBuffer* buffer)
{
  m_buffers.push_back( buffer);
}

unsigned int Mesh::GetSize()
{
  return m_size;
}
