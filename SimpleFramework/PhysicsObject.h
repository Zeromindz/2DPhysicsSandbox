#pragma once

#include "glm.hpp"
#include "LineRenderer.h"
#include "Utilities.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class PhysicsObject
{
public:
	Vector2 pos = { 0, 0 };
	Vector2 vel = { 0, 0 };
	Vector2 acc = { 0,0 };

	float mass = 0.0f;

	void Update(float deltaTime);

private:
	
};

