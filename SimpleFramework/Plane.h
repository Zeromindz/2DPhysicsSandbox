#pragma once

#include "PhysicsObject.h"
#include "RigidBody.h"
#include "Maths.h"
#include "glm.hpp"


class Plane : public PhysicsObject
{

public:
	Plane();
	Plane(Vector2 norm, float dist);
	~Plane();

	virtual void Update(Vector2 grav, float time);
	virtual void Render(LineRenderer& lines);

	virtual void ResetPosition() {}
	
	void ResolveCollision(RigidBody* obj);
	void ApplyForce(Vector2 force);
	void ApplyForceToObject(RigidBody* object2, Vector2 force);

	Vector2 GetNormal() const { return normal; };
	float GetOffset() const { return offset; }
	float DistanceToPoint(Vector2 point) { return glm::dot(normal, point) + offset; }
private:

	Vector2 normal = Vector3(0, 0, 0);
	float offset = 0;
	float length = 1000.0f;

	Vector3 colour = { 0, 0, 1.0f };

};

