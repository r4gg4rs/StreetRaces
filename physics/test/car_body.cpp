#include "car_body.h"

CarBody::CarBody()
{
  
}

CarBody::~CarBody()
{

}

void CarBody::Turn(float val)
{
  m_steeringAngle += val;
}
