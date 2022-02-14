#pragma once

//Reference
//https://github.com/RandyGaul/cute_headers/blob/master/cute_c2.h

#include "GameBase.h"

#include "PhysicsSystem.h"

class GameWorld : public GameBase
{

public:
	GameWorld();
	~GameWorld()
	{
		delete physicsSystem;
	}

	void Update();
	void Render();

	bool StartUp();

private:
	PhysicsSystem* physicsSystem = new PhysicsSystem();

	//Agent* agent;


};

