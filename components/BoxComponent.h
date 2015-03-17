#ifndef SR_COMPONENTS_BOXCOMPONENT_H
#define SR_COMPONENTS_BOXCOMPONENT_H

namespace SR
{
	class BoxComponent : public Component
	{
	  private:
	    Vector3       m_max;
	    Vector3       m_min;
	    Vector3*      p_points;
		public:
			BoxComponent();
			~BoxComponent();
			
			void Set(const Vector3& min, const Vector3& max);
			void Update();
			
	};
}
#endif
