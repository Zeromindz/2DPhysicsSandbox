#include "GameWorld.h"

GameWorld::GameWorld()
{
	Vector2 pos1 = { 5.0f, 4.0f };
	Vector2 pos2 = { -5.0f, -4.0f };
	aabb1 = new AABB(pos1, 3.0f, 5.0f);
	aabb2 = new AABB(pos2, 1.0f, 4.0f);
	AddObject(aabb1);
	AddObject(aabb2);

	Vector2 up = { 0.0f, 1.0f };
	Vector2 right = { 1.0f, 0.0f };

	planes.push_back(new Plane(up, 10.0f));
	planes.push_back(new Plane(right, 10.0f));
	planes.push_back(new Plane(-up, 10.0f));
	planes.push_back(new Plane(-right, 10.0f));
	
	for (int i = 0; i < particleCount; i++)
	{
		particles.push_back(new Particle());
	}
}

void GameWorld::Update()
{

	for (AABB* obj : objects)
	{
		obj->Update(deltaTime);	
	}

	for (Particle* particle : particles)
	{
		particle->Update(deltaTime);
	}

	for (Plane* plane : planes)
	{
		plane->Update(deltaTime);
	}

	//This call ensures that your mouse position and aspect ratio are maintained as correct.
	GameBase::Update();
}

void GameWorld::Render()
{
	for (AABB* obj : objects)
	{
		obj->Render(lines);
	}

	for (Particle* particle : particles)
	{
		particle->Render(lines);
	}

	for (Plane* plane : planes)
	{
		plane->Render(lines);
	}

	//This call puts all the lines you've set up on screen - don't delete it or things won't work.
	GameBase::Render();
}

void GameWorld::AddObject(AABB* object)
{
	objects.push_back(object);
}

void GameWorld::RemoveObject(AABB* object)
{

}

void GameWorld::StepThroughObjects(float deltaTime)
{
	for (AABB* obj : objects)

	{
		obj->Update(deltaTime);
		obj->Render(lines);
	}
}
