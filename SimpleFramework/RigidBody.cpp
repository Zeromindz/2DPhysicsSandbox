#include "RigidBody.h"


RigidBody::RigidBody(ShapeType shapeID) : RigidBody(ShapeType::SHAPE, { 0, 0 }, { 0, 0}, 0, 0)
{

}

RigidBody::RigidBody(ShapeType shapeID, Vector2 pos, Vector2 vel, float rot, float ma)
{
	position = pos;
	rotation = rot;
	linearVelocity = vel;
	mass = ma;
	linearVelocity = vel;
}

RigidBody::~RigidBody()
{

}

void RigidBody::Update(Vector2 gravity, float deltaTime)
{
	position += linearVelocity * deltaTime;
	ApplyForce(gravity * mass * deltaTime);
}

void RigidBody::ApplyForce(Vector2 force)
{
	// f = m * a
	// a = f / m

	acceleration = force / mass;
	
	linearVelocity += acceleration;

}

void RigidBody::ApplyForceToObject(RigidBody* object2, Vector2 force)
{
	object2->ApplyForce(force);
	//Vector2 inverseForce;
	//ApplyForce(inverseForce);
}

void RigidBody::ResolveCollision(RigidBody* object2)
{
	Vector2 normal = glm::normalize(object2->GetPosition() - position);
	Vector2 relativeVelocity = object2->GetVelocity() - linearVelocity;

	float elasticity = 1;
	float j = glm::dot(-(1 + elasticity) * (relativeVelocity), normal) / ((1 / mass) + (1 / object2->GetMass()));

	Vector2 force = normal * j;
	ApplyForceToObject(object2, -force);
}

