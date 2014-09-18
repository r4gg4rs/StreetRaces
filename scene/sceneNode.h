#ifndef STREETRACER_SCENE_NODE_H
#define STREETRACER_SCENE_NODE_H

class SceneNode
{
 public:
  SceneNode(SceneNode* child);
 
  ~SceneNode();

 private:
  SceneNode* m_child;
};
#endif
