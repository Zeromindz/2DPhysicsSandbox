#pragma once

#include "LineRenderer.h"
#include "PhysicsObject.h"
#include "Maths.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;


class CollisionManifold
{
public:
	CollisionManifold();
	CollisionManifold(Vector2 norm, float dep);

	void Render(LineRenderer& lines);

	bool IsColliding() const { return depth > 0; }

	std::vector<Vector2> GetContactPoints() { return contactPoints; }
	void AddContactPoint(Vector2 contact) { contactPoints.push_back(contact); }
	Vector2 GetNormal() { return normal; }
	void SetNormal(Vector3 norm) { normal = norm; }
	float GetDepth() { return depth; }
	void SetDepth(float dep) { depth = dep; }

private:
	std::vector<Vector2> contactPoints;
	Vector2 normal;
	float depth;

	PhysicsObject* shapeA;
	PhysicsObject* shapeB;

};
