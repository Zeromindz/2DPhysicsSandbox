#pragma once
#include "PhysicsObject.h"

class RigidBody : public PhysicsObject
{
public:
	

	RigidBody();
	RigidBody(ShapeType shapeID);
	RigidBody(ShapeType shapeID, Vector2 position, Vector2 velocity, float orient, float mass);
	~RigidBody() {}

	virtual void Update(float deltaTime);
	virtual void Render(LineRenderer& lines);

	void ApplyForce(Vector2 force);

	Vector2 GetPosition() { return pos; }
	void SetPosition(Vector2 newPos) { pos = newPos; }
	Vector2 GetVelocity() { return vel; }
	void SetVelocity(Vector2 newVel) { vel = newVel; }
	Vector2 GetAcceleration() { return acc; }
	void SetAcceleration(Vector2 newAcc) { acc = newAcc; }

	float GetMass() { return mass; }
	float GetOrientation() { return orientation; }

private:
	Vector2 pos;
	Vector2 vel;
	Vector2 acc;

	float orientation;
	float mass;

};

