#include "Particle.h"

Particle::Particle()
{
	SetPosition(Vector2(GetRandomFloat(-20, 20), GetRandomFloat(-20, 20)));
	//SetAcceleration(Vector2(0, 0));
	//SetVelocity(Vector2(GetRandomFloat(-3, 3), GetRandomFloat(-3, 3)));

	colour = { 1, 0.2f, 0.2f };
	size = 0.2f;

}

Particle::Particle(Vector2 position, float radius) : RigidBody(ShapeType::PARTICLE)
{

}

void Particle::Update(float deltaTime)
{
	//DEBUG
	Vector2 x = { 0, 0 };
	//x = GetVelocity();
	
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


	PhysicsObject::Update(deltaTime);
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
	
}