#ifndef STREETRACER_GAMESTATE_H
#define STREERRACER_GAMESTATE_H


class GameState
{
 public:
  virtual ~GameState();

  virtual void Render();
  virtual void Update();
};


class MenuState : public GameState
{
 public:
  MenuState();
  ~MenuState();

  void Render();
  void Update();
};

class PlayState
{
 public:
  PlayState();
  ~PlayState();

  void Render();
  void Update();
};


class Game
{
 public:
  Game();
  ~Game();
  void Render();
  void Update();
  void ChangeState(GameState* newState);
 private:
  GameState* p_state;
  GameState* p_pausedState;
};
#endif
