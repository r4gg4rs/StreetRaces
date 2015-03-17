#ifndef SR_OBJECTFACTORY_H
#define SR_OBJECTFACTORY_H

#include "MeshObject.h"
#include "../utils/singleton.h"
#include "../core/base.inc"
#include "../graphics/Mesh.h"
#include <map>
#include <string>

namespace SR
{
  typedef MeshObjectPtr (*ObjectCreatorPtr)();
  
  class ObjectFactory : public Singleton<ObjectFactory>
  {
    protected:
      std::map<std::string, ObjectCreatorPtr> m_creatorRegister;
    public:
      ObjectFactory();
      ~ObjectFactory();
     // void RegisterCreator( name, function
     void RegisterCreator(std::string& name,ObjectCreatorPtr creator );
     MeshObjectPtr GetObject( std::string& name);
     //MeshObjectPtr  GetObject( std::string& name);
     
//      MeshObject*   GetObject(std::string& name);
      
      MeshObject*   GetTestObject();
  };
  
  typedef std::shared_ptr<ObjectFactory> ObjectFactoryPtr;
}
#endif
