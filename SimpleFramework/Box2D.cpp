#include "Box2D.h"
#include "UtilityMath.h"

Box2D::Box2D()
{
	size = Vector2(1.5f, 1.5f);
	halfSize = size * 0.5f;
}

Box2D::Box2D(Vector2 min, Vector2 max)
{
	size = max - min;
	halfSize = size * 0.5f;
}

Box2D::~Box2D()
{
}

void Box2D::Update(float deltaTime)
{
}

void Box2D::Render(LineRenderer& lines)
{
	Vector2 min = GetLocalMin();
	Vector2 max = GetLocalMax();

	lines.DrawLineSegment(min, min + size.y); // bottom left > top left
	lines.DrawLineSegment(min + size.y, max); // top left > top right
	lines.DrawLineSegment(max, max - size.y); // top right right > bottom right 
	lines.DrawLineSegment(max - size.y, min); // bottom right  > bottom left
}

std::vector<Vector2> Box2D::GetVerticies()
{
	Vector2 min = GetLocalMin();
	Vector2 max = GetLocalMax();

	std::vector<Vector2> result;

	result.push_back(Vector2(min.x, min.y));
	result.push_back(Vector2(min.x, max.y));
	result.push_back(Vector2(max.x, min.y));
	result.push_back(Vector2(max.x, max.y));

	if (rb.GetRotation() != 0.0f)
	{
		for (Vector2 vert : result)
		{
			UtilityMath::Rotate(vert, rb.GetRotation(), rb.GetPosition());
		}
	}

	return result;
}