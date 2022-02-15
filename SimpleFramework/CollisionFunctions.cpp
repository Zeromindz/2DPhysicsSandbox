#include "CollisionFunctions.h"
/*
bool CollisionDetection2D::CircleToCircle(PhysicsObject* obj1, PhysicsObject* obj2)
{
	// Attempt to cast objects as circles
	CircleCollider* circle1 = dynamic_cast<CircleCollider*>(obj1);
	CircleCollider* circle2 = dynamic_cast<CircleCollider*>(obj1);
	// if cast is successful, test for collision
	if (circle1 != nullptr && circle2 != nullptr)
	{
		// TODO if the spheres touch, set their velocities to zero for now
		Vector2 dist = circle1->GetPosition() - circle2->GetPosition();
		if (glm::length(dist) < circle1->GetRadius() + circle2->GetRadius()) {
			// collision 
			// for now, just stop the spheres 
			//circle1->SetVelocity(Vector2(0, 0));
			//circle2->SetVelocity(Vector2(0, 0));
			return true;
		}
	}
	return false;
}

bool CollisionDetection2D::CircleToPlane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	CircleCollider* circle = dynamic_cast<CircleCollider*>(obj1);
	Plane* plane = dynamic_cast<Plane*>(obj2);

	if (circle != nullptr && plane != nullptr)
	{
		Vector2 collisionNormal = plane->GetNormal();
		float circleToPlane = glm::dot(circle->GetPosition(), plane->GetNormal()) - plane->GetOffset();
		float intersection = circle->GetRadius() - circleToPlane;
		float velocityOutOfPlane = glm::dot(circle->GetVelocity(), plane->GetNormal());
		if (intersection > 0 && velocityOutOfPlane < 0)
		{
			//set sphere velocity to zero here 
			circle->ApplyForce(-circle->GetVelocity() * circle->GetMass());
			return true;
		}
	}
	return false;
}

bool CollisionDetection2D::PlaneToCircle(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return CircleToPlane(obj2, obj1);
}

bool CollisionDetection2D::PointOnLine(Vector2 point, Line2D line)
{
	// y = mx + b

	float dy = line.GetEnd().y - line.GetStart().y;
	float dx = line.GetEnd().x - line.GetStart().x;
	float m = dy / dx;

	float b = line.GetEnd().y - (m * line.GetEnd().x);

	return point.y == m * point.x + b;
}

bool CollisionDetection2D::PointInCircle(Vector2 point, CircleCollider circle)
{
	Vector2 circleCenter = circle.GetCenter();
	Vector2 centerToPoint = point - circleCenter;

	float lengthSquared = sqrt(glm::length(centerToPoint));

	return lengthSquared <= circle.GetRadius() * circle.GetRadius();
}

bool CollisionDetection2D::PointInAABB(Vector2 point, AABB box)
{
	Vector2 min = box.GetLocalMin();
	Vector2 max = box.GetLocalMax();

	return point.x <= max.x && min.x <= point.x &&
		point.y <= max.y && min.y <= point.y;
}

bool CollisionDetection2D::PointInBox2D(Vector2 point, Box2D box)
{
	// Translate point into local space
	Vector2 pointInBoxLocalSpace = point;
	UtilityMath::Rotate(pointInBoxLocalSpace, box.GetRigidbody().GetRotation(),
		box.GetRigidbody().GetPosition());

	Vector2 min = box.GetLocalMin();
	Vector2 max = box.GetLocalMax();

	return pointInBoxLocalSpace.x <= max.x && min.x <= pointInBoxLocalSpace.x &&
		pointInBoxLocalSpace.y <= max.y && min.y <= pointInBoxLocalSpace.y;
}



bool CollisionDetection2D::LineAndAABB(Line2D line, AABB box)
{
	if (PointInAABB(line.GetStart(), box) || PointInAABB(line.GetEnd(), box))
	{
		return true;
	}

	Vector2 unitVector = line.GetEnd() - line.GetStart();
	glm::normalize(unitVector);
	unitVector.x = (unitVector.x != 0) ? 1.0f / unitVector.x : 0;
	unitVector.y = (unitVector.y != 0) ? 1.0f / unitVector.y : 0;

	Vector2 min = box.GetLocalMin();
	min -= line.GetStart() * unitVector;
	Vector2 max = box.GetLocalMax();
	max -= line.GetStart() * unitVector;

	float tmin = glm::max(glm::min(min.x, max.x), glm::min(min.y, max.y));
	float tmax = glm::min(glm::max(min.x, max.x), glm::max(min.y, max.y));

	if (tmax < 0 || tmin > tmax)
	{
		return false;
	}

	float t = (tmin < 0) ? tmax : tmin;
	return t > 0 && t * t < line.LengthSquared();
}

bool CollisionDetection2D::Raycast(CircleCollider circle, Ray2D ray, RaycastResult* result)
{
	Vector2 originToCircle = circle.GetCenter() - ray.GetOrigin();
	float radiusSquared = circle.GetRadius() * circle.GetRadius();
	float originToCircleLengthSquared = (glm::length(originToCircle) * glm::length(originToCircle));

	// Project the vector from the origin onto the direction
	float a = glm::dot(originToCircle, ray.GetDirection());
	float bSq = originToCircleLengthSquared - (a * a);
	if (radiusSquared - bSq < 0.0f)
	{
		return false;
	}

	float f = glm::sqrt(radiusSquared - bSq);
	float t = 0;
	if (originToCircleLengthSquared < radiusSquared)
	{
		// Ray's origin is inside circle
		t = a + f;
	}
	else
	{
		t = a - f;
	}

	if (result != nullptr)
	{
		Vector2 point = ray.GetOrigin() + (ray.GetDirection() * t);
		Vector2 normal = point - circle.GetCenter();
		glm::normalize(normal);

		result->Init(point, normal, t, true);
	}

	return true;
}


bool CollisionDetection2D::LineAndBox2D(Line2D line, Box2D box)
{
	float theta = box.GetRigidbody().GetRotation();
	Vector2 centre = box.GetRigidbody().GetPosition();
	Vector2 localStart = line.GetStart();
	Vector2 localEnd = line.GetEnd();

	UtilityMath::Rotate(localStart, theta, centre);
	UtilityMath::Rotate(localEnd, theta, centre);

	Line2D localLine = Line2D(localStart, localEnd);
	AABB aabb = AABB(box.GetLocalMin(), box.GetLocalMax());

	return LineAndAABB(localLine, aabb);
}






/*
CollisionManifold CollideAABBToAABB(const AABB& boxA, const AABB& boxB, LineRenderer& lines)
{
	CollisionManifold result = CollisionManifold();



	return result;
}

CollisionManifold CollideAABBToPlane(const AABB& box, const Plane& plane, LineRenderer& lines)
{
	CollisionManifold result = CollisionManifold();
	return result;
}

CollisionManifold CollideAABBToCircle(const AABB& box, CircleCollider& circle, LineRenderer& lines)
{
	CollisionManifold result = CollisionManifold();

	Vector2 clampedPos = circle.GetCenter();

	if (clampedPos.x < box.XMin()) clampedPos.x = box.XMin();
	if (clampedPos.x > box.XMax()) clampedPos.x = box.XMax();
	if (clampedPos.y < box.YMin()) clampedPos.y = box.YMin();
	if (clampedPos.y > box.YMax()) clampedPos.y = box.YMax();

	lines.DrawCross(clampedPos, 0.2f);

	Vector2 circletoClamped = clampedPos - circle.GetCenter();
	float distance = glm::length(circletoClamped);
	//result.GetDepth() = circle.GetRadius() - distance;
	//result.GetNormal() = circletoClamped / distance;
	//result. = clampedPos;
	
	return result;
	
}

CollisionManifold CollideCircleToCircle(const CircleCollider& circle1, const CircleCollider& circle2, LineRenderer& lines)
{
	CollisionManifold result = CollisionManifold();
	return result;
}

CollisionManifold CollideCircleToPlane(const CircleCollider& circle, const Plane& plane, LineRenderer& lines)
{
	CollisionManifold result = CollisionManifold();
	return result;
}
*/
