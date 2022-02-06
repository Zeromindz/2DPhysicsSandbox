#include "Agent.h"

Agent::Agent(LineRenderer* renderer)
{
	Initialize();

	lines = renderer;
}

void Agent::Update(float deltaTime)
{
	pos += vel * deltaTime;
	vel += acc * deltaTime;

	Vector2 requiredChange = commandPos - pos;
	acc = requiredChange;
}

void Agent::Render(LineRenderer& lines)
{
	lines.DrawCircle(pos, size, colour);

	if (commanded)
	{
		lines.DrawCircle(commandPos, 1, { 0, 1, 0 });
		
	}

	for (auto point : impactPoints)
	{
		lines.DrawCross(point, 0.2f, { 1, 0, 0 });
	}
}

void Agent::OnCollision(Vector2 otherPos)
{
	impactPoints.push_back(otherPos);
}

void Agent::Initialize()
{
	Vector2 pos = { 0, 0 };
	Vector2 vel = { 0, 0 };
	Vector2 acc = { 0, 0 };

	Vector3 colour = { 0.3f, 0.3f, 1 };

	float size = 0.6f;

	commanded = false;
}
