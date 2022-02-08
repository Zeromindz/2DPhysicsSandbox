#pragma once

#include "glm.hpp"
#include "LineRenderer.h"
#include "Utilities.h"
#include "RigidBody.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;


struct Particle : public RigidBody
{
private:
	Vector3 colour = { 1, 0.2f, 0.2f };
	Vector2 pos = {0, 0};
	float size = 0.2f;


public:
	Particle();
	Particle(Vector2 position, float radius);


	void Initialize();

	void Update(float deltaTime);
	void Render(LineRenderer& lines);

	void OnCollision(Vector2 otherPos, Vector2 dir);

	Vector2 GetCurrentPos() const { return pos; }
	
	float GetSize() const { return size; }

	bool collided = false;
};

