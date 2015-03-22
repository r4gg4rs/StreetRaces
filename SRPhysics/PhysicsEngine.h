#ifndef SR_PHYSICS_PHYSICSENGINE_H
#define SR_PHYSICS_PHYSICSENGINE_H

#include "../framework/IEngine.h"
#include "./ForceGenerators/ForceGenerator.h"
#include "ForceRegistry.h"
#include "../utils/singleton.h"
#include "base.inc"

namespace SR
{
	typedef ForceGeneratorPtr (*GetGenerator) ();
	typedef std::map<std::string, GetGenerator> GeneratorMap;
	
  class PhysicsEngine : public Singleton<PhysicsEngine>, public IEngine
  {
  	private:
  		ForceRegistry 		m_forceRegistry;
  		GeneratorMap 			m_generatorMap;
  	public:
    	void Initialize();
			void Start();
			void Update( Real dt );
			
		  void Add(BodyPtr body, std::vector<std::string> forces);
	    void RegisterGenerator(std::string name, GetGenerator generator);
  };
 	typedef std::shared_ptr<PhysicsEngine> PhysicsEnginePtr;
}


#endif
