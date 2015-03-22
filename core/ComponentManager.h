#ifndef SR_COMPONENTMANAGER_H
#define SR_COMPONENTMANAGER_H

#include "base.inc"
#include "Component.h"

namespace SR
{
  typedef ComponentPtr (*ComponentCreatorPtr)();
  
  class ComponentManager : public Singleton<ComponentManager>
  {
    private:
      std::map<std::string, ComponentCreatorPtr> m_creatorMap;
    public:
      
      void RegisterCreator(std::string& name, ComponentCreatorPtr creator)
      {
        m_creatorMap[name] = creator;
      }
      
      
      ComponentPtr GetComponent(std::string& name)
      {
        return m_creatorMap[name]();
      }
      
  };
  
  std::shared_ptr<ComponentManager> ComponentManagerPtr;
}
#endif