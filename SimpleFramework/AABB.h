#pragma once

#include "glm.hpp"
#include "LineRenderer.h"
#include "Utilities.h"
#include "PhysicsObject.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class AABB : public PhysicsObject
{
private:
	//Vector2 min = { 0, 0 };
	//Vector2 max = { 0, 0 };

	// Dimensions
	float width = 0;
	float height = 0;

	Vector2 pos = { 0, 0 };

public:

	AABB();
	AABB(Vector2 position, float w, float h);
	void Update(float deltaTime);
	void Render(LineRenderer& lines);

	bool CheckAABBCollision(AABB a, AABB b);


};

