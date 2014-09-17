#ifndef STREETRACER_GAMESTATE_H
#define STREERRACER_GAMESTATE_H

class GameState
{
 public:
  virtual ~GameState();

  virtual void Render();
  virtual void Update();
};
#endif
