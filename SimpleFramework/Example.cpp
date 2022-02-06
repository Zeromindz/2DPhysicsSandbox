#include "Example.h"
#include "Particle.h"

Example::Example() : GameBase()
{
	//Your initialisation code goes here!
	agent = Agent::getInstance();

	for (int i = 0; i < particleCount; i++)
	{
		particles[i] = Particle(&lines);
	}

	for (int i = 0; i < obstacleCount; i++)
	{
		obstacle[i] = Obstacle(&lines);
	}
}

void Example::Update()
{
	agent.Update(deltaTime);

	for (int p = 0; p < particleCount; p++)
	{
		particles[p].Update(deltaTime);
	}
	
	for (int o = 0; o < obstacleCount; o++)
	{
		obstacle[o].Update(deltaTime);
	}

	CheckCollisions();

	//This call ensures that your mouse position and aspect ratio are maintained as correct.
	GameBase::Update();

}



void Example::Render()
{
	//Your drawing code goes here!
	agent.Render(lines);

	for (int i = 0; i < particleCount; i++)
	{
		particles[i].Render(lines);
	}

	for (int o = 0; o < obstacleCount; o++)
	{
		obstacle[o].Render(lines);
	}

	//Example code that draws a coloured circle at the mouse position, whose colour depends on which buttons are down.
	/*
	if (leftButtonDown)
	{
		lines.DrawCircle(cursorPos, 0.2f, { 1, 0, 0 });
	}
	else if (rightButtonDown)
	{
		lines.DrawCircle(cursorPos, 0.2f, { 0, 1, 0 });
	}
	else
	{
		lines.DrawCircle(cursorPos, 0.2f, { 0, 0, 1 });
	}
	*/

	//This call puts all the lines you've set up on screen - don't delete it or things won't work.
	GameBase::Render();
}

void Example::OnMouseClick(int mouseButton)
{
	agent.commanded = true;
	agent.commandPos = cursorPos;
}

void Example::CheckCollisions()
{
	for (auto particle : particles)
	{
		Vector2 particlePos = particle.GetCurrentPos();
		Vector2 agentPos = agent.GetCurrentPos();

		Vector2 dist = particlePos - agentPos;
		float mag = (float)glm::sqrt((dist.x * dist.x) + (dist.y * dist.y));
		float radialSum = (particle.GetSize() + agent.GetSize());

		if (mag < radialSum && !particle.collided)
		{
			Vector2 dir = { dist.x /= mag,  dist.y /= mag };
			agent.OnCollision(particlePos);
			particle.OnCollision(agentPos, dir);

		}
	}
}

void Example::InitializeLevel()
{

}