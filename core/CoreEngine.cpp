
#include "CoreEngine.h"

using namespace SR;

CoreEngine::CoreEngine()
{
  
}

CoreEngine::~CoreEngine()
{
  
}

void CoreEngine::SetRenderingSystem(RenderingSystem* rSystem)
{
  p_renderingSystem = rSystem;
}