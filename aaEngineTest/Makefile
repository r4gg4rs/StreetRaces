CC = g++
PROGRAM = run
FLAGS = -Wall -std=c++11
LIBS = -lGL -lGLU -lglut -lGLEW

SOURCES = main.cpp\
	../GLUT/GLUT_Window.cpp\
	../core/CoreEngine.cpp ../core/ObjectFactory.cpp ../core/Scene2.cpp  ../core/Entity.cpp\
	../core/Component.cpp ../core/NodeObject.cpp ../core/MeshObject.cpp\
	../graphics/Mesh.cpp ../graphics/Material2.cpp\
	../GL/GL_ArrayBuffer.cpp ../GL/GL_ElementBuffer.cpp ../GL/GL_VAO.cpp\
	../GL/GL_Renderer.cpp ../GL/Shader.cpp ../GL/GL_ShaderManager.cpp\
	../camera/Camera.cpp

ALL : $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) $(PLIBS) -o $(PROGRAM)



