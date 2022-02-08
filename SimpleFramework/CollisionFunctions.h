#pragma once

#include "CollisionData.h"
#include "CircleCollider.h"
#include "AABB.h"
#include "Plane.h"

CollisionData CollideAABBToAABB(const AABB& boxA, const AABB& boxB, LineRenderer& lines); 
CollisionData CollideAABBToPlane(const AABB& box, const Plane& plane, LineRenderer& lines);
CollisionData CollideAABBToCircle(const AABB& box, const CircleCollider& circle, LineRenderer& lines);

CollisionData CollideCircleToCircle(const CircleCollider& circle1, const CircleCollider& circle2, LineRenderer& lines);
CollisionData CollideCircleToPlane(const CircleCollider& circle, const Plane& plane, LineRenderer& lines);



