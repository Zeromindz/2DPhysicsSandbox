#include "CollisionFunctions.h"

CollisionData CollideAABBToAABB(const AABB& boxA, const AABB& boxB, LineRenderer& lines)
{
	CollisionData result = CollisionData();



	return result;
}

CollisionData CollideAABBToPlane(const AABB& box, const Plane& plane, LineRenderer& lines)
{
	CollisionData result = CollisionData();
	return result;
}

CollisionData CollideAABBToCircle(const AABB& box, const CircleCollider& circle, LineRenderer& lines)
{
	CollisionData result = CollisionData();

	Vector2 clampedPos = circle.GetCenter();

	if (clampedPos.x < box.XMin()) clampedPos.x = box.XMin();
	if (clampedPos.x > box.XMax()) clampedPos.x = box.XMax();
	if (clampedPos.y < box.YMin()) clampedPos.y = box.YMin();
	if (clampedPos.y > box.YMax()) clampedPos.y = box.YMax();

	lines.DrawCross(clampedPos, 0.2f);

	Vector2 circletoClamped = clampedPos - circle.GetCenter();
	float distance = glm::length(circletoClamped);
	result.depth = circle.GetRadius() - distance;
	result.normal = circletoClamped / distance;
	result.worldPos = clampedPos;
	
	return result;
	
}

CollisionData CollideCircleToCircle(const CircleCollider& circle1, const CircleCollider& circle2, LineRenderer& lines)
{
	CollisionData result = CollisionData();
	return result;
}

CollisionData CollideCircleToPlane(const CircleCollider& circle, const Plane& plane, LineRenderer& lines)
{
	CollisionData result = CollisionData();
	return result;
}
