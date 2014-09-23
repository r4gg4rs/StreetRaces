#include "ecar.h"

EWheel::EWheel()
{

}

EWheel::~EWheel()
{

}

ECar::ECar()
{

}

ECar::~ECar()
{

}

void ECar::Accelerate()
{
m_position += m_heading;
}

void ECar::Brake()
{

}

void ECar::TurnLeft()
{
  m_angle += 1.0f;
}

void ECar::TurnRight()
{
 m_angle -= 1.0f;
}
