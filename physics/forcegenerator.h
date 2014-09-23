#ifndef STREETRACER_PHYSICS_FORCEGENERATOR_H
#defien STREETRACER_PHYSICS_FORCEGENERATOR_H

class ForceGenerator
{
 public:
  virtual void UpdateForce(Body* body,float dt) = 0;
};


class ForceRegistry 
{
 public:
  void Add(Body* body, ForceGenerator* fg);
  void Remove(Body* body, ForceGenerator* fg);
  void Clear();
  void UpdateForces(float dt);
 private:
  struct BodyForce
  {
    Body* body;
    ForceGenerator* forceGenerator;
  }
  typedef std::vector<BodyForce> Registery;
  Registery registrations;

};
#endif
