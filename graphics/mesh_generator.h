#ifndef SR_MESH_GENERATOR_H
#define SR_MESH_GENERATOR_H

#include "../math/math_inc.h"
#include "../vertex.h"
#include <vector>


namespace MESH {
  void MakeBox(std::vector<Vertex>& vertices, std::vector<int>& indices, float width,float height, float lenght);
  void MakeWheel(std::vector<Vertex>& vertices, std::vector<int>& indices, float radius,float width);
	void MakeRim(std::vector<Vertex>& vertices, std::vector<int>& indices, float radius, float width);

  void AddQuad(std::vector<Vertex>& vertices, std::vector<int>& indices,
               Vertex& vert1, Vertex& vert2, Vertex& vert3, Vertex& vert4);
  void AddTriangle(std::vector<Vertex>& vertices, std::vector<int>& indices,
                   Vertex& vert1, Vertex& vert2, Vertex& vert3);
  void AddVertex(std::vector<Vertex>& vertices, std::vector<int>& indices, Vertex& vertex);
  void CalculateNormal(Vertex& vertex1, Vertex& vertex2, Vertex& vertex3);

};
#endif
