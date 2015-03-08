#ifndef STREETRACER_TEST_TERRAIN_H
#define STREETRACER_TEST_TERRAIN_H

#include <string>
#include <vector>
#include "../renderable.h"

class Terrain : public IRenderable
{
	public:
		Terrain();
		~Terrain();
		
		void Load(std::string& filename);
		void Render(RenderState& state);
		
	private:
	
};
#endif
