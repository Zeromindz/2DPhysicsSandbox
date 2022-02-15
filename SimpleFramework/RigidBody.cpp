#include "RigidBody.h"


RigidBody::RigidBody(ShapeType shapeID)
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
	position += linearVelocity * deltaTime; // Update pos based on vel
	ApplyForce(gravity * mass * deltaTime); // Apply gravity force

	currentGravity = gravity; // store gravity
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

	float kePre = GetKineticEnergy() + object2->GetKineticEnergy();

	ApplyForceToObject(object2, -force);

	float kePost = GetKineticEnergy() + object2->GetKineticEnergy();

	float deltaKE = kePost - kePre;
	if (deltaKE > kePost * 0.01f)
	{
		// kinetic discrepancy
	}
}


float RigidBody::GetKineticEnergy()
{
	// Ek = ½ mv2
	
	float kEnergy;
	kEnergy = glm::length((GetMass() * (GetVelocity() * GetVelocity())) * 0.5f);
	return kEnergy;
	
}

float RigidBody::GetPotentialEnergy()
{
	return - GetMass() * glm::dot(currentGravity, GetPosition());
}

