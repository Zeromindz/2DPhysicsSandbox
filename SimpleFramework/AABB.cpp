#include "AABB.h"

AABB::AABB(float xMinInit, float xMaxInit, float yMinInit, float yMaxInit) : RigidBody(ShapeType::BOX)
{
}

void AABB::Update(float deltaTime)
{


    RigidBody::Update(deltaTime);
}

void AABB::Render(LineRenderer& lines)
{
    Vector3 color = { 0.0f, 0.5f, 1.0f };

    lines.AddPointToLine(Vector2(xMin, yMin), colour);
    lines.AddPointToLine(Vector2(xMin, yMax), colour);
    lines.AddPointToLine(Vector2(xMax, yMax), colour);
    lines.AddPointToLine(Vector2(xMax, yMin), colour);
    lines.FinishLineLoop();
}

bool AABB::CheckAABBCollision(AABB AABB1, AABB AABB2)
{

    // Exit with no intersection if found separated along an axis
    //if (AABB2.pos.x - AABB2.width < AABB2.pos.x - width || AABB1.min.x > AABB2.max.y)
    //{
    //    return false;
    //}
    //if (AABB1.max.y < AABB2.min.y || AABB1.min.y > AABB2.max.y)
    //{
    //    return false;
    //}
    ////No separating axis found, must be overlap
    return true;
}



