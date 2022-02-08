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
private:
	Vector3 colour = { 1.0f, 0, 0 };

	float xMin = FLT_MAX;
	float xMax = -FLT_MAX;
	float yMin = FLT_MAX;
	float yMax = -FLT_MAX;

public:
	
	AABB() {}
	AABB(float xMinInit, float xMaxInit, float yMinInit, float yMaxInit);

	void Update(float deltaTime);
	void Render(LineRenderer& lines);

	bool CheckAABBCollision(AABB a, AABB b);

	float XMin() const { return xMin; }
	float XMax() const { return xMax; }
	float YMin() const { return yMin; }
	float YMax() const { return yMax; }

};

