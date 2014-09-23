#ifndef STREETRACING_CAR_H
#define STREETRACING_CAR_H

#include "entity.h"
#include "carcontroller.h"
#include "./sdl/sdl_eventmanager.h"


class EWheel : public Entity
{
 public:
  EWheel();
  ~EWheel();
};

class ECar : public Entity
{
 public:
  ECar();
  ~ECar();
  void Accelerate();
  void Brake();
  void TurnLeft();
  void TurnRight();

 private:
  EWheel m_FL_wheel;
  EWheel m_FR_wheel;
  EWheel m_RL_wheel;
  EWheel m_RR_wheel;
  CarController* p_controller;
};
#endif
