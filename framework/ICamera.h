#ifndef SR_ICAMERA_H
#define SR_ICAMERA_H

#include "../math/math.inc"

namespace SR
{
  class ICamera
  {
    public:
      virtual Matrix4&  GetViewMatrix()=0;
      virtual Matrix4&  GetProjectionMatrix()=0;
  };
}
#endif