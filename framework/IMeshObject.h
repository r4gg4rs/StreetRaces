#ifndef STREETRACER_IMESHOBJECT_H
#define STREETRACER_IMESHOBJECT_H

#include "IEntity.h"
#include "IMesh.h"
#include "ICamera.h"


namespace SR
{
  class IMeshObject : public IEntity
  {
    public:
      virtual IMesh*  GetMesh()=0;
      virtual void Render(const ICamera& camera)=0;
  };
}

#endif