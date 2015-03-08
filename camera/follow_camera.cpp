#include "follow_camera.h"
#include <iostream>

FollowCamera::FollowCamera() 
{
	m_distance = Vector3(0.0f, 40.0f, 0.0);
}

FollowCamera::~FollowCamera() 
{

}

void FollowCamera::SetFollowPosition(const Vector3& position )
{
	m_target = position;
		
	m_position = m_target + m_distance;
	CalculateMatrix();
}


void FollowCamera::SetDistance(const Vector3& distance)
{
	m_distance = distance;	
}

void FollowCamera::CalculateMatrix() 
{
	m_viewMatrix = glm::lookAt( m_position, m_target, m_up);
	m_projectionMatrix = glm::perspective( m_fieldOfView,
                                        m_aspectRatio,
                                        m_nearPlane,
                                        m_farPlane);

}
