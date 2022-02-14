#pragma once

#include "glm.hpp"
typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class UtilityMath
{
public:
	static void Rotate(Vector2& vec, float angleDeg, Vector2 origin);

	bool Compare(float x, float y, float epsilon);
	bool Compare(Vector2 vec1, Vector2 vec2, float epsilon);
	bool Compare(float x, float y);
	bool Compare(Vector2 vec1, Vector2 vec2);

private:

};

