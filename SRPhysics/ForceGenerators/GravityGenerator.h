#ifndef SR_PHYSICS_GRAVITYGENERATOR_H
#define SR_PHYSICS_GRAVITYGENERATOR_H

#include "ForceGenerator.h"

namespace SR
{
  class GravityGenerator : public ForceGenerator
  {
    private:
      Vector3       m_gravity;
    public:
      GravityGenerator(const Vector3& gravity):m_gravity(gravity) {}
      ~GravityGenerator(){}
      
      void Update(BodyPtr body, Real dt)
      {
        body->AddForce(m_gravity * body->GetMass());
      }
  };
}
#endif