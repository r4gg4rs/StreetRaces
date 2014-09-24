#include "ecar.h"
#include <iostream>
EWheel::EWheel()
{

}

EWheel::~EWheel()
{

}
/*
	Body body
		johon sitten lisätään voima
		body -> lisää metoodi Simulate(deltatime)
		physics manager -> GetBody (vector<string>) lista haluttavista voima generaattoreista
		
		update
		body->Getposition
		
		engineforce -> bodyyn
		suunnan laskeminen
		renkaat
		
*/
ECar::ECar()
{
	//SetMass(1000.0f);
	m_inverseMass = 1/ 1000.0f;
}

ECar::~ECar()
{

}

void ECar::Update(float dt)
{
	// force = mass * acceleration
	// acceleration = force / mass
	// acceleration = force * inverse mass
	Vector3 acc = m_force* m_inverseMass;
	m_velocity += acc;
	//std::cout << "acceleration x  "<< acc.x << " y  " << acc.y << " z  " << acc.z << std::endl; 
	//SetAcceleration(GetForce() * GetMass() );
	//Vector3 acc = GetAcceleration();
	//AddVelocity(acc);
	//Vector3 vel = GetVelocity();	
	float speed = MATH::Lenght(m_velocity);
	//std::cout<< "speed : " << speed <<  "Inverse mass " << GetInverseMass() << std::endl;
	Vector3 dis =	m_heading * speed;
	
	//m_Position += m_heading;
	m_force = Vector3(0.0f,0.0f,0.0f);
	//std::cout << "pos "<< m_Position.x << std::endl;
	Entity::Update(dt);
}

void ECar::Accelerate()
{
	m_Position += m_heading;
	std::cout << m_Position.x << std::endl;
	m_force  = Vector3(0.0f,0.0f,1500.0f);
	//AddForce(Vector3(0.0f,0.0f,5.0f));
	//m_position += m_heading;
}

void ECar::Brake()
{

}

void ECar::TurnLeft()
{
  m_angle += 1.0f;
}

void ECar::TurnRight()
{
 m_angle -= 1.0f;
}
