#ifndef SR_MODELMANAGER_H
#define SR_MODELMANAGER_H

namespace SR
{
  class ModelManager : public Singleton<ModelManager>
  {
    private:
      std::vector<Mesh*>  m_meshes;
    public:
      ModelManager() {}
      ~ModelManager() {
        for(unsigned int i =0; i< m_meshes.size(); i++)
        {
          delete m_meshes[i];
        }
      }
      
      Mesh*     GetMesh(){
        Mesh* mesh = new Mesh();
        m_meshes.push_back(mesh);
      }
      //mold MakeMold - tee muotti (Mesh* mesh, std::string moldname);
      Mesh* GetMesh(std::vecto<Vector3>& vertices, std::vector<Vecto3>& indices)
      {
        Mesh* mesh = GetMesh();
        mesh.SetVertices(vertices);
        mesh.SetIndices(indices);
        return mesh;
      }
      
      Mesh* GetPlaneMesh(Real width, Real debth)
      {
        
      }
      
      Mesh* GetBoxMesh(Real width, Real height, Real debth, 
      Real widthSegment, Real heightSegment, Real debthSegment)
      {
        
      }
      Mesh* GetSphereMesh(Real radius)
      {
        
      }
      
      std::vector<Mesh*> GetMeshes(std::vector<std::string>& names)
      {
        
      }
      
      
  };
}
#endif