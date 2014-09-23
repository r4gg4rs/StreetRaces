#ifndef STREETRACING_KEYBOARD_H
#define STREETRACUNG_KEYBOARD_H

#include "controller.h"

class Keyboard : public Controller
{
 public:
  Keyboard();
  ~Keyboard();
  void KeyDown(unsigned char key);
  void KeyUp(unsigned char key);
  
  void Update();
 private:
  bool* m_keystates;
  bool* m_special;
};
#endif
