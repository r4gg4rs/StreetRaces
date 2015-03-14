#ifndef SR_OBJECTFACTORY_H
#define SR_OBJECTFACTORY_H

#include "MeshObject.h"
#include "../utils/singleton.h"
#include "../core/base.inc"
#include "../graphics/Mesh.h"

namespace SR
{
  class ObjectFactory : public Singleton<ObjectFactory>
  {
    public:
      ObjectFactory();
      ~ObjectFactory();
     // void RegisterCreator( name, function
      MeshObject*   GetObject(std::string& name);
      
      MeshObject*   GetTestObject();
  };
}
#endif
