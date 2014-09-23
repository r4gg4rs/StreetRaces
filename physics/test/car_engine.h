#ifndef SR_ENGINE_H
#define SR_ENGINE_H

class Engine
{
 public:
  Engine();
  ~Engine();

 private:

  float m_rpm;
  float m_maxRpm;
  float m_throttle_position;

};
#endif
