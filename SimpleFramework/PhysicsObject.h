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

	ShapeType shapeID;
	PhysicsObject() {}
	PhysicsObject(ShapeType shapeType) : shapeID(shapeType) {}
	

	virtual void Update(float deltaTime);
	virtual void Render(LineRenderer& lines);

};

