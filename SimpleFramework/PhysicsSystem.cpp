#include "PhysicsSystem.h"

typedef bool(*fn)(PhysicsObject*, PhysicsObject*, CollisionManifold&);

static fn CollisionFunctionArray[]
{
	PhysicsSystem::PlaneToPlane,  PhysicsSystem::PlaneToAABB, PhysicsSystem::PlaneToCircle,
	PhysicsSystem::AABBToPlane,   PhysicsSystem::AABBToAABB,  PhysicsSystem::AABBToCircle,
	PhysicsSystem::CircleToPlane, PhysicsSystem::CircleToBox, PhysicsSystem::CircleToCircle
};

PhysicsSystem::PhysicsSystem() : timeStep(0.01f), gravity({ 0, 0 })
{

}

PhysicsSystem::~PhysicsSystem()
{
	for(auto object : objects)
	{
		delete object;
	}
}

void PhysicsSystem::Update(float deltaTime)
{

	static float accumulatedTime = 0.0f;
	accumulatedTime += deltaTime;

	while (accumulatedTime >= timeStep)
	{
		for (auto object : objects)
		{
			object->Update(gravity, timeStep);
		}
		accumulatedTime -= timeStep;

		// Find collision

		int size = (int)objects.size();

		// Iterate all objects twice, checking for collision
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (i == j)
				{
					continue;
				}
				CollisionManifold result = CollisionManifold();

				PhysicsObject* obj1 = objects[i];
				PhysicsObject* obj2 = objects[j];

				int shapeId1 = (int)obj1->GetShapeID();
				int shapeId2 = (int)obj2->GetShapeID();

				//	*SHAPE*, 0 PLANE, 1 BOX, 2 CIRCLE, 3 COUNT

				// plane(0) * count(3) + plane(0)   = 0	  * plane2plane 
				// 
				// plane(0) * count(3) + box(1)     = 1		plane2box 
				// plane(0) * count(3) + circle(2)  = 2		plane2circle 
				// box(1) * count(3) + plane(0)	    = 3		box2plane 
				// box(1) * count(3) + box(1)	    = 4		box2box 
				// box(1) * count(3) + circle(2)    = 5		box2circle 
				// circle(2) * count(3) + plane(0)  = 6		circle2plane!
				// circle(2) * count(3) + box(1)    = 7		circle2box
				// circle(2) * count(3) + circle(2) = 8		circle2circle

				// using function pointers 
				int functionIdx = (shapeId1 * (int)PhysicsObject::ShapeType::COUNT) + shapeId2;
				fn collisionFunctionPtr = CollisionFunctionArray[functionIdx];
				if (collisionFunctionPtr != nullptr)
				{
					// did a collision occur? 
					collisionFunctionPtr(obj1, obj2, result);
					//AABBToAABB(obj1, obj2);
				}
				//RigidBody* r1 = objects[i];
				//RigidBody* r2 = objects[j];

				//
			}
		}
	}

	// Update forces

	// Resolve collisions

	// Update velocities

	
}

void PhysicsSystem::Render(LineRenderer& lines)
{
	for (auto object : objects)
	{
		object->Render(lines);
	}
}

void PhysicsSystem::AddObject(PhysicsObject* object)
{
	objects.push_back(object);
}

void PhysicsSystem::RemoveObject(PhysicsObject* object)
{

}

//--------------------------------------------------------------/
//	Collision Functions
//____________________________________________________________/

void PhysicsSystem::CheckForCollision()
{

}

void PhysicsSystem::ApplyContactForces(RigidBody* body1, RigidBody* body2, Vector2 norm, float pen)
{
	float body2Mass = body2 ? body2->GetMass() : INT_MAX;

	float body1Factor = body2Mass / (body1->GetMass() + body2Mass);

	body1->SetTransform(body1->GetPosition() - body1Factor * norm * pen);

	if (body2)
	{
		body2->SetTransform(body2->GetPosition() + (1 - body1Factor) * norm * pen);
	}
}

//-----------------------/
// COLLISION INDEX: 0
//_____________________/
bool PhysicsSystem::PlaneToPlane(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	return false;
}
//-----------------------/
// COLLISION INDEX: 1
//_____________________/
bool PhysicsSystem::PlaneToAABB(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	return AABBToPlane(obj2, obj1, collsionData);
}
//-----------------------/
// COLLISION INDEX: 2
//_____________________/
bool PhysicsSystem::PlaneToCircle(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	return CircleToPlane(obj2, obj1, collsionData);
}
//-----------------------/
// COLLISION INDEX: 3
//_____________________/
bool PhysicsSystem::AABBToPlane(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	AABB* box1 = dynamic_cast<AABB*>(obj1);
	Plane* plane2 = dynamic_cast<Plane*>(obj2);

	if (box1 != nullptr && plane2 != nullptr)
	{
		Vector2 boxMin = box1->GetLocalMin();
		Vector2 boxMax = box1->GetLocalMax();

		Vector2 planeNormal = plane2->GetNormal();
		
		//V`a = Va − 1 + 𝑒 𝑉𝐴 ∙𝑛 ∗𝑛

		return true;
	}

	return false;
}
//-----------------------/
// COLLISION INDEX: 4
//_____________________/
bool PhysicsSystem::AABBToAABB(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	// Attempt to cast objects as circles
	AABB* box1 = dynamic_cast<AABB*>(obj1);
	AABB* box2 = dynamic_cast<AABB*>(obj2);
	// if cast is successful, test for collision
	if (box1 != nullptr && box2 != nullptr)
	{
		Vector2 b1Size = box1->GetSize();
		Vector2 b2Size = box2->GetSize();

		if (box1->GetPosition().x < box2->GetPosition().x + b2Size.x &&
			box1->GetPosition().x + b1Size.x > box2->GetPosition().x &&
			box1->GetPosition().y < box2->GetPosition().y + b2Size.y &&
			box1->GetPosition().y + b1Size.y > box2->GetPosition().y)
		{
			

			//r=d−2(d dot n)n
			/*float d = glm::dot(glm::normalize(box1->GetVelocity()), glm::normalize(box2->GetVelocity()));
			Vector2 reflection = glm::normalize(box1->GetVelocity()) - (2 * d) * glm::normalize(box2->GetVelocity());
			glm::normalize(reflection);

			float velMag1 = glm::length(box1->GetVelocity());
			float velMag2 = glm::length(box2->GetVelocity());*/

			//collsionData.SetNormal(glm::normalize(box2->GetPosition() - box1->GetPosition()));

			//box1->ResolveCollision(box2);//

			// Collision
			//box1->SetVelocity(-reflection * velMag1);
			//box2->SetVelocity(reflection * velMag2);
			
			

			return true;
		}
	}
	return false;
}
//-----------------------/
// COLLISION INDEX: 5
//_____________________/
bool PhysicsSystem::AABBToCircle(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	// Attempt to cast objects as circles
	AABB* box1 = dynamic_cast<AABB*>(obj1);
	CircleCollider* circle2 = dynamic_cast<CircleCollider*>(obj2);
	// if cast is successful, test for collision
	if (box1 != nullptr && circle2 != nullptr)
	{
		return true;
	}

	return false;
}
//-----------------------/
// COLLISION INDEX: 6
//_____________________/
bool PhysicsSystem::CircleToPlane(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	CircleCollider* circle = dynamic_cast<CircleCollider*>(obj1);
	Plane* plane = dynamic_cast<Plane*>(obj2);

	if (circle != nullptr && plane != nullptr)
	{
		Vector2 collisionNormal = plane->GetNormal();
		float circleToPlane = glm::dot(circle->GetPosition(), plane->GetNormal()) - plane->GetOffset();
		float intersection = circle->GetRadius() - circleToPlane;
		float velocityOutOfPlane = glm::dot(circle->GetVelocity(), plane->GetNormal());
		if (intersection > 0 && velocityOutOfPlane < 0)
		{
			//set sphere velocity to zero here 
			//circle->ApplyForce(-circle->GetVelocity() * circle->GetMass());
			circle->ApplyForce(-glm::normalize(circle->GetVelocity()) * glm::length(circle->GetVelocity()));
			return true;
		}
	}
	return false;
}
//-----------------------/
// COLLISION INDEX: 7
//_____________________/
bool PhysicsSystem::CircleToBox(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	return false;
}
//-----------------------/
// COLLISION INDEX: 8
//_____________________/
bool PhysicsSystem::CircleToCircle(PhysicsObject* obj1, PhysicsObject* obj2, CollisionManifold& collsionData)
{
	// Attempt to cast objects as circles
	CircleCollider* circle1 = dynamic_cast<CircleCollider*>(obj1);
	CircleCollider* circle2 = dynamic_cast<CircleCollider*>(obj2);
	// if cast is successful, test for collision
	if (circle1 != nullptr && circle2 != nullptr)
	{
		Vector2 dist = circle1->GetPosition() - circle2->GetPosition(); // Measure distance between spheres
		if (glm::length(dist) < circle1->GetRadius() + circle2->GetRadius()) // If r+r is less than the distance
		{
			// Collision has occured 
			circle1->ResolveCollision(circle2);
			//circle1->SetVelocity(Vector2(0,0));
			//circle2->SetVelocity(Vector2(0, 0));
			
			return true;
		}
	}
	return false;
}

float PhysicsSystem::GetTotalEnergy()
{
	float total = 0;
	for (auto pObject : objects)
	{
		RigidBody* obj = dynamic_cast<RigidBody*>(pObject);
		total += obj->GetKineticEnergy();
	}
	return total;
}
