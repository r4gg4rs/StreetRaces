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
}
