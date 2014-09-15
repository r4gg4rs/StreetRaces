/*
  @author  : r4gg4rs r4gg4rs@yahoo.com
  @version : 14.09.2014
*/

#ifndef STREETRACER_MESH_H
#define STREETRACER_MESH_H

#include <vector>
#include "vertex.h"

class Mesh
{
 public:
  Mesh();
  ~Mesh();
  
 private:
  std::vector<Vertex*>  	m_vertices;
  std::vector<int>  		m_indices;
};
#endif
