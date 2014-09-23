/*
  @author  : r4gg4rs  r4gg4rs@yahoo.com
  @version : 22.09.2014
 */

#ifndef SR_VEHICLE_ENGINE_H
#define SR_VEHICLE_ENGINE_H

class Engine
{
 public:
  Engine();
  ~Engine();

  float GetMaxRPM() const;
  float GetRPM() const;
 private:
  float m_rpm;
  float m_maxRpm;
  float m_throttle_position;
};
#endif
