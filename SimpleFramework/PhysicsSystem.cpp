#include "PhysicsSystem.h"

typedef bool(*fn)(PhysicsObject*, PhysicsObject*);

static fn CollisionFunctionArray[]
{
	PhysicsSystem::CircleToCircle,
	PhysicsSystem::CircleToPlane,
	PhysicsSystem::PlaneToCircle,

	//PhysicsSystem::PointOnLine,
	//PhysicsSystem::PointInCircle,
	//PhysicsSystem::PointInAABB,
	//PhysicsSystem::PointInBox2D,
	//
	//PhysicsSystem::LineAndAABB,
	//PhysicsSystem::LineAndBox2D,
	//
	//PhysicsSystem::CircleToCircle
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

				// using function pointers 
				int functionIdx = (shapeId1 * (int)PhysicsObject::ShapeType::COUNT) + shapeId2;
				fn collisionFunctionPtr = CollisionFunctionArray[functionIdx];
				if (collisionFunctionPtr != nullptr)
				{
					// did a collision occur? 
					collisionFunctionPtr(obj1, obj2);
				}
				//RigidBody* r1 = objects[i];
				//RigidBody* r2 = objects[j];

				//
			}
		}
	}
		



	//bodies1.clear();
	//bodies2.clear();
	//collisions.clear();

	

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

void PhysicsSystem::AddObject(RigidBody* object)
{
	objects.push_back(object);
}

void PhysicsSystem::RemoveObject(RigidBody* object)
{
	
}

void PhysicsSystem::CheckForCollision()
{
}

bool PhysicsSystem::CircleToCircle(PhysicsObject* obj1, PhysicsObject* obj2)
{
	// Attempt to cast objects as circles
	CircleCollider* circle1 = dynamic_cast<CircleCollider*>(obj1);
	CircleCollider* circle2 = dynamic_cast<CircleCollider*>(obj2);
	// if cast is successful, test for collision
	if (circle1 != nullptr && circle2 != nullptr)
	{
		// TODO if the spheres touch, set their velocities to zero for now
		Vector2 dist = circle1->GetPosition() - circle2->GetPosition();
		if (glm::length(dist) < circle1->GetRadius() + circle2->GetRadius()) {
			// collision 
			// for now, just stop the spheres 
			circle1->SetVelocity(-circle1->GetVelocity());
			circle2->SetVelocity({ 0, 0 });
			return true;
		}
	}
	return false;
}

bool PhysicsSystem::CircleToPlane(PhysicsObject* obj1, PhysicsObject* obj2)
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
			circle->ApplyForce(-circle->GetVelocity() * circle->GetMass());
			return true;
		}
	}
	return false;
}

bool PhysicsSystem::PlaneToCircle(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return CircleToPlane(obj2, obj1);
}



