#ifndef SR_ICAMERA_H
#define SR_ICAMERA_H

#include "../math/math.inc"
#include <memory>
namespace SR
{
  class ICamera
  {
    public:
      virtual Matrix4&  GetViewMatrix()=0;
      virtual Matrix4&  GetProjectionMatrix()=0;
  };
  
  typedef std::shared_ptr<ICamera> ICameraPtr;
}
#endif