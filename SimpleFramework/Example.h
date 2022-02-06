#pragma once

#include "GameBase.h"
#include "Particle.h"
#include "Agent.h"
#include "Obstacle.h"
#include "Maths.h"

class Example : public GameBase
{
private:
	Agent agent;
	const static int particleCount = 100;
	Particle particles[particleCount];
	const static int obstacleCount = 100;
	Obstacle obstacle[obstacleCount];

public:
	Example();

	void Update();

	void Render();

	void InitializeLevel();

	void CheckCollisions();
	
	void OnMouseClick(int mouseButton);
};