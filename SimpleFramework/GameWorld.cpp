#include "GameWorld.h"

GameWorld::GameWorld() : GameBase()
{
	circleTest = CircleCollider({ 2.0f, 2.0f }, { 1.0f, 0.0f }, 0, 0.5f, { 1, 1, 1 });
	boxTest = AABB(-1.0f, 1.0f, -1.0f, 1.0f);

	AddObject(circleTest);
	AddObject(boxTest);

	for (int i = 0; i < particleCount; i++)
	{
		particles.push_back(Particle());
	}
}

void GameWorld::AddObject(PhysicsObject object)
{
	objects.push_back(object);
}

void GameWorld::RemoveObject(PhysicsObject object)
{
	
}

void GameWorld::Update()
{
	collisionData = CollideAABBToCircle(boxTest, circleTest, lines);
	circleTest.SetCenter(cursorPos);

	for (PhysicsObject object : objects)
	{
		object.Update(deltaTime);
	}

	for (Particle particle : particles)
	{
		particle.Update(deltaTime);
	}

	//This call ensures that your mouse position and aspect ratio are maintained as correct.
	GameBase::Update();
}

void GameWorld::Render()
{

	//circleTest.Render(lines);
	//boxTest.Render(lines);
	for (PhysicsObject object : objects)
	{
		object.Render(lines);
	}

	for (Particle particle : particles)
	{
		particle.Render(lines);
	}

	//This call puts all the lines you've set up on screen - don't delete it or things won't work.
	GameBase::Render();
}

/*
void GameWorld::StepThroughObjects(float deltaTime)
{
	CollisionData result;

	for (int i = 0; i < objects.size(); i++)
	{
		for (int o = i + 1; o < objects.size(); o++)
		{
			if (objects[i].shapeID == RigidBody::ShapeType::CIRCLE)
			{
				
			}
			else if (objects[i].shapeID == RigidBody::ShapeType::PLANE)
			{

			}
			else if (objects[i].shapeID == RigidBody::ShapeType::BOX)
			{

			}
			else if(objects[i].shapeID == RigidBody::ShapeType::PARTICLE)
			{

			}
		}
	}
	*/

