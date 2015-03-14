
#include "Model.h"

void Model::SetShader(IShader* shader)
{
  p_shader = shader;
}

void Model::SetMesh(IMesh* mesh)
{
  p_mesh = mesh;
}