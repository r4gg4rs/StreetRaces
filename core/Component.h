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

	class Component
	{
	  friend class MeshObject;
		private:
			ID 							m_id;
			std::string			m_type;
			MeshObjectPtr 	p_owner;
			static ID 			s_nextID;
		public:
			Component();
			~Component();
	//		void SetParent(MeshObjectPtr parent);
		protected:
			void SetType(std::string& type);
		private:
			static ID GetID(); 
	};
	
	typedef std::shared_ptr<Component> ComponentPtr;
}
#endif
