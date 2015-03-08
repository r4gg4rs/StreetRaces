/**
 * @author    Jani Haippo
 * @version   03.2015
 * @file      Mesh.h
 * */
 
 #ifndef STREETRACER_MESH_H
 #define STREETRACER_MESH_H
 
 namespace SR
 {
   class Mesh
   {
      public:
        Mesh();
        ~Mesh();
    
        void                        SetVertices(std::vector<Vector3>& vertices);
        void                        SetIndices(std::vector<unsigned int>& indices);
        std::vector<Vector3>&       GetVertices();
        std::vector<unsigned int>&  GetIndices();

      private:
        std::vector<Vector3>        m_vertices;
        std::vector<Vector3>        m_normals;
        std::vector<Vector3>        m_colors;
        std::vector<unsigned int>   m_indices;
      
   };
 }
 #endif