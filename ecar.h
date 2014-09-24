#ifndef STREETRACING_CAR_H
#define STREETRACING_CAR_H

#include "entity.h"
#include "carcontroller.h"
#include "./sdl/sdl_eventmanager.h"
#include "./physics/body.h"
#include "./math/math_inc.h"


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
  
  void Update(float dt);
  
  void Accelerate();
  void Brake();
  void TurnLeft();
  void TurnRight();

 private:
	Body*  p_body;
  EWheel m_FL_wheel;
  EWheel m_FR_wheel;
  EWheel m_RL_wheel;
  EWheel m_RR_wheel;
  CarController* p_controller;
	Vector3 m_force;
	Vector3 m_velocity;
	float m_inverseMass;
};
#endif
