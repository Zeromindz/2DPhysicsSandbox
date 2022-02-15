#pragma once

#include "glm.hpp"
#include "LineRenderer.h"
#include "Utilities.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;


class PhysicsObject
{

public:
	enum class ShapeType
	{
		//SHAPE, // 0
		PLANE, // 1
		BOX,   // 2
		CIRCLE,// 3
		//PARTICLE,

		COUNT  // 4
	};

	PhysicsObject() {}
	PhysicsObject(ShapeType shapeType) : shapeID(shapeType) {}
	
	virtual void Update(Vector2 gravity, float timestep) = 0;
	virtual void Render(LineRenderer& lines);
	virtual void ResetPosition() {};

	ShapeType GetShapeID() { return shapeID; }
	void SetShapeID(ShapeType type) { shapeID = type; }

private:
	ShapeType shapeID = ShapeType::PLANE;
};

				//	PhysicsSystem::PlaneToAABB, PhysicsSystem::PlaneToCircle, PhysicsSystem::AABBToPlane, 
				//  PhysicsSystem::AABBToAABB,  PhysicsSystem::AABBToCircle,  PhysicsSystem::CircleToPlane,
				//  PhysicsSystem::CircleToBox, PhysicsSystem::CircleToCircle