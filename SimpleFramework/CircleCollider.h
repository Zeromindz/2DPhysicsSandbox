#pragma once
#include "glm.hpp"
#include "Shape.h" 
#include "LineRenderer.h"
#include "RigidBody.h"
#include "Maths.h"

class CircleCollider : public RigidBody
{

public:
	CircleCollider() {}
	CircleCollider(Vector2 position, Vector2 velocity, float mass, float radius, Vector3 colour);
	~CircleCollider() {}

	virtual void Render(LineRenderer& lines);

	Vector2 GetCenter() { return rb.GetPosition(); }
	float GetRadius() const { return m_radius; }

	//RigidBody GetRigidbody() { return rb; }
	//void SetRigidbody(RigidBody body) { rb = body; }

private:
	Vector3 m_colour = { 0, 1.0f, 0 };
	float m_radius = 1.0f;

	RigidBody rb;

};

