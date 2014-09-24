/*
  @author  : r4gg4rs r4gg4rs@yahoo.com
  @version : 14.09.2014
*/

#ifndef SR_VERTEX_H
#define SR_VERTEX_H

#include "./math/vec.h"

class Vertex
{

	public:
		bool operator==(const Vertex& vert)
		{
			
			return 	Position == vert.Position && 
							Normal == vert.Normal &&
							TextCoord == vert.TextCoord &&
							Color == vert.Color;						
		}
		bool operator !=(const Vertex& vert)
		{
			return 	Position != vert.Position &&
							Normal != vert.Normal &&
							TextCoord != vert.TextCoord &&
							Color != vert.Color;		
		}

	public:
	
  Vector3 Position;
  Vector3 Normal;
 	Vector2 TextCoord;
  Vector4 Color;
};

#endif
