#include "CollisionData.h"

void CollisionData::Render(LineRenderer& lines)
{
	if (depth > 0)
	{
		lines.DrawLineSegment(worldPos, worldPos + normal * depth);

	}
}
