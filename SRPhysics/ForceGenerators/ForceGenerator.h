#ifndef SR_PHYSICS_FORCEGENERATOR_H
#define SR_PHYSICS_FORCEGENERATOR_H

#include <stdio.h>	
#include <memory>
#include "../base.inc"
#include "../Body.h"

namespace SR
{
	typedef std::shared_ptr<Body> BodyPtr;

  class ForceGenerator
  {
		public:
			typedef std::shared_ptr<ForceGenerator> ForceGeneratorPtr;
	  
    public:
   //   ForceGenerator(){}
    //  ~ForceGenerator(){}
      virtual void Update(BodyPtr body, Real dt)=0;
   //  static virtual ForceGeneratorPtr Get() =0;
  };
  

}
#endif
