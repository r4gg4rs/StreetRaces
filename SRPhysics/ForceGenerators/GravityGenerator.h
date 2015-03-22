#ifndef SR_PHYSICS_GRAVITYGENERATOR_H
#define SR_PHYSICS_GRAVITYGENERATOR_H

#include "ForceGenerator.h"


namespace SR
{
  class GravityGenerator : public ForceGenerator
  {
  	typedef std::shared_ptr<GravityGenerator> GravityGeneratorPtr;
  	
    private:
      				Vector3       				m_gravity;
      static 	GravityGeneratorPtr		p_instance;
      
    public:
      GravityGenerator(){ m_gravity = Vector3(0,-1,0) ; } //(const Vector3& gravity= new Vector3(0,-1,0)):m_gravity(gravity) {}
      ~GravityGenerator(){}
      
      void Update(BodyPtr body, Real dt)
      {
        body->AddForce(m_gravity * body->GetMass());
      }
      
      static ForceGeneratorPtr Get()
      {
      	GravityGeneratorPtr gen(new GravityGenerator);
      	return gen;
  		}    
      /*
      	if( p_instance == NULL )										// Gravity generator only neets one instance
      	{
      		GravityGeneratorPtr gen(new GravityGenerator);
      		p_instance = gen;
      		return gen;
      	}
      	return  p_instance;
      }
      */
  };
}

#endif
