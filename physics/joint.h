#ifndef SR_JOINT_H
#define SR_JOINT_H

#include "body.h"

class Joint
{
	Joint();
	~Joint();
	void Set(Body* body1, Body* body2);
	private:
		Body* p_body1;
		Body* p_body2;
};
#endif
