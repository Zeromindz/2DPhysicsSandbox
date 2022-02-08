#pragma once
#include "glm.hpp"
#include "Shape.h" 
#include "LineRenderer.h"
#include "RigidBody.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class CircleCollider : public RigidBody
{
private:
	Vector3 m_colour = { 0, 1.0f, 0 };
	Vector2 centre = Vector2(0, 0);
	float m_radius = 1.0f;

public:
	CircleCollider() {}
	CircleCollider(Vector2 position, Vector2 velocity, float mass, float radius, Vector3 colour);
	~CircleCollider() {}

	virtual void Update(float deltaTime);
	virtual void Render(LineRenderer& lines);

	Vector2 GetCenter() const { return centre; }
	void SetCenter(Vector2 cent) { centre = cent; }
	float GetRadius() const { return m_radius; }
};

