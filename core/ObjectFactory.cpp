
#include "ObjectFactory.h"
#include "../graphics/Face4.h"
using namespace SR;

ObjectFactory::ObjectFactory()
{
  
}

ObjectFactory::~ObjectFactory()
{
  
}

MeshObject* ObjectFactory::GetObject(std::string& name)
{
  MeshObject* object =GetTestObject();
  return object;
  
}

MeshObject* ObjectFactory::GetTestObject()
{
  MeshObject* object = new MeshObject();
  Mesh* mesh = new Mesh();
  mesh->AddVertices(Vertex(-0.5,-0.5, 1.5)); // 0
  mesh->AddVertices(Vertex( 0.5,-0.5, 1.5)); // 1
  mesh->AddVertices(Vertex( 0.5, 0.5, 1.5)); // 2
  mesh->AddVertices(Vertex(-0.5, 0.5, 1.5)); // 3
  
  mesh->AddVertices(Vertex(-0.5,-0.5, -0.1)); // 4
  mesh->AddVertices(Vertex( 0.5,-0.5, -0.1)); // 5
  mesh->AddVertices(Vertex( 0.5, 0.5, -0.1)); // 6
  mesh->AddVertices(Vertex(-0.5, 0.5, -0.1)); // 7
  
  mesh->AddFace(Face4(0,1,2,3));
  mesh->AddFace(Face4(1,5,6,2));
  mesh->AddFace(Face4(5,4,7,6));
  mesh->AddFace(Face4(4,0,3,7));
  mesh->AddFace(Face4(4,5,1,0));
  mesh->AddFace(Face4(3,2,6,7));
  object->SetMesh( mesh );
  
  return object;
  
}