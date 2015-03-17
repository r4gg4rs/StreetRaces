#ifndef STREETRACER_IMESHOBJECT_H
#define STREETRACER_IMESHOBJECT_H

#include "IEntity.h"
#include "IMesh.h"
#include "ICamera.h"
#include <memory>

namespace SR
{
  class IMeshObject : public IEntity
  {
    public:
      virtual IMeshPtr  GetMesh()=0;
      virtual void Render(const ICamera& camera)=0;
  };
  
  typedef std::shared_ptr<IMeshObject> IMeshObjectPtr;
}

#endif