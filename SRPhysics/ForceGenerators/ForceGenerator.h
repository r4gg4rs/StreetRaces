#ifndef SR_PHYSICS_FORCEGENERATOR_H
#define SR_PHYSICS_FORCEGENERATOR_H

namespace SR
{
  class ForceGenerator
  {
    public:
      ForceGenerator();
      ~ForceGenerator();
      void Update(BodyPtr body, Real dt)=0;
  };
  
  typedef std::shared_ptr<ForceGenerator> ForceGeneratorPtr;
}
#endif