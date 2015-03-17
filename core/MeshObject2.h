#ifndef SR_MESHOBJECT2_H
#define SR_MESHOBJECT2_H

namespace SR
{
  class MeshObject : public NodeObject
  {
    private:
      MeshPtr     p_mesh;
      MaterialPtr p_material;
      
      void        SetMesh(MeshPtr mesh);
      MeshPtr     GetMesh();
      void        SetMaterial(MaterialPtr material);
      MaterialPtr GetMaterial();
  };
}
#endif