#ifndef STREETRACES_OBJECTMANAGER_H
#define STREETRACES_OBJECTMANAGER_H

class ObjectManager
{
 public:
  static ObjectManager* GetSingletonPtr();
  static ObjectManager& GetSingleton();

  void Register(
 private:
  ObjectManager();
  ~ObjectManager();
};
#endif
