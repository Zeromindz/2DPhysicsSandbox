#pragma once

#include "RigidBody.h"

class Plane : public RigidBody
{

public:
	Plane();
	Plane(Vector2 norm, float dist);
	~Plane();

	virtual void Update(Vector2 grav, float timeStep);
	virtual void Render(LineRenderer& lines);

	virtual void ResetPosition() {}
	
	Vector2 GetNormal() const { return normal; };
	float GetOffset() const { return offset; }

private:

	Vector2 normal = Vector3(0, 0, 0);
	float offset = 0;
	float length = 1000.0f;

	Vector3 colour = { 0, 0, 1.0f };

};

