#ifndef STREETRACER_MODEL_H
#define STREETRACER_MODEL_H

#include<vector>
#include<iostream>
#include<ifstream>

class Model
{
 public:
  Model();
  ~Model();
  void LoadObj(std::string& filename);
  void Render();
 private:
  std::vector<Mesh> p_meshes;
};
#endif
