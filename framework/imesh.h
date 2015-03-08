#ifndef SR_IMESH_H
#define SR_IMESH_H

namespace SR
{
  class IMesh
  {
    std::vector<Vector3>&       GetVertices();
    std::vector<unsigned int>&  GetIndices();
  }
};
#endif
