#ifndef SR_MESHOBJECT_H
#define SR_MESHOBJECT_H

#include "Entity.h"
#include "../framework/IMeshObject.h"
#include "base.inc"
#include "../math/math.inc"

namespace SR
{
	typedef std::vector<MeshObject> MeshObjectList;
  class MeshObject : public Entity , public IMeshObject
  {
    public:
      MeshObject();
      ~MeshObject();
      void				Add(MeshObject* child);
      void      	SetPosition(const Vector3& position);
      void 				Move(const Vector3& position);
      Vector3&  	GetPosition();
      
      void				SetRotation(const Vector3& axis, Real angle);
      Quaternion&	GetRotation();

      void 				Rotate(const Vector3& axis, Real angle);      
      
      void      SetMesh(IMesh* mesh);
      IMesh*    GetMesh();
      

      
      
      Matrix4&  	GetModelMatrix();
      void      	UpdateMatrix();
      
      void      	Render(const ICamera& camera);
      void      	Render();
      
      void      	SetVisibility(bool value);
      void      	_SetNeedsToRender(bool value);
      bool      	NeedsToRender();
    private:
      Vector3     								m_position;
      Quaternion									m_rotation;
      IMesh*      								p_mesh;
      Matrix4     								m_modelMatrix;
      bool       									m_matrixNeedsToUpdate;
      bool        								m_isVisible;
      bool       		 							m_needsToRender; // object is inside frustum and need's to render
      MeshObjectList							m_MOchilds;
      
      
      Vector3			euler;
      
    
  };
}
#endif
