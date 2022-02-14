#include "CircleCollider.h"


CircleCollider::CircleCollider(Vector2 position, Vector2 velocity, float mass, float radius, Vector3 colour) : RigidBody(ShapeType::CIRCLE, position, velocity, 0, mass)
{

	
	//rb = RigidBody(ShapeType::CIRCLE, position, velocity, GetRotation(), mass);
	rb.SetTransform(position);
	
	m_radius = radius;
	m_colour = colour;
	
}



void CircleCollider::Render(LineRenderer& lines)
{
	lines.DrawCircle(GetPosition(), m_radius, m_colour);
}


