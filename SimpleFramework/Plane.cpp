#include "Plane.h"


Plane::Plane(Vector2 norm, float dist) : PhysicsObject(ShapeType::PLANE)
{

}

Plane::~Plane()
{
	
}

void Plane::Update(float deltaTime)
{


	PhysicsObject::Update(deltaTime);
}

void Plane::Render(LineRenderer& lines)
{
	Vector2 centerPoint = normal * offset;
	Vector2 parallel(normal.y, -normal.x);
	
	Vector2 start = centerPoint + (parallel * length);
	Vector2 end = centerPoint - (parallel * length);

	lines.DrawLineSegment(start, end, colour);


}
