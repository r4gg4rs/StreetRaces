#ifndef ROAD_TEST_H
#define ROAD_TEST_H

#include <vector>

/*
	Test Road build
	
	testaus tien rakentamiseen
		koostetaan rata pisteistä
*/



class RoadTest
{
	public: 
		RoadTest();
		~RoadTest();
			void AddRoadPoint(Vector3& point);
	private:
		std::vector<Vector3> m_roadPoints;
};
#endif
