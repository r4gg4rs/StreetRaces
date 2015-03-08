#ifndef STREETRACER_IMESHOBJECT_H
#define STREETRACER_IMESHOBJECT_H

#include "IEntity.h"
#include "imesh.h"


namespace SR
{
  class IMeshObject : public IEntity
  {
    public:
      virtual IMesh*  GetMesh();
  };
}

#endif