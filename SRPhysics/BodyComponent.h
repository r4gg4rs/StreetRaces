#ifndef SRPHYSICS_BODYCOMPONENT_H
#define SRPHYSICS_BODYCOMPONENT_H

#include "../core/Component.h"
#include "Body.h"
#include "base.inc"

namespace SR
{
  
  class BodyComponent : public Component
  {
  public:
 
    BodyPtr     body;
   // ColiderPtr  colider;
  public:
    void SetOwner(MeshObjectPtr owner) 
    { 
      p_owner = owner;
      body->SetOwner(owner);
    }
    
    static ComponentPtr Get()
    {
      std::shared_ptr<BodyComponent> component(new BodyComponent);
      return component;
    }
  
  };
  
    typedef std::shared_ptr<BodyComponent> BodyComponentPtr;
}



/*
namespace SR
{
	class BodyComponent : public Component, public Body
	{
		public:
			BodyComponent() {}
			~BodyComponent() {}
			void Print() {std::cout<<"Owner " << p_owner->Print() << std::endl; }
	};

	typedef std::shared_ptr<BodyComponent> BodyComponentPtr;
}
*/
#endif
