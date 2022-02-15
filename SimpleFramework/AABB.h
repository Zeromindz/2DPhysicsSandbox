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
	AABB(Vector2 pos, Vector2 vel, Vector2 size, float mass); // Bottom left corner = min, Top right = max

	void Render(LineRenderer& lines);

	Vector2 GetLocalMin() { return Vector2(GetPosition() - halfSize); }
	Vector2 GetLocalMax() { return Vector2(GetPosition() + halfSize); }

	Vector2 GetSize() { return size; }
	Vector2 GetHalfSize() { return halfSize; }

	void SetSize(Vector2 newSize);



private:
	Vector2 size;
	Vector2 halfSize;

	Vector3 colour = { 1.0f, 0.2f, 0.2f };

	RigidBody rb;
};

