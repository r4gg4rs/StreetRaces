#ifndef CHARACTER_H
#define CHARACTER_H

class Character : public Entity
{
	public:
		Character();
		~Character();
		
		void Walk();
		void TurnLeft();
		void TurnRight();
};
#endif
