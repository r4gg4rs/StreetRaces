#include "model.h"

Model::Model()
{

}

Model::~Model()
{

}

void LoadObj(std::string& filename)
{
  ifstream file(filename.c_str());
  if(!file)
    {
      std::cout << "Error" << std::endl;
    }
  std::string line;
  Mesh* mesh;
  std::vector<Vertex> vertices;
  std::vector<int> indices;

  std::vector<Vector3> posVertices;
  std::vector<Vector3> norVertices;
  std::vector<Vector2> texVertices;
  while(getLine(file,line))
    {
      if(line[0] == 'o')
        {
          /* new mesh */
          if(mesh != NULL)
            {
              mesh->SetData(vertices,indices);
            }
          mesh = new Mesh();

        }
      if(line[0] == 'v')
        {
          if(line[1] == ' ')
            {
              /* Vertex */
              Vector3 vert;
              
            }
          else if(line[1] == 't')
            {
              /* Texture coordinate */

            }
          else if(line[1] == 'n')
            {
              /* normal */

            }
        }
      if(line[0] == 'f')
        {
          /* face */
        }
    }

}

void Model::Render()
{

}
