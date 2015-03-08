#ifndef STREETRACER_FOLLOW_CAMERA_H
#define STREETRACER_FOLLOW_CAMERA_H

#include "camera_base.h"

class FollowCamera : public Camera_Base 
{
	public:
		FollowCamera();
		~FollowCamera();
		
		void 
		SetFollowPosition(const Vector3& position );
		void SetDistance(const Vector3& distance);
		void CalculateMatrix();
		
	protected:
		Vector3 	m_distance;
};
#endif
