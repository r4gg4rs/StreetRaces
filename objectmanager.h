#ifndef STREETRACES_OBJECTMANAGER_H
#define STREETRACES_OBJECTMANAGER_H

class ObjectManager
{
 public:
  static ObjectManager* GetSingletonPtr();
  static ObjectManager& GetSingleton();
 private:
  ObjectManager();
  ~ObjectManager();
};
#endif
