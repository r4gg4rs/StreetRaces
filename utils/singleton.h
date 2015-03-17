#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

namespace SR 
{

	template <class T>
	class Singleton
	{
		public:
		 
		  
			static T* GetSingletonPtr()
			{
				static T* instance;
				if(!instance)
				{
					instance = new T();
					instance->StartUp();
				}
				return instance;		
			}
		  
		  
		  static std::shared_ptr<T> GetSingletonSPtr()
		  {
		      std::shared_ptr<T> instance(GetSingletonPtr());
		      return instance;
		  }
		
			static T& GetSingleton()
			{
				return *GetSingletonPtr();
			}
		
			static void Delete()
			{
				T* inst = GetSingletonPtr();
				inst->ShutDown();
				delete inst;		
			}
		
			virtual void StartUp()
			{
			}
		
			virtual void ShutDown()
			{
		
			}
		protected:
		/*
			Singleton() { }
			~Singleton(){ }
		*/
		private:
			//static T* instance;
	};
}
#endif
