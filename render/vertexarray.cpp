#include "vertexarray.h"

VertexArray::VertexArray()
{

}

VertexArray::~VertexArray()
{

}

void VertexArray::SetData(std::vector<Vertex>& vertices, std::vector<int>& indices)
{
  /* Pystynkö jotenkin lataamaan datan suoraan verticesistä näytönohjaimelle ? 

     Vertex rakunne ->

     struct Vertex
     {
        Vector3 Position
        Vector3 Normal 
        Vector2 TextCoord
        Vectoe3 Color
     } 
  */
  

  std::vector<Vector3> positions;
  std::vector<Vector3> normals;
  std::vector<Vector2> textCoords;
  std::vector<Vector4> colors;

  for(int i =0; i< vertices.size(); i++)
    {
      positions.push_back( vertices[i].Position );
      normals.push_back( vertices[i].Normal );
      textCoords.push_back( vertices[ı].TextCoord );
      colors.push_back( vertices[i].Color );
    }
    
  GLuint m_handle;
 	glGenVertexArray(1, &m_handle);
	glBindVertexArray(m_handle);
    
  GLuint buffer_handle;
  glGenBuffer(1, &buffer_handle);

  glBindBuffer(GL_ARRAY_BUFFER, buffer_handle);
  glBufferData(GL_ARRAY_BUFFER, sizeof(positions) + sizeof(normals) + sizeof(colors),NULL,GL_STATIC_DRAW);
  glBufferSubData(GL_ARRAY_BUFFER, 0                 , sizeof(positions) , &positions[0]);
  glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions) , sizeof(normals)   , &normals[0]);
  glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions)+ sizeof(normals),
                  sizeof(colors), &colors[0]);

  GLenum element_handle;
  glGenBuffer(1, &element_handle);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_handle);
  glBufferData(GL_ELEMET_ARRAY_BUFFER, &indices[0], GL_STATIC_DRAW);


}
