#ifndef SR_ICAMERA_H
#define SR_ICAMERA_H

namespace SR
{
  class ICamera
  {
    public:
      Matrix4&  GetViewMatrix();
      Matrix4&  GetProjectionMatrix();
  }
}
#endif