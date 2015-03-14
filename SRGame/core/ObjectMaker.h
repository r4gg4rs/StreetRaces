#ifndef SRGAME_CORE_OBJECTMAKER_H
#define SRGAME_CORE_OBEJCTMAKER_H

namespace SRGame
{
	namespace ObjectMaker
	{
	
		//TODO register maker to SR:ObjectFactory
		static MeshObject* MakeCar()
		{
			MeshObject* car = new MeshObject();
			MeshObject* flWheel = new MeshObject(); // front left wheel
			MeshObject* frWheel = new MeshObject(); // front right wheel
			MeshObject* rlWheel = new MeshObject(); // rear left wheel
			MeshObject* rrWheel = new MeshObject(); // rear right wheel
			
			car.Add(flWheel);
			car.Add(frWheel);
			car.Add(rlWheel);
			car.Add(rrWheel); 
		}
	}
}
#endif
