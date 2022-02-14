#pragma once

#include "Shape.h"
#include "LineRenderer.h"
#include "Maths.h"

class CollisionManifold
{
public:
	CollisionManifold();
	CollisionManifold(Vector2 norm, float dep);


	void AddContactPoint(Vector2 contact) { contactPoints.push_back(contact); }
	Vector2 GetNormal() { return normal; }
	std::vector<Vector2> GetContactPoints() { return contactPoints; }
	float GetDepth() { return depth; }
private:
	std::vector<Vector2> contactPoints;
	Vector2 normal;
	float depth;

	//Shape* shapeA;
	//Shape* shapeB;

	//void Render(LineRenderer& lines);

	//bool IsColliding() const { return depth > 0; }
};
