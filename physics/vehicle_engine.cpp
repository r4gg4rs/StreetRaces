#include "vehicle_engine.h"

Engine::Engine() :m_rpm(0.0f), m_maxRpm(8500.0f),  m_throttle_position(0.0f)
{

}

Engine::~Engine()
{

}

float Engine::GetMaxRPM() const
{
  return m_maxRpm;
}

float Engine::GetRPM() const
{
  return m_rpm;
}
