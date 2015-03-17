#ifndef SR_PHYSICS_GRAVITYGENERATOR_H
#define SR_PHYSICS_GRAVITYGENERATOR_H

#include "ForceGenerator.h"

namespace SR
{
  class GravityGenerator : public ForceGenerator
  {
    public:
      GravityGenerator(const Vector3& gravity);
      ~GravityGenerator();
  };
}
#endif