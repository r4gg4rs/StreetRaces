/**
* @author		: Jani Haippo
* @version	: 03.2015
**/

#ifndef STREETRACER_CAMERA_BASE_H
#define STREETRACER_CAMERA_BASE_H

#include "icamera.h"

#include "../math/math_inc.h"

typedef float Real;

namespace Chopper
{

	class Camera_Base : public ICamera
	{

	 public:
		Camera_Base();
		~Camera_Base();

		void SetPosition(const Vector3& position);
		const Vector3& GetPosition() const;

		void SetTarget(const Vector3& target);
		const Vector3& GetTarget() const;


		void	SetFieldOfView(Real fov);
		Real	GetFieldOfView() const;	

		void 	UpdateMatrix();

		virtual Matrix4& GetViewMatrix();
		virtual Matrix4& GetProjectionMatrix(); 
	 protected:

		Matrix4    m_viewMatrix;
		Matrix4    m_projectionMatrix;

		Vector3    m_position;
		Vector3    m_target;
		Vector3    m_up;

		Real     m_fieldOfView;
		Real     m_nearPlane;
		Real     m_farPlane;
		Real     m_aspectRatio;
		
		bool			m_matrixNeedsUpdate;

	};
}
#endif
