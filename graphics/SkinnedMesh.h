#ifndef SR_GRAPHICS_SKINNEDMESH_H
#define SR_GRAPHICS_SKINNEDMESH_H

#include "Mesh.h"

namespace SR
{
  class SkinnedMesh : public Mesh
  {
    private:
    
    public:
      SkinnedMesh();
      ~SkinnedMesh();
      
      void SetSkeleton(Skeleton skeleton);
  };
}
#endif
