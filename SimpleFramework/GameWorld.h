#pragma once

#include "GameBase.h"
#include "PhysicsObject.h"
#include "AABB.h"
#include "Plane.h"
#include "Particle.h"

class GameWorld : public GameBase
{
private:
	std::vector<AABB*> objects;
	const static int particleCount = 100;
	std::vector<Particle*> particles;

	// Boxes
	AABB* aabb1;
	AABB* aabb2;

	// Bounds
	std::vector<Plane*> planes;


public:
	GameWorld();

	void Update();

	void Render();

	void AddObject(AABB* object);
	void RemoveObject(AABB* object);

	void StepThroughObjects(float deltaTime);

	void InitializeLevel();

	void CheckCollisions();

};

