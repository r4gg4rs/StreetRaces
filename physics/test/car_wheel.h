#ifndef SR_CAR_WHEEL_H
#define SR_CAR_WHEEL_H

#include "../body.h"
#include "../../entity.h"

class CarWheel : public Entity
{
 public:
  CarWheel();
  ~CarWheel();

};

class CarWheelPhys : public Body
{

};
#endif
