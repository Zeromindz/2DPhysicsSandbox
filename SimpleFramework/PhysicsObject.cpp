#include "PhysicsObject.h"

void PhysicsObject::Update(float deltaTime)
{
	//Update particle position
	pos += vel * deltaTime;
	vel += acc * deltaTime;
}
