#include "singleton.h"

Singleton::Singleton()
{

}

Singleton::~Singleton()
{

}

T* Singleton::GetSingletonPtr()
{
  static T* instance
    if(instance == NULL)
      {
        instnace = new T();
      }
}
