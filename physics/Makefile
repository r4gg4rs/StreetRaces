sr_physics.a : body.o forcegen.o physicsmanager.o 
	ar rcs sr_physics.a body.o forcegen.o
	
body.o : body.cpp
	g++ -Wall -c body.cpp
	
forcegen.o : forcegenerator.cpp
	g++ -Wall -c forcegenerator.cpp -o forcegen.o
	
physicsmanager.o : physicsmanager.cpp
	g++ -Wall -c physicsmanager.cpp 
	

