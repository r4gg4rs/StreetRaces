#ifndef STREETRACER_VEHICLE_H
#define STREETRACER_VEHICLE_H

//class Vehicle : public PhysicsObject
class Vehicle : public Renderable, public Updateable, public Physical
{
 public:
  Vehicle();
  ~Vehicle();
  
  void Render(const ICamera* camera);
  void Update(float dt);
  Body *GetBody();

 private:
  Body* p_body;
};


#endif
