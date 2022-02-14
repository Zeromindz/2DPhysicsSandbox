#include "Plane.h"


Plane::Plane() : RigidBody(ShapeType::PLANE)
{
	offset = 0;
	normal = Vector2(0, 1);
}

Plane::Plane(Vector2 norm, float dist)
{
	normal = norm;
	offset = dist;
}

Plane::~Plane()
{
	
}

void Plane::Update(Vector2 grav, float timeStep)
{


	//PhysicsObject::Update(deltaTime);
}

void Plane::Render(LineRenderer& lines)
{
	Vector2 centerPoint = normal * offset;
	Vector2 parallel(normal.y, -normal.x);
	
	Vector2 start = centerPoint + (parallel * length);
	Vector2 end = centerPoint - (parallel * length);

	lines.DrawLineSegment(start, end, colour);


}
