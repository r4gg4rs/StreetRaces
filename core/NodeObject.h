#ifndef SR_NODEOBJECT_H
#define SR_NODEOBJECT_H

#include "../math/math.inc"
#include "base.inc"
//#include "../framework/IRenderer.h"
#include <list>

namespace SR
{
  typedef Vector3 Euler;
  typedef unsigned int ID;
  typedef unsigned int Index;
  
  class IRenderer;
  typedef std::shared_ptr<IRenderer> IRendererPtr;
  
  
  class NodeObject
  {
    typedef std::shared_ptr<NodeObject> NodeObjectPtr;
    typedef std::list<NodeObjectPtr>    ChildList;
    
    private:
      ID              m_id;
      static ID       s_nextID;
    protected:
      ChildList       m_childs;
      Matrix4         m_modelMatrix;
      Matrix4         m_toWorld;
      Vector3         m_position;
      Euler           m_erotation; // change to quaternion
      bool            m_matrixNeedsToUpdate;
      bool            m_needsToRender;
      NodeObjectPtr   p_parent;
      bool            m_isVisible;

    public:
      NodeObject();
      ~NodeObject();
      
      bool operator ==(const NodeObjectPtr obj);
      
      
      ID            GetID       () const;
      void          Add         (NodeObjectPtr child);
      void          Remove      (NodeObjectPtr child);
      void          SetParent   (NodeObjectPtr parent);
      NodeObjectPtr GetParent   ();
      
      void          SetPosition (const Vector3& position);
      Vector3&      GetPosition ();
      
      void          SetRotation (const Euler& rotation);
      Euler&        GetRotation ();
      
      Matrix4&      GetModelMatrix();
      Matrix4&      GetToWorld();
      
      
      bool          MatrixNeedsToUpdate();
      bool          ToWorldMatrixNeedsToUpate();
      virtual void  Render(IRendererPtr renderer);
      
      bool          IsVisible() const;
      void          SetVisibility(bool visibility);
      void          Print();
      void          UpdateToWorldMatrix();
    private:
      void          UpdateMatrix();
      
      
  };
}
#endif