#ifndef TEST_TESTCREATOR_H
#define TEST_TESTCREATOR_H

#include "../core/MeshObject.h"
#include "../core/ObjectFactory.h"
#include "../graphics/ModelManager.h"
#include "../core/base.inc"

namespace SR
{
  static MeshObjectPtr GetTestObject()
  {
    MeshObjectPtr object(new MeshObject);
    ModelManagerPtr modelmanager = Singleton<ModelManager>::GetSingletonSPtr();
    
    MeshPtr mesh = modelmanager->GetPlaneMesh(2,2);
    object->SetMesh(mesh);
    Uniform color;
    color.name ="color";
    color.type ="vec3";
    MaterialPtr material(new Material);
    material->AddUniform(color);
    object->SetMaterial(material);
    return object;
  }

  static void InitCreator()
  {
      ObjectFactoryPtr factory = Singleton<ObjectFactory>::GetSingletonSPtr();
      std::string testname = "TestObject";
      factory->RegisterCreator(testname,&GetTestObject);
  }

}
#endif