#pragma once

#include "glm.hpp"
#include "LineRenderer.h"
#include "Utilities.h"
#include "PhysicsObject.h"
typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;


struct Particle : public PhysicsObject
{
private:

	Vector2 pos = {0, 0};

	Vector3 colour = { 1, 0.2f, 0.2f };
	float size = 0.2f;

	LineRenderer* lines = nullptr;


public:
	Particle();

	//Particle(const Particle& other) {}
	//Particle& operator=(const Particle& other) { return *this; }
	//
	//~Particle() {}

	void Initialize();

	void Update(float deltaTime);
	void Render(LineRenderer& lines);

	void OnCollision(Vector2 otherPos, Vector2 dir);

	Vector2 GetCurrentPos() { return pos; }
	
	float GetSize() { return size; }

	bool collided = false;
};

