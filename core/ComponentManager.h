#ifndef SR_COMPONENTMANAGER_H
#define SR_COMPONENTMANAGER_H

namespace SR
{
  typedef ComponentPtr (*ComponentCreatorPtr)();
  
  class ComponentManager : public Singleton<ComponentManager>
  {
    private:
      std::map<std::string, ComponentCreatorPtr> m_creatorMap;
    public:
      
      void RegisterCreator(std::string& name, CompnentCreatorPtr creator)
      {
        m_creatorMap[name] = creator;
      }
      
      
      ComponentPtr GetComponent(std::string& name)
      {
        return m_creatorMap[name];
      }
      
  };
}
#endif