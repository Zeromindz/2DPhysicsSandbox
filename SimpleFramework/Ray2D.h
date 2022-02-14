#pragma once


#include "glm.hpp"
typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class Ray2D
{
public:
	Ray2D(Vector2 orig, Vector2 dir)
	{
		origin = orig;
		direction = dir;
		glm::normalize(direction);
	}

	Vector2 GetOrigin() { return origin; }
	Vector2 GetDirection() { return direction; }

private:
	Vector2 origin;
	Vector2 direction;

};
