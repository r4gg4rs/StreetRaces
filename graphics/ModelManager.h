#ifndef SR_MODELMANAGER_H
#define SR_MODELMANAGER_H

#include "../core/base.inc"
#include "Mesh.h"
#include "Material2.h"

/**
 *  TODO
 * 
 *  propably mesh init should be made in here when mesh is created
 *  get the renderer in core engine.
 * */


namespace SR
{
  struct MeshMold
  {
    std::string   name;
    MeshPtr         mesh;
  };  

  typedef std::vector<MeshPtr> MeshList;
  typedef std::vector<MeshMold> MoldList;
  
  
  class ModelManager : public Singleton<ModelManager>
  {
    private:
      MeshList  m_meshes;
      MoldList  m_moldlist;
    public:
      ModelManager() {}
      ~ModelManager() {
        for(unsigned int i =0; i< m_meshes.size(); i++)
        {
          //delete m_meshes[i];
        }
      }
      
      
      /**
       *  Get empty mesh
       * */
      MeshPtr GetMesh(){
        MeshPtr mesh(new Mesh);
        m_meshes.push_back(mesh);
        return mesh;
      }
      
      void MekeMold(std::string& name, MeshPtr mesh)
      {
        MeshMold mold;
        mold.name = name;
        mold.mesh = mesh;
      }
      
      /**
       * Needs that mesh and name has been registerated int moldlist
       * */
      MeshPtr GetMeshByName(std::string& name)
      {
        for(MoldList::iterator it=m_moldlist.begin(); it != m_moldlist.end(); it++)
        {
          if(it->name == name) return it->mesh;
        }
        
        return NULL;
      }
      
      
      //mold MakeMold - tee muotti (Mesh* mesh, std::string moldname);
      /**
       * Get mesh whith vertices and indices
       * */
      MeshPtr GetMesh(std::vector<Vector3>& vertices, std::vector<unsigned int>& indices)
      {
        MeshPtr mesh = GetMesh();
        mesh->SetVertices(vertices);
        mesh->SetIndices(indices);
        return mesh;
      }
      
      
      /**
       * Get PlaneMesh
       * */
      MeshPtr GetPlaneMesh(Real width, Real debth, Real widthSegment=1, Real heightSegment=1)
      {
          MeshPtr plane = GetMesh();
          plane->AddVertices(Vector3( -width/2 , 0.0, -debth/2));
          plane->AddVertices(Vector3(  width/2 , 0.0, -debth/2));
          plane->AddVertices(Vector3(  width/2 , 0.0,  debth/2));
          plane->AddVertices(Vector3( -width/2 , 0.0,  debth/2));
          plane->AddFace( Face4(0,1,2,3));
          
          /*
          plane->AddIndices(0);
          plane->AddIndices(1);
          plane->AddIndices(2);
          
          plane->AddIndices(2);
          plane->AddIndices(3);
          plane->AddIndices(0);
          */
          return plane;
      }
      
      
      MeshPtr GetBoxMesh(Real width, Real height, Real debth, 
      Real widthSegment=1, Real heightSegment=1, Real debthSegment=1)
      {
        MeshPtr box = GetMesh();
        box->AddVertices(Vector3( -width/2 , height/2, -debth/2));  // 0
        box->AddVertices(Vector3(  width/2 , height/2, -debth/2));  // 1
        box->AddVertices(Vector3(  width/2 , height/2,  debth/2));  // 2
        box->AddVertices(Vector3( -width/2 , height/2,  debth/2));  // 3
        
        box->AddVertices(Vector3( -width/2 , -height/2, -debth/2)); // 4
        box->AddVertices(Vector3(  width/2 , -height/2, -debth/2)); // 5
        box->AddVertices(Vector3(  width/2 , -height/2,  debth/2)); // 6
        box->AddVertices(Vector3( -width/2 , -height/2,  debth/2)); // 7
        
        box->AddFace( Face4(0,1,2,3) ); // top
        box->AddFace( Face4(7,6,5,4) ); // bottom
        box->AddFace( Face4(0,3,7,4) ); // left
        box->AddFace( Face4(6,5,1,2) ); // right
        box->AddFace( Face4(7,6,2,4) ); // front
        box->AddFace( Face4(5,4,0,1) );  // back
        
        
        return box;
      }
      
      
      MeshPtr GetSphereMesh(Real radius)
      {
        MeshPtr sphere = GetMesh();
        
        return sphere;
      }
      /*
      std::vector<Mesh*> GetMeshes(std::vector<std::string>& names)
      {
        
      }
      */
      
  };
  
  typedef std::shared_ptr<ModelManager> ModelManagerPtr;
}
#endif