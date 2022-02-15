#pragma once

#include "PhysicsObject.h"
#include "RigidBody.h"
#include "CollisionManifold.h"
#include "CircleCollider.h"
#include "Plane.h"
#include "AABB.h"
#include "Agent.h"

#include <vector>


class PhysicsSystem
{
public:
	PhysicsSystem();
	~PhysicsSystem();

	void Update(float deltaTime);
	void Render(LineRenderer& lines);
	
	void AddObject(PhysicsObject* object);
	void RemoveObject(PhysicsObject* object);

	float GetTimestep() { return timeStep; }
	void SetTimestep(float time) { timeStep = time; }
	Vector2 GetGravity() { return gravity; }
	void SetGravity(Vector2 grav) { gravity = grav; }


	float GetTotalEnergy();

	void CheckForCollision();
	void ApplyContactForces(RigidBody* body1, RigidBody* body2, Vector2 norm, float pen);

	static bool PlaneToPlane(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);
	static bool PlaneToAABB(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);
	static bool PlaneToCircle(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);
	static bool AABBToPlane(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);
	static bool AABBToAABB(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);
	static bool AABBToCircle(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);
	static bool CircleToPlane(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);
	static bool CircleToBox(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);
	static bool CircleToCircle(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData);


private:
	std::vector<PhysicsObject*> objects;
	std::vector<RigidBody*> bodies1;
	std::vector<RigidBody*> bodies2;
	std::vector<CollisionManifold> collisions;

	Vector2 gravity; 
	float timeStep;
};


class Line2D
{
private:
	Vector2 from;
	Vector2 to;
	Vector3 colour;

public:
	Line2D(Vector2 f, Vector2 t) { from = f; to = t; colour = { 1, 1, 1 }; }
	Line2D(Vector2 f, Vector2 t, Vector3 col) { from = f; to = t; colour = col; }
	Vector2 GetFrom() { return from; }
	Vector2 GetTo() { return to; }
	Vector2 GetStart() { return from; }
	Vector2 GetEnd() { return to; }

	float LengthSquared() {
		return sqrt(glm::length(Vector2(to - from)));
	}
};
