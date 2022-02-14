#include "GameWorld.h"

GameWorld::GameWorld() : GameBase()
{
	StartUp();

}


void GameWorld::Update()
{
	physicsSystem->Update(deltaTime);
	//agent->Update(deltaTime);

	//This call ensures that your mouse position and aspect ratio are maintained as correct.
	GameBase::Update();
}

void GameWorld::Render()
{
	physicsSystem->Render(lines);
	//agent->Render(lines);

	//This call puts all the lines you've set up on screen - don't delete it or things won't work.
	GameBase::Render();
}

bool GameWorld::StartUp()
{

	// initialize the physics scene 
	physicsSystem = new PhysicsSystem();
	physicsSystem->SetGravity(Vector2(0, -1.0f));
	physicsSystem->SetTimestep(0.01f);

	CircleCollider* ball1 = new CircleCollider(Vector2(0.3f, 5.0f), Vector2(0, -5), 0.1f, 1.0f, { 1, 0, 0 });
	CircleCollider* ball2 = new CircleCollider(Vector2(0.1f, 0.5f), Vector2(0, 0), 1.0f, 2.0f, { 0, 1, 0 });
	Plane* plane1 = new Plane(Vector2(0, 1), -10);
	Plane* plane2 = new Plane(Vector2(1, 0), 10);
	Plane* plane3 = new Plane(Vector2(0, 1), 10);
	Plane* plane4 = new Plane(Vector2(1, 0), -10);

	//agent = new Agent();


	physicsSystem->AddObject(ball1);
	physicsSystem->AddObject(ball2);
	physicsSystem->AddObject(plane1);
	physicsSystem->AddObject(plane2);
	physicsSystem->AddObject(plane3);
	physicsSystem->AddObject(plane4);
	//physicsSystem->AddObject(agent);

	

	return true;
}


