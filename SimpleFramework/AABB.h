#pragma once

#include "glm.hpp"
#include "LineRenderer.h"
#include "Utilities.h"
#include "RigidBody.h"
#include <cfloat>

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class AABB : public RigidBody
{

public:
	
	AABB();
	AABB(Vector2 min, Vector2 max); // Bottom left corner = min, Top right = max

	void Update(float deltaTime);
	void Render(LineRenderer& lines);

	bool CheckAABBCollision(AABB a, AABB b);

	Vector2 GetLocalMin() { return Vector2(rb.GetPosition() - halfSize); }
	Vector2 GetLocalMax() { return Vector2(rb.GetPosition() + halfSize); }

	void SetSize(Vector2 s) { size = s; halfSize = { s.x / 2.0f, s.y / 2.0f }; }

private:
	Vector3 colour = { 1.0f, 0, 0 };


	RigidBody rb;

	Vector2 size;
	Vector2 halfSize;
};

