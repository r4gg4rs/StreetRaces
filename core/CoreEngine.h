/**
* @author			Jani Haippo
* @version		03.2015
**/

#ifndef STREETRACER_COREENGINE_H
#define STREETRACER_COREENGINE_H

#include "../framework/RenderingSystem.h"

namespace SR
{
	class CoreEngine 
	{
		public:
			CoreEngine();
			~CoreEngine();
			
			void SetRenderingSystem(RenderingSystem* rSystem);
		private:
		  RenderingSystem*  p_renderingSystem;
	};

};

#endif
