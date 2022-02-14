#include "CollisionManifold.h"

CollisionManifold::CollisionManifold()
{
	normal = { 0, 0 };
	depth = 0;
}

CollisionManifold::CollisionManifold(Vector2 norm, float dep)
{
	normal = norm;
	depth = dep;
}

//void CollisionManifold::Render(LineRenderer& lines)
//{
//	if (depth > 0)
//	{
//		lines.DrawLineSegment(worldPos, worldPos + normal * depth);
//
//	}
//}
