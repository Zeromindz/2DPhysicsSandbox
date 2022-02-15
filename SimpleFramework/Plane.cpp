#include "Plane.h"


Plane::Plane()
{
	offset = 0;
	normal = Vector2(0, 1);
}

Plane::Plane(Vector2 norm, float dist) : PhysicsObject(ShapeType::PLANE)
{
	SetShapeID(ShapeType::PLANE);

	normal = norm;
	offset = dist;

}

Plane::~Plane()
{
	
}

void Plane::Update(Vector2 grav, float time)
{

}

void Plane::Render(LineRenderer& lines)
{
	Vector2 centerPoint = normal * offset;
	Vector2 parallel(normal.y, -normal.x);
	
	Vector2 start = centerPoint + (parallel * length);
	Vector2 end = centerPoint - (parallel * length);

	lines.DrawLineSegment(start, end, colour);
	lines.DrawLineSegment(centerPoint, centerPoint + normal, Vector3(1, 0, 1));
	lines.DrawCircle(centerPoint, 0.3f, Vector3(1, 1, 1));
}


void Plane::ResolveCollision(RigidBody* obj)
{
	Vector2 normal = glm::normalize(obj->GetPosition() - (normal * offset));
	Vector2 relativeVelocity = obj->GetVelocity();

	float elasticity = 1;
	float j = glm::dot(-(1 + elasticity) * (relativeVelocity), normal) + (1 / obj->GetMass());

	Vector2 force = normal * j;

	float kePre = obj->GetKineticEnergy();

	ApplyForceToObject(obj, -force);

	float kePost = obj->GetKineticEnergy();

	float deltaKE = kePost - kePre;
	if (deltaKE > kePost * 0.01f)
	{
		// kinetic discrepancy
	}
}


void Plane::ApplyForceToObject(RigidBody* object2, Vector2 force)
{
	object2->ApplyForce(force);
}
