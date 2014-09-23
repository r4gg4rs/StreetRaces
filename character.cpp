#include "character.h"

Character::Character()
{

}

Character::~Character()
{

}

void Character::Walk()
{
	m_position += m_heading;
}

void Character::TurnLeft()
{
	  m_angle += 1.0f;
}

void Character::TurnRight()
{
	  m_angle -= 1.0f;
}

