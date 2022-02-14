#pragma once

#include "Maths.h"

class RaycastResult
{
public:
	RaycastResult()
	{
		point = { 0, 0 };
		normal = { 0, 0 };
		t = -1;
		hit = false;
	}

	void Init(glm::vec2 p, glm::vec2 n, float t, bool h);

	static void Reset(RaycastResult* result);

private:
	glm::vec2 point;
	glm::vec2 normal;
	float t;
	bool hit;
};

