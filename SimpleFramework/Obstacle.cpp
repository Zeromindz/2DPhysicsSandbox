#include "Obstacle.h"

Obstacle::Obstacle(LineRenderer* renderer)
{
	Initialize();
	lines = renderer;
}

void Obstacle::Update(float deltaTime)
{

}

void Obstacle::Render(LineRenderer& lines)
{
	Vector2 posA = { pos.x - width / 2, pos.y + height / 2 };
	Vector2 posB = { pos.x + width / 2, pos.y + height / 2 };
	Vector2 posC = { pos.x + width / 2, pos.y - height / 2 };
	Vector2 posD = { pos.x - width / 2, pos.y - height / 2 };
	lines.DrawLineSegment(posA, posB);
	lines.DrawLineSegment(posB, posC);
	lines.DrawLineSegment(posC, posD);
	lines.DrawLineSegment(posD, posA);
}

void Obstacle::Initialize()
{
	pos = { GetRandomFloat(-50, 50), GetRandomFloat(-50, 50) };

	width = 1.0f;
	height = 1.0f;

	colour = { 1, 1, 1 };
}
