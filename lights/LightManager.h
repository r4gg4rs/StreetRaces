#ifndef SR_LIGHTMANAGER_H
#define SR_LIGHTMANAGER_H

#include "../utils/singleton.h"

namespace SR
{
  class LightManager : Singleton<LightManager>
  {
    public:
      LightManager(){}
      ~LightManager(){}
      
      ILight*   GetAmbientLight(const Color& color);
      ILight*   GetAreaLight(const Color& color, Real intensity);
      ILight*   GetDirectionalLight(const Color& color, Real intesity);
      ILight*   GetSpotLight(const Color&, Real intensity, const Vector3 position);
  };
}
#endif