#ifndef SR_LOADER_H
#define SR_LOADER_H

#include "../utils/singleton.h"
#include "../core/base.inc"
#include <fstream>
#include <sstream>
#include <iostream>

#include "../framework/IScene.h"

#include <boost/algorithm/string.hpp>

//#include "../GL/GL_Texture.h"



namespace SR
{
	class Loader : public Singleton<Loader>
	{
		public:
			Loader() {}
			~Loader() {}
			
			std::string LoadShader(std::string& filename)
			{
				std::ifstream file(filename.c_str() );
				std::string line;
				std::string out;
				std::cout << "starting to load " << filename << "\n\n"<< std::endl;
				while(std::getline(file, line))
				{
				//	std::cout<< line <<std::endl;
					out.append(line + "\n");
				}
				
				return out;
			}
			
			/**
			* Loads image
			*	@param image image data pointer
			* @param filename image filename
			**/
			/*
			bool LoadImager(ImageData& imagedata, std::string& filename)
			{
			
			}
			*/
			/**
				{
					Renderer: {
					
					},
					Camera: {
					
					},
					Scene: {
						MeshObject:{
						
						},
						MeshObject:{
						
						},
						MeshObject:{
						
						}
					}
				}
			**/
			void LoadScene(IScene* scene, std::string filename)
			{
				std::ifstream file(filename.c_str() );
				std::string line;
				
				std::string mo = "MeshObject";
				std::string sscene ="Scene:";
				
				bool isObject = false;
				std::cout << "Starting to parse scene " << filename<<std::endl;
				int count = 0;
				while(std::getline(file, line) )
				{
					std::cout << " Line " <<line << std::endl;
					boost::algorithm::trim(line);
					
					
					/**
						Start to parse scene
					**/
					if(line.compare(0, sscene.size(),sscene)==0)
					{
						std::cout << sscene << " Found " << std::endl;
						std::string sceneString;
						int scount = 0;
						bool sbool = true;
						bool s_start_found = false;
						while(sbool)
						{
							std::getline(file,line);
							if(line.find("{") != std::string::npos)
							{
								scount++;
								count++;
								std::cout <<"Found { " << scount << std::endl;
							}
							if(line.find("}") != std::string::npos)
							{
								scount--;
								count--;
								if(scount <= 0) {
									sbool = false;
									std::cout << "SCENE \n" << sceneString<<std::endl;	
	
								}
								std::cout << "Found } " << scount << std::endl;
							}
							
							sceneString.append(line + "\n");						
						}
					}
					
				}
			}
	};
}
#endif
