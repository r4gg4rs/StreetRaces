#ifndef SR_BSPTREE_H
#define SR_BSPTREE_H

namespace SR
{
	template class<T>
	class BspTree	
	{
		typedef std::shared_ptr<T> 	TPtr;
		typedef std::shared_ptr<BspTree>	BspTreePtr;
		
		private:
			BspTreePtr 	m_tree[8];
			BspTreePtr 	p_parent;
			T						m_instance;
			Vector3			m_min;
			Vector3			m_max;
		public:
			BspTree(const Vector3 min, const Vector3 max ) : m_min(min), m_max(max)
			{
			
			}
		public:
		
			void Add(TPtr object) 
			{
				if(!IsLeaf) 
				{
					for( int i=0; i< 8; i++) 
					{
						if(m_tree[i].PointIsInside(object.GetPosition() ) 
						{
							m_tree[i].Add( object );
						}
					}
					// TODO 
				} else
				{
					m_instance.Add( object );
				}
			}
			
			
			void Remove(TPtr object) 
			{
				// TODO
			}
			
			
			void Split()
			{
				// TODO
			}
			
			
			bool IsRoot() 
			{
				return (p_parent != null);
			}
			
			
			bool IsLeaf()
			{
				if(p_tree != null ) return true;
				return false;
			}
			
			bool PointIsInside(const Vector3 point)
			{
				if(point.x < m_min.x || point.x > m_max.x) return false;
				if(point.y < m_min.y || point.y > m_max.y) return false;
				if(point.z < m_min.z || point.z > m_max.z) return false;
				return true;
			}
	};
}
#endif

