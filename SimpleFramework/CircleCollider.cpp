#include "CircleCollider.h"


CircleCollider::CircleCollider(Vector2 position, Vector2 velocity, float mass, float radius, Vector3 colour) : RigidBody(ShapeType::CIRCLE)
{
	m_radius = radius;
	m_colour = colour;

}

void CircleCollider::Update(float deltaTime)
{


	PhysicsObject::Update(deltaTime);
}

void CircleCollider::Render(LineRenderer& lines)
{
	lines.DrawCircle(centre, m_radius, m_colour);
}
