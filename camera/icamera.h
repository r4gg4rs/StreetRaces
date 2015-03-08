#ifndef STREETRACER_H
#define STREETRACER_H

#include "../math/math_inc.h"

namespace Chopper
{
	class ICamera
	{
	 public:
		virtual Matrix4& GetViewMatrix()=0;
		virtual Matrix4& GetProjectionMatrix()=0;
	};
}
#endif
