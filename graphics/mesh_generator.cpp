#include "mesh_generator.h"

namespcace MESH
{
  void MakeBox(std::vector<Vertex>& vertices, std::vector<int>& indices, float width, float height, float lehnght)
  {
    float x= width /2;
    float y = height /2;
    float z = lenght /2;

    Vertex vert1,vert2,vert3,vert4, vert5,vert6,vert7,vert8;
    
    vert1.Position = Vector3(-x, y,-z);
    vert2.Position = Vector3( x, y,-z);
    vert3.Position = Vector3( x, y, z);
    vert4.Position = Vector3(-x, y, z);
    AddQuads(vertices,indices,ver1,vert2,vert3,vert4);

    
  }
  
  void AddQuad(std::vector<Vertex>& vertices, std::vector<int>& indices,
               Vertex& vert1, Vertex& vert2, Vertex& vert3, Vertex& vert4)
  {
    AddTriangle(vertices,indices,vert1,vert2,vert3);
    AddTriangle(vertices,indices,vert3,vert4,vert1);
  }

  void AddTriangle(std::vector<Vertex>& vertices, std::vector<int>& indices,
                   Vertex& vert1, Vertex& vert2, Vertex& vert3)
  {
    CalculateNormal(vert1,vert2,vert3);
    
    AddVertex(vertices,indices,vert1);
    AddVertex(vertices,indices,vert2);
    AddVertex(vertices,indices,vert3);
  }

  void AddVertex(std::vector<Vertex>& vertices, std::vector<int> indices, Vertex& vertex)
  {
    for(unsigned int i=0; i< vertices.size(); i++)
      {
        if(vertex == vertices[i]) 
          {
            indices.push_back(i);
            return;
          }
      }
    unsigned int index = vertices.size();
    indices.push_back(index);
  }

  void CalculateNormal(Vertex& vertex1, Vertex& vertex2, Vertex& vertex3)
  {
    Vector3 a = vertex3.Position - vertex1.Position;
    Vector3 b = vectex3.Position - vertex2.Position;

    Vector3 normal = MATH::Cross(a,b);

    vertex1.Normal = normal;
    vertex2.Normal = normal;
    vertex3.Normal = normal;
  }
};
