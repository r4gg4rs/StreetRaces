#include "mesh.h"

#include <iostream>
Mesh::Mesh()
{
  m_renderMode = GL_TRIANGLES;
  /*
  m_vert.push_back( Vector3(-0.24f, 0.0f,-0.3f));

  m_vert.push_back(Vector3(-0.24f, 0.0f, 0.3f));
  m_vert.push_back(Vector3( 0.24f, 0.0f, 0.3f));
  m_vert.push_back(Vector3( 0.24f, 0.0f,-0.3));

  m_indices.push_back(0);
  m_indices.push_back(1);
  m_indices.push_back(2);
  m_indices.push_back(3);
*/
}

Mesh::~Mesh()
{

}

void Mesh::Load(std::string name)
{
	if(name == "Cube") MESH::MakeBox(m_vertices,m_indices,0.5f,0.3f,1.0f);
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


void Mesh::CalculateSize()
{
	float min_x, max_x,min_y,max_y,min_z, max_z;
	
	for(unsigned int i=0; i< m_vertices.size(); i++)
	{
		float x = m_vertices[i].Position.x;
		float y = m_vertices[i].Position.y;
		float z = m_vertices[i].Position.z;
		
		if(x > max_x) max_x = x;
		if(x < min_x) min_x = x;
		if(y > max_y) max_y = y;
		if(y < min_y) min_y = y;
		if(z > max_z) max_z = z;
		if(z < min_z) min_z = z;
	}
	
	m_width 	= MATH::Abs(min_x) + MATH::Abs(max_x);
	m_height 	= MATH::Abs(min_y) + MATH::Abs(max_y);
	m_lenght 	= MATH::Abs(min_z) + MATH::Abs(max_z);
}
