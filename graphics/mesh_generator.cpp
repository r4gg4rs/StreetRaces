#include "mesh_generator.h"

namespace MESH
{
  void MakeBox(std::vector<Vertex>& vertices, std::vector<int>& indices, float width, float height, float lenght)
  {
    float x= width /2;
    float y = height /2;
    float z = lenght /2;

    Vertex leftUpFront,leftDownFront,rightDownFront,rightUpFront, rightUpBack,rightDownBack,leftDownBack, leftUpBack;
    
    leftUpFront.Position		= Vector3( -x,  y,  z);
   	leftDownFront.Position	= Vector3( -x, -y,  z);
   	rightDownFront.Position	= Vector3(  x, -y,  z);
   	rightUpFront.Position 	= Vector3(  x,  y,  z);
   	rightUpBack.Position 		= Vector3(  x,  y, -z);
   	rightDownBack.Position  = Vector3(  x, -y, -z);
   	leftDownBack.Position 	= Vector3( -x, -y, -z);
   	leftUpBack.Position			= Vector3( -x,  y, -z);
   	
   	AddQuad(vertices,indices,leftUpFront,leftDownFront, rightDownFront,rightUpFront); //front
   	AddQuad(vertices,indices, rightUpFront,rightDownFront,rightDownBack,rightUpBack); // left
   	AddQuad(vertices,indices, rightUpBack,rightDownBack,leftDownBack,leftUpBack); // back
   	AddQuad(vertices,indices, leftUpBack, leftDownBack, leftDownFront, leftUpFront);  // left
   	AddQuad(vertices,indices, leftUpFront, rightUpFront, rightUpBack, leftUpBack); // up
   	AddQuad(vertices,indices, leftDownBack, rightDownBack,rightDownFront, leftDownFront); // down
    
  }
  
  void MakeWheel(std::vector<Vertex>& vertices, std::vector<int>& indices, float radius,float width)
  {
  	
  }
  
    
	void MakeRim(std::vector<Vertex>& vertices, std::vector<int>& indices, float radius, float width)
	{
	
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

  void AddVertex(std::vector<Vertex>& vertices, std::vector<int>& indices, Vertex& vertex)
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
    vertices.push_back(vertex);
    indices.push_back(index);
  }

  void CalculateNormal(Vertex& vertex1, Vertex& vertex2, Vertex& vertex3)
  {
    Vector3 a = vertex3.Position - vertex1.Position;
    Vector3 b = vertex3.Position - vertex2.Position;

    Vector3 normal = MATH::Cross(a,b);

    vertex1.Normal = normal;
    vertex2.Normal = normal;
    vertex3.Normal = normal;
  }
};
