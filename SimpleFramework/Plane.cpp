#include "Plane.h"

Plane::Plane(Vector2 norm, float dist)
{
	normal = norm;
	offset = dist;
	length = 10.0f;
}

void Plane::Update(float deltaTime)
{

}

void Plane::Render(LineRenderer& lines)
{
	Vector2 centerPoint = normal * offset;
	Vector2 parallel(normal.y, -normal.x);
	
	Vector2 start = centerPoint + (parallel * length);
	Vector2 end = centerPoint - (parallel * length);

	lines.DrawLineSegment(start, end, { 1.0f, 0.0f, 1.0f });


}
