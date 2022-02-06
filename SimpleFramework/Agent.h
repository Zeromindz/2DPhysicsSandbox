#pragma once
#include "LineRenderer.h"
#include "GameBase.h"
#include "GLFWCallbacks.h"
#include "Maths.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class Agent
{
public:
	static Agent& getInstance()
	{
		static Agent instance; // Guaranteed to be destroyed.
		return instance;	// Instantiated on first use.
	}

private:
	// Physics
	Vector2 pos = { 0, 0 };
	Vector2 vel = { 0, 0 };
	Vector2 acc = { 0, 0 };

	// GFX
	Vector3 colour = { 0.3f, 0.3f, 1 };
	float size = 6.0f;

	std::vector<Vector2> impactPoints;

	LineRenderer* lines;

public:
	Agent() {}
	Agent(LineRenderer* renderer);

	void Update(float deltaTime);
	void Render(LineRenderer& lines);
	

	void Initialize();
	void OnCollision(Vector2 otherPos);

	Vector2 GetCurrentPos() { return pos; }
	float GetSize() { return size; }
	
	Vector2 commandPos = { 0, 0 };
	bool commanded;
};

