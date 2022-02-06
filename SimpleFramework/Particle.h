#pragma once

#include "glm.hpp"
#include "LineRenderer.h"
#include "Utilities.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;


struct Particle
{
private:
	
	
	Vector2 pos = { GetRandomFloat(-10, 10), GetRandomFloat(-10, 10) };
	Vector2 vel = { 0, 0 };
	Vector2 acc = { 0, 0 };
	Vector3 colour = { 1, 0.2f, 0.2f };
	float size = 0.2f;

	LineRenderer* lines;


public:
	Particle() {}
	Particle(LineRenderer* lines);

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

