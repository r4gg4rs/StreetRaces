#include "../GLUT/GLUT.inc"
#include "../GL/GL_Renderer.h"
#include "../core/base.inc"
#include "../core/CoreEngine.h"
#include "../core/Scene2.h"
#include "../core/MeshObject.h"
#include "../core/ComponentManager.h"
#include "../graphics/Mesh.h"
#include "../math/math.inc"
#include "../core/base.inc"
#include "../camera/Camera.h"
#include <iostream>

#include "../loader/loader.h"

#include "../graphics/ModelManager.h"
#include "TestCreator.h"
#include "../SRPhysics/PhysicsEngine.h"
#include "../SRPhysics/BodyComponent.h"


SR::IWindow*            p_window;
SR::CoreEngine*         p_coreEngine;

SR::ICamera*            p_camera;
SR::Loader*             p_loader;
SR::ModelManager*       p_modelManager;

SR::IWindowPtr          m_window;
SR::CoreEnginePtr       m_coreEngine;
std::shared_ptr<SR::ComponentManager>  p_componentManager;
void Render()
{
  p_coreEngine->Render();
  glutPostRedisplay();
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  
  
  SR::WindowGLUTPtr glut (new SR::WindowGLUT);
  m_window = glut;
  //p_window = new SR::WindowGLUT();
  std::string testi = "testi";
  m_window->Create(testi, 800,600);

//  SR::IWindowPtr iw = SR::WindowGLUTPtr(new SR::WindowGLUT);
  
  
  
  
  GLenum glewinit = glewInit();
  if(glewinit != GLEW_OK) 
  {
    std::cout <<"GLEW ERROR : " << std::endl;
    std::cout <<  glewGetErrorString(glewinit) << std::endl;
  }  

  
  
  p_loader = SR::Singleton<SR::Loader>::GetSingletonPtr();

  
  p_coreEngine = SR::Singleton<SR::CoreEngine>::GetSingletonPtr();
  p_componentManager = SR::Singleton<SR::ComponentManager>::GetSingletonSPtr();
  std::string BC_str = "BodyComponent";
  p_componentManager->RegisterCreator(BC_str, &SR::BodyComponent::Get);
  SR::PhysicsEnginePtr physicsEngine = SR::Singleton<SR::PhysicsEngine>::GetSingletonSPtr();
  
  
  
//  m_coreEngine = SR::Singleton<SR::CoreEngine>::GetSingletonSPtr();
  p_modelManager = SR::Singleton<SR::ModelManager>::GetSingletonPtr();
  SR::IRendererPtr    p_renderer(new SR::GL_Renderer);
  p_coreEngine->SetRenderer(p_renderer); 
  
  p_camera = new SR::Camera();
  
  
  p_renderer->SetCamera(p_camera);
 // new SR::GL_Renderer());
  
 // SR::Scene* pscene= new SR::Scene();
  SR::ScenePtr pscene(new SR::Scene);
  p_coreEngine->SetScene(pscene );
  
//  std::string sceneload = "../data/test/testload.test";
//  p_loader->LoadScene(pscene,sceneload);
  
   SR::InitCreator();  
  

  SR::MeshObjectPtr pobj1(new SR::MeshObject);
  SR::MeshPtr pmesh1(new SR::Mesh);
  
  std::vector<SR::Vector3> vertices;
  vertices.push_back(SR::Vector3(-0.5,-0.5, 0.5)); // 0
  vertices.push_back(SR::Vector3( 0.5,-0.5, 0.5)); // 1
  vertices.push_back(SR::Vector3( 0.5, 0.5, 0.5)); // 2
  vertices.push_back(SR::Vector3(-0.5, 0.5, 0.5)); // 3
  
  vertices.push_back(SR::Vector3(-0.5,-0.5, -0.5)); // 4
  vertices.push_back(SR::Vector3( 0.5,-0.5, -0.5)); // 5
  vertices.push_back(SR::Vector3( 0.5, 0.5, -0.5)); // 6
  vertices.push_back(SR::Vector3(-0.5, 0.5, -0.5)); // 7
  

  std::vector<unsigned int> indices;

  indices.push_back(0);
  indices.push_back(1);
  indices.push_back(2);  

  indices.push_back(2);
  indices.push_back(3);
  indices.push_back(0);

/**
  indices.push_back(4);
  indices.push_back(5);
  indices.push_back(6);
  
  indices.push_back(6);
  indices.push_back(7);
  indices.push_back(4);
**/


  indices.push_back(4);
  indices.push_back(5);
  indices.push_back(6);
  
  indices.push_back(6);
  indices.push_back(7);
  indices.push_back(4);
  
  /*
  indices.push_back(0);
  indices.push_back(7);
  indices.push_back(6);
  */
 // indices.push_back(1);
  

  pmesh1->SetVertices(vertices);
  pmesh1->SetIndices(indices);
  
  p_renderer->InitMesh(pmesh1);
  pobj1->SetMesh(pmesh1);
  
  SR::MaterialPtr pmat1(new SR::Material);
  pobj1->SetMaterial(pmat1);
  
  SR::BodyComponentPtr body1; 
  SR::ComponentPtr p_com1 = p_componentManager->GetComponent(BC_str);
  std::string grav = "Gravity";
  std::vector<std::string> fl;
  fl.push_back(grav);
  physicsEngine->Add(body1, fl);
  std::string bodyComponentStr = "BodyComponent";
  pobj1->AddComponent(bodyComponentStr,body1);
  
  
    
  pscene->Add(pobj1);
  pobj1->SetRotation(SR::Vector3(1.0,0.0,0.0), 0.25);

  pobj1->SetPosition(SR::Vector3(2,2,0));
  
  
  SR::MeshObjectPtr planeObject( new SR::MeshObject);
  SR::MeshPtr planeMesh = p_modelManager->GetPlaneMesh(2,2);
 
  p_renderer->InitMesh(planeMesh);
   std::cout << "planemesh size " << planeMesh->GetSize() << std::endl;
  planeObject->SetMesh(planeMesh);
  SR::MaterialPtr planeMat(new SR::Material);
  planeObject->SetMaterial(planeMat);
  planeObject->SetPosition(SR::Vector3(-1,-2,0));
  pscene->Add(planeObject);
  
  /*
  SR::MeshObject* boxObj = new SR::MeshObject();
  SR::Mesh* boxMesh = p_modelManager->GetBoxMesh(4,4,4);
  boxObj->SetMesh(boxMesh);
  boxObj->SetPosition(SR::Vector3(-1, -2, 0));
  pscene->Add(boxObj);
  */
  
  
  
  
  
  
  
  
  p_coreEngine->Start();
  
 glutDisplayFunc(Render);
  
  glutMainLoop();
  
	return 0;	
}

