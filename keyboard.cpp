#include "keyboard.h"

Keyboard::Keyboard()
{
  m_keystates = new bool[256];
  for(unsigned int i = 0; i< m_keystates.size(); i++)
  {
  	m_keystates[i] = false;
  }
}

Keyboard::~Keyboard()
{

}

void Kayboard::KeyDown(unsigned char key)
{

}


void Keyboard::KeyUp(unsigned char key)
{

}

void Keyboard::Update()
{

}
