#ifndef SR_CORE_COMPONENT_H
#define SR_CORE_COMPONENT_H

#include "MeshObject.h"
#include "../core/base.inc"
#include <memory>


namespace SR
{
  class MeshObject;
  
  typedef std::shared_ptr<MeshObject> MeshObjectPtr;
	typedef unsigned int ID;
/*
  class ComponentEvent
  {
    public:
      enum CEventType { ADD_OWNER };
  };
  
  typedef void (*EventFunc) (ComponentEvent event)();
  
  class ComponentListener
  {
    public:
      CEventType  event;
      EventFunc   callback;
  };

  typedef std::vector<ComponentListener> ListenerList;
*/
	class Component
	{
	  friend class MeshObject;
		
		protected: // should be private exept owner if setowner virtual
			ID 							m_id;
			std::string			m_type;
			MeshObjectPtr 	p_owner;
	//		ListenerList    m_listeners;
			
			static ID 			s_nextID;
			
		public:
			Component();
			~Component();
	//		void SetParent(MeshObjectPtr parent);
		  
		  /*
		    virtual becose bodycomponent needs to know if owner is added
		    owner added event?
		  */
		  virtual void SetOwner(MeshObjectPtr owner);
		//  void AddListener(CEventType event, EventFunc callback);
		protected:
			void SetType(std::string& type);
	
		private:
			static ID GetID(); 
	};
	
	typedef std::shared_ptr<Component> ComponentPtr;
}
#endif
