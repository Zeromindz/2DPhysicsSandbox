#include "Particle.h"

Particle::Particle()
{
	Initialize();

	vel.x = GetRandomFloat(-3, 3);
	vel.y = GetRandomFloat(-3, 3);
}

void Particle::Update(float deltaTime)
{
	PhysicsObject::Update(deltaTime);
	//Update particle position
	//pos += vel * deltaTime;
	//vel += acc * deltaTime;
	//
	//// x reflection
	//if (pos.x - size <= -15 || pos.x + size >= 15)
	//{
	//	vel.x = -vel.x;
	//}
	//// y reflection
	//if (pos.y - size <= -15 || pos.y + size >= 15)
	//{
	//	vel.y = -vel.y;
	//}
}

void Particle::Render(LineRenderer& lines)
{
	//Render GFX
	lines.DrawCircle(pos, 0.2f, colour);
}

void Particle::OnCollision(Vector2 otherPos, Vector2 dir)
{
	colour = { 0, 1, 0 };
	collided = true;
}

void Particle::Initialize()
{
	pos = { GetRandomFloat(-20, 20), GetRandomFloat(-20, 20) };

	acc = { 0, 0 };
	colour = { 1, 0.2f, 0.2f };
	size = 0.2f;
}