#ifndef SR_MESHOBJECT_H
#define SR_MESHOBJECT_H

#include "NodeObject.h"

#include "Entity.h"
#include "../framework/IMeshObject.h"
#include "base.inc"
#include "../math/math.inc"
#include "../graphics/Material2.h"

#include "../framework/IRenderer.h"
#include "Component.h"


namespace SR
{
	class IRenderer;
  class Component;
  
  typedef std::shared_ptr<IRenderer> IRendererPtr;
  
  typedef std::shared_ptr<Component> ComponentPtr;
  typedef std::map<std::string, ComponentPtr> ComponentMap;
	//typedef std::vector<ComponentPtr> 
 // class MeshObject : public Entity , public IMeshObject, std::enable_shared_from_this<MeshObject> x
	class MeshObject : public NodeObject, public std::enable_shared_from_this<MeshObject>
  {
    typedef std::vector<MeshObject*> MeshObjectList;
    public:
      MeshObject();
      ~MeshObject();
    //  void				  Add(MeshObject* child);
      void          AddComponent(std::string& name, ComponentPtr component);
      ComponentPtr  GetComponent(std::string& name);
      
   //   void      	  SetPosition(const Vector3& position);
      void 				  Move(const Vector3& position);
  //    Vector3&  	  GetPosition();
      
      void				  SetRotation(const Vector3& axis, Real angle);
      Quaternion&	  GetRotation();

      void 				  Rotate(const Vector3& axis, Real angle);      
      
      void          SetMesh(IMeshPtr mesh);
      IMeshPtr      GetMesh();
      
      void          SetMaterial(MaterialPtr material);
      MaterialPtr   GetMaterial();
      
      void          Render(IRenderer* renderer);
      
      
//      Matrix4&  	  GetModelMatrix();
//      void      	  UpdateMatrix();
      
      void      	  Render(const ICamera& camera);
      void      	  Render();
      void          Render(IRendererPtr renderer);
      
      void      	SetVisibility(bool value);
      void      	_SetNeedsToRender(bool value);
      bool      	NeedsToRender();
      
      void          Print();
    private:
//      Vector3     								m_position;
      Quaternion									m_rotation;
      IMeshPtr    								p_mesh;
//      Matrix4     								m_modelMatrix;
//      bool       									m_matrixNeedsToUpdate;
//      bool        								m_isVisible;
      bool       		 							m_needsToRender; // object is inside frustum and need's to render
      MeshObjectList							m_MOchilds;
      MaterialPtr                 p_material;
      Vector3											euler;
      
      ComponentMap                m_components;
    //SpherePtr										p_sphere; // bounding sphere
  };
  typedef std::shared_ptr<MeshObject> MeshObjectPtr;
}
#endif
