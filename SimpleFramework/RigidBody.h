#pragma once

#include "PhysicsObject.h"
#include "Maths.h"
#include "UtilityMath.h"
#include "glm.hpp"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class RigidBody : public PhysicsObject
{
public:
	RigidBody() {}
	RigidBody(ShapeType shapeID);
	RigidBody(ShapeType shapeID, Vector2 pos, Vector2 vel, float rot, float ma);
	~RigidBody();

	virtual void Update(Vector2 gravity, float deltaTime);

	void ApplyForce(Vector2 force);
	void ApplyForceToObject(RigidBody* object2, Vector2 force);

	void ResolveCollision(RigidBody* object2);

	Vector2 GetPosition() { return position; }
	float GetRotation() { return rotation; }
	void SetTransform(Vector2 pos, float rot) { position = pos; rotation = rot; }
	void SetTransform(Vector2 pos) { position = pos; }

	Vector2 GetVelocity() { return linearVelocity; }
	void SetVelocity(Vector2 vel) { linearVelocity = vel; }
	float GetMass() { return mass; }
	void SetMass(float ma) { mass = ma; }

	float GetKineticEnergy();
	float GetPotentialEnergy();

private:
	Vector2 position = { 0, 0 };
	float rotation = 0;
	float mass = 0;

	Vector2 linearVelocity;
	Vector2 acceleration;
	float linearDamping = 0;
	
	float angularVelocity = 0;
	float angularDamping = 0;
	bool fixedRotation = false;

	Vector2 currentGravity = { 0, 0 };

};

