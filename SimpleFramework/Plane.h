#pragma once

#include "RigidBody.h"

class Plane : public PhysicsObject
{
private:
	Vector3 colour = { 0, 0, 1.0f };

	Vector2 normal = Vector3(0, 0, 0);
	float offset = 0;
	float length = FLT_MAX;

public:
	Plane() {}
	Plane(Vector2 norm, float dist);
	~Plane();

	virtual void Update(float deltaTime);
	virtual void Render(LineRenderer& lines);
	
	Vector2 GetNormal() const { return normal; };
	float GetOffset() const { return offset; }

};

