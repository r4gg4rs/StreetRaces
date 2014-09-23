#ifndef STREETRACER_CARCONTROLLER_KEYBOARD_H
#define STREETRACER_CARCONTROLLER_KEYBOARD_H

#include "carcontroller.h"

class CarCKeyboard : public CarController
{

 public:
  CarCKeyboard();
  ~CarCKeyboard();

  void Accelerate();
  void Brake();
  void Turn(float value);
};
#endif
