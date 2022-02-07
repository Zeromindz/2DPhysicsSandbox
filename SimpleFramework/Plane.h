#pragma once

#include "PhysicsObject.h"

class Plane : public PhysicsObject
{
public:
	Plane(Vector2 norm, float dist);

	void Update(float deltaTime);
	void Render(LineRenderer& lines);
	
	Vector2 GetNormal() { return normal; };
	float GetOffset() { return offset; }
private:
	Vector2 normal;
	float offset;
	float length;
};

