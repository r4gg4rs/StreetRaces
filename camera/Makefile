sr_camera.a : camera_base.o cameramanager.o follow_camera.o
	ar rcs sr_camera.a camera_base.o cameramanager.o follow_camera.o
	
camera_base.o : camera_base.cpp
	g++ -Wall -c camera_base.cpp
	
cameramanager.o : cameramanager.cpp
	g++ -Wall -c cameramanager.cpp

follow_camera.o : follow_camera.cpp
	g++ -Wall -c follow_camera.cpp

clean:
	rm *.o
