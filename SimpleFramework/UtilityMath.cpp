#include "UtilityMath.h"

void UtilityMath::Rotate(Vector2& vec, float angleDeg, Vector2 origin)
{
	float x = vec.x - origin.x;
	float y = vec.y - origin.y;

	float cos = glm::cos(glm::radians(angleDeg));
	float sin = glm::sin(glm::radians(angleDeg));

	float xPrime = (x * cos) - (y * sin);
	float yPrime = (x * sin) - (y * cos);

	xPrime += origin.x;
	yPrime += origin.y;

	vec.x = xPrime;
	vec.y = yPrime;
}

bool UtilityMath::Compare(float x, float y, float epsilon)
{
	return glm::abs(x - y) <= epsilon * glm::max(1.0f, glm::max(glm::abs(x), glm::abs(y)));
}

bool UtilityMath::Compare(Vector2 vec1, Vector2 vec2, float epsilon)
{
	return Compare(vec1.x, vec2.x, epsilon) && Compare(vec1.y, vec2.y, epsilon);
}

// Overloaded functions without epsilon

bool UtilityMath::Compare(float x, float y)
{
	return glm::abs(x - y) <= FLT_MIN * glm::max(1.0f, glm::max(glm::abs(x), glm::abs(y)));
}

bool UtilityMath::Compare(Vector2 vec1, Vector2 vec2)
{
	return Compare(vec1.x, vec2.x) && Compare(vec1.y, vec2.y);
}
