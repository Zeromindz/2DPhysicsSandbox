#pragma once
#include "glm.hpp"
#include "LineRenderer.h"
#include "Utilities.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

enum class ShapeType
{
	Shape,
	Box,
	Circle,

	Count
};

class Shape
{
	virtual ShapeType GetType() const = 0;
};

class Circle : public Shape
{
	ShapeType GetType() const override { return ShapeType::Circle; }
};

class Box : public Shape
{
	ShapeType GetType() const override { return ShapeType::Box; }
};

//CollisionData CollideTwoShapes(Shape* shapeA, Shape* shapeB)

// if shape a == circle & shape b == circle

// Collide two circles

struct CollisionData
{
	Vector2 worldPos;
	Vector2 normal;
	float depth;

	Shape* shapeA;
	Shape* shapeB;

	bool IsColliding() const { return depth > 0; }
};

/*
{
	for int(i = 0; i < shapes.size(); i++)
	{
		for int j = i + 1; j < shapes.size(); j++)
		{
		CollisionData thisHitData = CollideTwoShapes(shapes[i], shapes[j]);
		if (thisHitData.IsColliding())
		{
			somevectororwhatever.pushback(thishitdata);
		}
		}
	}
}
*/