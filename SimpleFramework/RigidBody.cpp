#include "RigidBody.h"


RigidBody::RigidBody()
{

}

RigidBody::RigidBody(ShapeType shapeType)
{

}

RigidBody::RigidBody(ShapeType shapeID, Vector2 position, Vector2 velocity, float orient, float mass)
{

}

void RigidBody::Update(float deltaTime)
{
	//Update position
	pos += vel * deltaTime;
	vel += acc * deltaTime;
}

void RigidBody::Render(LineRenderer& lines)
{

}

void RigidBody::ApplyForce(Vector2 force)
{

}
