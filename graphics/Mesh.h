/**
 * @author    Jani Haippo
 * @version   03.2015
 * @file      Mesh.h
 * */
 
 #ifndef STREETRACER_MESH_H
 #define STREETRACER_MESH_H
 
 #include "../core/base.inc"
 #include "../math/math.inc"
 #include "../framework/IMesh.h"
 #include "../framework/IBuffer.h"
 
 #include "Face4.h"
 
 namespace SR
 {
   typedef std::vector<Face4>       Faces;
   
   class Mesh : public IMesh
   {
      public:
        Mesh();
        ~Mesh();
    
        void                        SetVertices(Vertices& vertices);
        void                        SetIndices(Indices& indices);

        void                        SetColors(Colors& color);
        void                        SetNormals(Normals& normals);
        
        Colors&                     GetColors();
        Normals&                    GetNormals();        
        
        
        void                        AddVertices(Vertices& vertices);
        void                        AddVertices(const Vertex& vertex);
        
        void                        AddIndices(Indices& indices);
        void                        AddIndices(Index index);
        
        void                        AddFace(Face4 face);
        
        
        Vertices&                   GetVertices();
        TextCoords&                 GetTextCoords();
        Indices&                    GetIndices();
      
        void                        Render(RenderState& state);
        void                        Render();
        void                        AddBuffer(IBuffer*  buffer);
        unsigned int                GetSize();
      
      
      private:
        Vertices                    m_vertices;
        Normals                     m_normals;
        Colors                      m_colors;
        TextCoords                  m_textCoords;
        Indices                     m_indices;
        
        std::vector<IBuffer*>       m_buffers;
        unsigned int                m_size;
        Faces                       m_faces;
        //Vao*  p_vao;
   };
 }
 #endif