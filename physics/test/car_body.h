#ifndef SR_CAR_BODY_H
#define SR_CAR_BODY_H

#include "../body.h"

class CarBody : public Body
{
 public:
  CarBody();
  ~CarBody();
  //void Turn(flaot val);
 protected:
  float m_steeringAngle;
  float m_maxAngle;
  // Vector3 m_suspensionPosFL;
  //Vector3 m_suspens
  //  float m_steeringAngle;

};
#endif
