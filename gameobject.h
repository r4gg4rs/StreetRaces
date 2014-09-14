/*
  @author  : r4gg4rs r4gg4rs@yahoo.com
  @version : 14.09.2014
*/

#ifndef STREETRACES_GAMEOBJECT_H
#define STREETRACES_GAMEOBJECT_H

#include <string>

/*
  Gameobjects base class every gameobject should inherit this
 */
class GameObject
{
 public:
  GameObject();
  ~GameObject();

  int GetID() const;
  void SetTag(std::string tag);
  std::string GetTag();
 private:
  int m_ID;
  std::string m_tag;
private: 
  int  s_nextID;
};
#endif
