#ifndef SR_PHYSICS_PHYSICSENGINE_H
#define SR_PHYSICS_PHYSICSENGINE_H

#include "../framework/IEngine.h"
#include "./ForceGenerators/ForceGenerator.h"
#include "ForceRegistry.h"
#include "../utils/singleton.h"
#include "base.inc"
#include "BodyComponent.h"
#include "./Collision/Colider.h"

namespace SR
{
	typedef ForceGeneratorPtr (*GetGenerator) ();
	typedef std::map<std::string, GetGenerator> GeneratorMap;
	typedef std::vector<BodyComponentPtr> ComponentList;
  class PhysicsEngine : public Singleton<PhysicsEngine>, public IEngine
  {
  	private:
  		ForceRegistry 		m_forceRegistry;
  		GeneratorMap 			m_generatorMap;
  		ComponentList          m_componentlist;
  	public:
    	void Initialize();
			void Start();
			void Update( Real dt );
			
		  void Add(BodyPtr body, std::vector<std::string> forces);
		  void Add(BodyComponentPtr component, std::vector<std::string> forces);
		  void Add(BodyComponentPtr);
	    void RegisterGenerator(std::string name, GetGenerator generator);
  };
 	typedef std::shared_ptr<PhysicsEngine> PhysicsEnginePtr;
}


#endif
