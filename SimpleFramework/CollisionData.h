#pragma once

#include "glm.hpp"
#include "Shape.h"
#include "LineRenderer.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class CollisionData
{
public:
	Vector2 worldPos;
	Vector2 normal; // from a to b
	float depth;

	Shape* shapeA;
	Shape* shapeB;

	void Render(LineRenderer& lines);

	bool IsColliding() const { return depth > 0; }
};
