#pragma once

//Reference
//https://github.com/RandyGaul/cute_headers/blob/master/cute_c2.h

#include "GameBase.h"
#include "PhysicsObject.h"
#include "AABB.h"
#include "Plane.h"
#include "Particle.h"
#include "CircleCollider.h"
#include "CollisionData.h"
#include "CollisionFunctions.h"
#include "RigidBody.h"

class GameWorld : public GameBase
{
private:
	std::vector<PhysicsObject> objects;
	Vector2 gravity;

	CollisionData collisionData;


	//Test
	CircleCollider circleTest;
	AABB boxTest;
	Plane planeTest;

	const static int particleCount = 100;
	std::vector<Particle> particles;


public:
	GameWorld();

	void AddObject(PhysicsObject object);
	void RemoveObject(PhysicsObject object);
	void Update();
	void Render();

	Vector2 GetGravity() const { return gravity; }
	void SetGravity(Vector2 grav) { gravity = grav; }

};

