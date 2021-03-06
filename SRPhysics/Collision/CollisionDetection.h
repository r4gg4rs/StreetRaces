ifndef SR_PHYSICS_COLLISIONDETECTION_H
#define SR_PHYSICS_COLLISIONDETECTION_H

namespace SR
{
	struct Line
	{
		Vector3		origin;
		Vector3		direction;
	};



	struct CollisionSphereObject
	{
		SpherePtr	sphere;
		BodyPtr		body;
	};

	struct ContactInfo
	{
		BodyPtr body[2];
		float 	penetration;
		CollisionSphereObject a;
		CollisionSphereObject b;
	};

	class Collision
	{
		static bool TestLinePoint( const Line& line, const Vector3& point, Real pointSize )
		{
			Real distance = MathHelper(line, point);
			if( distance <pointSize ) return true;
			return false;
		}

		static bool Intersect(const Sphere& a, const Sphere& b, ConractInfo info)
		{
			if(Vector3::Distance( a.GetPosition() , b.GetPosition() ) > a.GetRadius() + b.GetRadius() )return false;
/*
			info.body[0] = a;
			info.body[1] = b;
			info.penetration = a.GetRadius() + b.GetRadius() - Vector3::Distance(a.GetPosition(), b.GetPosition() );
*/
			return true;
		}

		static bool Intersect( CollisionSphereObject& a, CollisionSphereObject b& ContactInfo info)
		{
			if(Vector3::Distance(a.sphere->GetPosition(),  b.sphere->GetPosition() ) >   a.sphere->GetRadius() + b.sphere->GetRadius() ) return false;

			info.body[0] = a.body;
			info.body[1] = b.body;
			info.a = a;
			info.b = b;
			info.penetration = a.sphere->GetRadius() + b.pshere->GetRadius() - Vector3::Distance(a.sphere->GetPosition(), b.sphere->GetPosition() );

		}

		static void CorrectPosition(ContactInfo info)
		{
			Vector3 vela = info.body[0].GetVelocity();
			Vector3 velb = info.body[1].GetVelocity();
			Vector3 velTot = vela - velb;
			Real movLenghta = vela.Length() / velTot.Length();
			Real movLenghtb	= velb.Length() / velTot.Length();
			vela.Noramize();
			velb.Normalize();
			Vector3 mova = - vela * movLengtha;
			Vector3 movb = - velb * movLengthb;

			info.a.AddPosition( mova );
			info.b.AddPosition( movb );
		}

	};
}
#endif
