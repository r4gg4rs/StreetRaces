#include "car.h"

Car::Car()
{

}

Car::~Car()
{

}

void Car::Accelerate()
{
  Vector3 engineForce = Vector3(0.0f,0.0f,10.0f);
}

void Car::Brake()
{

}

void Car::TurnLeft()
{
  m_steeringAngle += 1.0f;
}

void Car::TurnRight()
{
  m_steeringAngle -= 1.0f;
}
