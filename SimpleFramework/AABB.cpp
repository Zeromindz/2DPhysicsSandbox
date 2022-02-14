#include "AABB.h"

AABB::AABB() : RigidBody(ShapeType::BOX)
{
    size = Vector2(1.5f, 1.5f);
    halfSize = { size.x / 2.0f, size.y / 2.0f };
}

AABB::AABB(Vector2 min, Vector2 max)
{
    size = max - min;
    halfSize = { size.x / 2.0f, size.y / 2.0f };
}

void AABB::Update(float deltaTime)
{

}

void AABB::Render(LineRenderer& lines)
{
	Vector2 min = GetLocalMin();
	Vector2 max = GetLocalMax();

	lines.DrawLineSegment(min, min + size.y); // bottom left > top left
	lines.DrawLineSegment(min + size.y, max); // top left > top right
	lines.DrawLineSegment(max, max - size.y); // top right right > bottom right 
	lines.DrawLineSegment(max - size.y, min); // bottom right  > bottom left
}




