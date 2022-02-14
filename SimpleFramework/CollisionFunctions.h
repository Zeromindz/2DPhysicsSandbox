#pragma once

#include "CircleCollider.h"
#include "AABB.h"
#include "Box2D.h"
#include "Ray2D.h"
#include "RaycastResult.h"
#include "Plane.h"

#include "Maths.h"
#include "UtilityMath.h"

class Line2D
{
private:
	Vector2 from;
	Vector2 to;
	Vector3 colour;

public:
	Line2D(Vector2 f, Vector2 t) { from = f; to = t; colour = { 1, 1, 1 }; }
	Line2D(Vector2 f, Vector2 t, Vector3 col) { from = f; to = t; colour = col; }
	Vector2 GetFrom() { return from; }
	Vector2 GetTo() { return to; }
	Vector2 GetStart() { return from; }
	Vector2 GetEnd() { return to; }

	float LengthSquared() {
		return sqrt(glm::length(Vector2(to - from)));
	}
};

class CollisionDetection2D
{
public:

	static bool CircleToCircle(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool CircleToPlane(PhysicsObject* circle, PhysicsObject* plane);
	static bool PlaneToCircle(PhysicsObject* plane, PhysicsObject* circle);

	static bool PointOnLine(Vector2 point, Line2D line);
	static bool PointInCircle(Vector2 point, CircleCollider circle);
	static bool PointInAABB(Vector2 point, AABB box);
	static bool PointInBox2D(Vector2 point, Box2D box);

	static bool LineAndAABB(Line2D line, AABB box);
	static bool LineAndBox2D(Line2D line, Box2D box);

	

	static bool Raycast(CircleCollider circle, Ray2D ray, RaycastResult* result);



	//CollisionManifold CollideAABBToAABB(const AABB& boxA, const AABB& boxB, LineRenderer& lines);
	//CollisionManifold CollideAABBToPlane(const AABB& box, const Plane& plane, LineRenderer& lines);
	//CollisionManifold CollideAABBToCircle(const AABB& box, const CircleCollider& circle, LineRenderer& lines);
	//
	//CollisionManifold CollideCircleToPlane(const CircleCollider& circle, const Plane& plane, LineRenderer& lines);

private:

};




