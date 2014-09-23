#ifndef SR_CAR_H
#define SR_CAR_H

//#include "car_engine.h"
#include "../../entity.h"
#include "car_body.h"
class Car : public Entity
{
 public:
  Car();
  ~Car();

  void Accelerate();
  void Brake();
  void TurnLeft();
  void TurnRight();
 private:
  CarBody m_body;
  //  CarPhysics m_carPhysics;
  //CarEngine m_engine;
};
#endif
