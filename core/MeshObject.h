#ifndef SR_MESHOBJECT_H
#define SR_MESHOBJECT_H

namespace SR
{
  class MeshObject : public Entity,IMeshObject
  {
    public:
      MeshObject();
      ~MeshObject();
      
      void      SetPosition(const Vector3& position);
      Vector3&  GetPosition();
      
      void      SetMesh(IMesh* mesh);
      IMesh*    GetMesh();
      Matrix4&  GetModelMatrix();
      void      UpdateMatrix();
    private:
      IMesh*      p_mesh;
      Matrix4     m_modelMatrix;
      bool        m_matrixNeedsToUpdate;
  };
}
#endif