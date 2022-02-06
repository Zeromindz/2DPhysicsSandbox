#pragma once

#include "LineRenderer.h"
#include "Utilities.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class Obstacle
{
private:
	Vector2 pos = { 0, 0 };

	float width = 1.0f;
	float height = 1.0f;

	Vector3 colour = { 1, 1, 1 };

	LineRenderer* lines;

public:

	Obstacle() {}
	Obstacle(LineRenderer* renderer);

	void Update(float deltaTime);
	void Render(LineRenderer& lines);

	void Initialize();


};

