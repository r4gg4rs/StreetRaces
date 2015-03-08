#include "ecar.h"
#include <iostream>
EWheel::EWheel() 
{
	std::vector<std::string> forcegen;
	forcegen.push_back("Gravity");
	p_body = PhysicsManager::GetSingleton().GetNewBody(forcegen);
	p_body->SetMass(10.0f);
	
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
	Initialize();
	//SetMass(1000.0f);
	//m_inverseMass = 1/ 1000.0f;
}

ECar::~ECar()
{

}

void ECar::Initialize()
{
	std::vector<std::string> forcegen;
	forcegen.push_back("Gravity");// TODO read force generators in file so that they can be aded later on
	p_body = PhysicsManager::GetSingleton().GetNewBody(forcegen); 
	p_body->SetMass(1000.0f);

//	p_FL_wheel = new Ewheel(); // TODO pyydä objectfactoryltä
// 	p_FR_wheel = new Ewheel();
//  p_RL_wheel = new Ewheel();
//  p_RR_wheel = new Ewheel();
}

void ECar::Update(float dt)
{
	p_body->Simulate(dt);
	Vector3 velocity = p_body->GetVelocity();
	float speed = MATH::Lenght(velocity);
	m_Position += m_heading * speed;	
	Entity::Update(dt);
}

void ECar::Accelerate()
{
//	m_Position += m_heading;
	std::cout << m_Position.x << std::endl;
	p_body->AddForce( Vector3(0.0f,0.0f,50.0f) );
	//AddForce(Vector3(0.0f,0.0f,5.0f));
	//m_position += m_heading;
}

void ECar::Brake()
{
	p_body->AddForce(Vector3(0.0f,0.0f,-50.0f) );
}

void ECar::TurnLeft()
{
  m_angle += 3.0f;
}

void ECar::TurnRight()
{
 m_angle -= 3.0f;
}
