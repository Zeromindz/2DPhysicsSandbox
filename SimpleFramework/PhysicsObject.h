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
		SHAPE,
		CIRCLE,
		PLANE,
		BOX,
		PARTICLE,

		COUNT
	};

	PhysicsObject() {}
	PhysicsObject(ShapeType shapeType) : shapeID(shapeType) {}
	
	virtual void Update(Vector2 gravity, float timestep) = 0;
	virtual void Render(LineRenderer& lines);
	virtual void ResetPosition() {};

	ShapeType GetShapeID() { return shapeID; }

private:
	ShapeType shapeID = ShapeType::SHAPE;
};

