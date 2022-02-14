#include "RaycastResult.h"

void RaycastResult::Init(glm::vec2 p, glm::vec2 n, float T, bool h)
{
	point = p;
	normal = n;
	t = T;
	hit = h;
}

void RaycastResult::Reset(RaycastResult* result)
{
	if (result != nullptr)
	{
		result->point = { 0, 0 };
		result->normal = { 0, 0 };
		result->t = -1;
		result->hit = false;
	}
}
