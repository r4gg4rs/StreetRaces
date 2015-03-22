#ifndef SR_PHYSICS_FORCEREGISTRY_H
#define SR_PHYSICS_FORCEREGISTRY_H

#include "base.inc"
#include "./ForceGenerators/ForceGenerator.h"
#include "Body.h"
#include <memory>

namespace SR
{
	typedef std::shared_ptr<ForceGenerator> ForceGeneratorPtr;

  struct FG_Body
  {
    ForceGeneratorPtr   generator;
    BodyPtr             body;
  };
  
  typedef std::vector<FG_Body> Registry;
  typedef unsigned int Index;
  
  class ForceRegistry
  {
      private:
        Registry 		m_registry;
      public:
        void        Add     (ForceGeneratorPtr forceGen, BodyPtr body);
        void        Remove  (ForceGeneratorPtr forceGen, BodyPtr body);
        void        Clear   ();
        void        Update  (Real dt);
  };
}
#endif
