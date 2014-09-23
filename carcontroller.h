/*
  @author  : r4gg4rs r4gg4rs@yahoo.com
  @version : 20.09.2014

  Car Controller
*/ 

#ifndef STREETRACER_CAR_CONTROLLER_H
#define STREETRACER_CAR_CONTROLLER_H

#include "controller.h"

class CarController
{
 public:
  virtual void Accelerate()=0;
  virtual void Brake()=0;
  virtual void Turn(float val)=0;
  
 protected:
  
};
#endif
