
#include "base.inc"
#include "PhysicsEngine.h"
#include "BodyComponent.h"
#include "./ForceGenerators/GravityGenerator.h"


//SR::PhysicsEnginePtr p_engine;

int main( int argc, char** argv )
{
	SR::PhysicsEnginePtr p_engine = SR::Singleton<SR::PhysicsEngine>::GetSingletonSPtr();
	std::string gravity("Gravity");
	p_engine->RegisterGenerator( gravity , &SR::GravityGenerator::Get );
	SR::BodyComponentPtr body(new SR::BodyComponent);
	body->SetMass( 1000);
	std::vector<std::string> forceList;
	forceList.push_back(gravity);
	
	p_engine->Add( body, forceList);

	SR::BodyComponent test;
	test.SetMass(10.0);
	
	
	
	return 0;
	
	
}



