#ifndef SR_TERRAINMANAGER_H
#define SR_TERRAINMANAGER_H

#include "../utils/singleton.h"
#include "TerrainPiece.h

namespace SR
{
	typedef std::vector<TerrainPiece> TerrainList;
	typedef std::vector<std::string>	FileList;
	
	struct LoadList
	{
		std::string			filename;
		Vector3					position;
	}
	
	typedef std::vector<LoadList>	LoadList;
	
	struct TSize
	{
		Real width;
		Real height;
	}

	class TerrainSettings
	{
		public:
			TSize		terrainSize; 	// size of terrain piece
			TSize		tileSize;			// Tile size
	};

	class TerrainManager : public Singleton<TerrainManager>
	{
		private:
			ICamera*					p_camera; // TODO ICamera GetPosition() // or frustum	
			TerrainList				m_terrainlist;
			LoadList					m_loadlist;
			
		public:
			TerrainSettings 	terrainSettings;
		protected:
			TerrainManager();
			~TerrainManager();
			
			void AddFile(std::String filename);
			void AddFileList(FileList filelist);
			void AddLoadList(LoadList loadlist);
			
			
			/*
			*	TODO Terrain manager loads piece of terrain acording to camera position
			* and unload pieces if they are far from camera. 
			*/
			TerrainPiece*	LoadTerrainPiece(std::string& filename);
			
			
	};

}
#endif
