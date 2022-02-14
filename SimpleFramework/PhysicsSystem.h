#pragma once

#include "PhysicsObject.h"
#include "RigidBody.h"
#include "CollisionManifold.h"
#include "CircleCollider.h"
#include "Plane.h"

#include "Agent.h"
//#include "CollisionFunctions.h"

#include <vector>

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


class PhysicsSystem
{
public:
	PhysicsSystem();
	~PhysicsSystem();

	void Update(float deltaTime);
	void Render(LineRenderer& lines);
	
	void AddObject(RigidBody* object);
	void RemoveObject(RigidBody* object);

	float GetTimestep() { return timeStep; }
	void SetTimestep(float time) { timeStep = time; }
	Vector2 GetGravity() { return gravity; }
	void SetGravity(Vector2 grav) { gravity = grav; }

	void CheckForCollision();
	
	static bool CircleToCircle(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool CircleToPlane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool PlaneToCircle(PhysicsObject* obj1, PhysicsObject* obj2);


	static bool PointOnLine(PhysicsObject* point, PhysicsObject* line) { return false; }
	static bool PointInCircle(PhysicsObject* point, PhysicsObject* circle) { return false; }
	static bool PointInAABB(PhysicsObject* point, PhysicsObject* box) { return false; }
	static bool PointInBox2D(PhysicsObject* point, PhysicsObject* box) { return false; }

	static bool Line2Circle(PhysicsObject* line, PhysicsObject* circle);
	static bool Circle2Line(PhysicsObject* circle, PhysicsObject* line);

	static bool LineAndAABB(PhysicsObject* line, PhysicsObject* box) { return false; }
	static bool LineAndBox2D(PhysicsObject* line, PhysicsObject* box) { return false; }


private:
	std::vector<RigidBody*> objects;
	std::vector<RigidBody*> bodies1;
	std::vector<RigidBody*> bodies2;
	std::vector<CollisionManifold*> collisions;

	Vector2 gravity; 
	float timeStep;
};

