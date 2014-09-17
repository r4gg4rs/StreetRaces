#ifndef STREETRACER_SINGLETON_H
#define STREETRACER_SINGLETON_H

template <class T>
class Singleton
{
 public:
  static T* GetSingletonPtr();
  static T& GetSingleton();
  static void Delete();

  void Start();
  void Shutdown();
 private:
  Singleton();
  ~Singleton();
};
#endif
