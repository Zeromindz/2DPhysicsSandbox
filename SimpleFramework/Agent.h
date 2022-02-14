#pragma once
#include "LineRenderer.h"
#include "GameBase.h"
#include "GLFWCallbacks.h"
#include "Maths.h"
#include "RigidBody.h"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;

class Agent : public RigidBody
{

public:
	Agent();

	void Update(float deltaTime);
	void Render(LineRenderer& lines);
	

	void Initialize();
	void OnCollision(Vector2 otherPos);

	Vector2 GetCurrentPos() { return pos; }
	float GetSize() { return size; }
	
	Vector2 commandPos = { 0, 0 };
	bool commanded = false;

private:
	// Physics
	Vector2 pos;
	Vector2 vel;
	Vector2 acc;

	// GFX
	Vector3 colour = { 0.3f, 0.3f, 1 };
	float size = 1.5f;

	std::vector<Vector2> impactPoints;

};

