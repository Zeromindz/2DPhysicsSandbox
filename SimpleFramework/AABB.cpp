#include "AABB.h"

AABB::AABB()
{
    size = Vector2(1.5f, 1.5f);
    halfSize = { size.x / 2.0f, size.y / 2.0f };
}

AABB::AABB(Vector2 min, Vector2 max)
{
    size = max - min;
    halfSize = { size.x / 2.0f, size.y / 2.0f };
}

AABB::AABB(Vector2 pos, Vector2 vel, Vector2 size, float mass) : RigidBody(ShapeType::BOX, pos, vel, 0, mass)
{
	SetShapeID(ShapeType::BOX);

	SetTransform(pos);
	SetVelocity(vel);

	SetSize(size);
	SetMass(mass);
}


void AABB::Render(LineRenderer& lines)
{
	Vector2 min = GetLocalMin();
	Vector2 max = GetLocalMax();

	lines.DrawLineSegment(min, Vector2(min.x, min.y + size.y)); // bottom left > top left
	lines.DrawLineSegment(Vector2(min.x, min.y + size.y), max); // top left > top right
	lines.DrawLineSegment(max, Vector2(max.x, max.y - size.y)); // top right right > bottom right 
	lines.DrawLineSegment(Vector2(max.x, max.y - size.y), min); // bottom right  > bottom left

	lines.DrawLineSegment(GetPosition(), GetPosition() + GetVelocity(), colour);
}

void AABB::SetSize(Vector2 newSize)
{
	size = newSize;
	halfSize = Vector2(size.x * 0.5f, size.y * 0.5f);
}






