#include "gamestate.h"

MenuState::MenuState()
{

}

MenuState::~MenuState()
{

}

void MenuState::Render()
{

}


void MenuState::Update()
{

}

PlayState::PlayState()
{

}

PlayState::~PlayState()
{

}

void PlayState::Render()
{

}

void PlayState::Update()
{

}

Game::Game()
{
  p_state = new MenuState();
}

Game::~Game()
{

}

void Game::Render()
{
  p_State->Render();
}

void Game::Update()
{
  p_state->Update();
}

void Game::ChangeState(GameState* newState)
{
  delete p_state;
  p_state = newState;
}

