#pragma once

#include "LineRenderer.h" 
#include "RigidBody.h"
#include "Maths.h"
#include "UtilityMath.h"

class Box2D
{
public:
	Box2D();
	Box2D(Vector2 min, Vector2 max); // Bottom left corner = min, Top right = max
	~Box2D();

	void Update(float deltaTime);
	void Render(LineRenderer& lines);

	Vector2 GetLocalMin() { return Vector2(rb.GetPosition() - halfSize); }
	Vector2 GetLocalMax() { return Vector2(rb.GetPosition() + halfSize); }

	void SetSize(Vector2 s) { size = s; halfSize = { s.x / 2.0f, s.y / 2.0f }; }

	std::vector<Vector2> GetVerticies();

	RigidBody GetRigidbody() { return rb; }
	void SetRigidbody(RigidBody body) { rb = body; }

private:
	RigidBody rb;

	Vector2 size;
	Vector2 halfSize;
};


