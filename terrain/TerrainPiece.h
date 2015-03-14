#ifndef SR_TERRAIN_TERRAINPIECE_H
#define SR_TERRAIN_TERRAINPIECE_H

namespace SR
{
	class TerrainPiece
	{
		
		public:
			TerrainPiece(Real width, Real height, Real tile_width, Real tile_height);
			~TerrainPiece();
			
			void Initialize();
			
	};
}
#endif
