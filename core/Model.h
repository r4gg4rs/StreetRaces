/**
 * Streetracing
 * @author    Jani Haippo
 * @version   03.2015
 * **/
 
 #ifndef SR_MODEL_H
 #define SR_MODEL_H
 
 #include "IModel.h"
 
 namespace SR
 {
   class Model : public IModel
   {
     private:
      IShader*    p_shader;
      IMaterial*  p_material;
      IMesh*      p_mesh;
      std::vector<Imesh>  m_meshes; // TODO change to allow multiple mesh
      // How about child models?
     public:
      Model(){}
      ~Model(){}
      
      void SetShader(IShader* shader)
      {
        p_shader =shader;
      }
      
      
      void SetMaterial(IMaterial* material)
      {
        p_material = material;
      }
      
      
      void SetMesh(IMesh* mesh)
      {
        p_mesh = mesh;
      }
      
      
      IShader* GetShader()
      {
        return p_shader;
      }
      
      
      IMaterial* GetMaterial()
      {
        return p_material;
      }
      
      
      IMesh*  GetMesh()
      {
        return p_mesh;
      }
      
    
   }
 }
 #endif