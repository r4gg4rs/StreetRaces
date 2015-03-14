#ifndef STREETRACER_ISCENE_H
#define STREETRACER_ISCENE_H

#include "../core/MeshObject.h"
#include "IMeshObject.h"
#include "IRenderer.h"

namespace SR
{
  class IScene 
  {
    public:
      virtual void Add(MeshObject* object)=0;
   //   virtual void Add(Light* light)=0;
      virtual void Render(IRenderer* renderer)=0;
      virtual void InitMeshes(IRenderer* renderer)=0;
    //  virtual void Visit(IMeshObjectVisitor& visitor)=0;
  };
}
#endif
