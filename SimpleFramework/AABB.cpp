#include "AABB.h"

AABB::AABB()
{
    width = 1.5f;
    height = 1.5f;
    
    //min = { -width, -height };
    //max = { width, height };
}

AABB::AABB(Vector2 position, float w, float h)
{
    pos = position;

    width = w;
    height = h;
}

void AABB::Update(float deltaTime)
{
    PhysicsObject::Update(deltaTime);
}

void AABB::Render(LineRenderer& lines)
{
    Vector2 a = { pos.x - width / 2.0f, pos.y + height / 2.0f}; // Top left
    Vector2 b = { pos.x + width / 2.0f, pos.y + height / 2.0f }; // Top right
    Vector2 c = { pos.x + width / 2.0f, pos.y - height / 2.0f }; // Bottom right
    Vector2 d = { pos.x - width / 2.0f, pos.y - height / 2.0f }; // Bottom left
    
    Vector3 color = { 0.0f, 0.5f, 1.0f };

    lines.DrawLineSegment(a, b, color);
    lines.DrawLineSegment(b, c, color);
    lines.DrawLineSegment(c, d, color);
    lines.DrawLineSegment(d, a, color);
}

bool AABB::CheckAABBCollision(AABB AABB1, AABB AABB2)
{
    Vector2 a = { pos.x - width / 2.0f, pos.y + height / 2.0f }; // Top left
    Vector2 b = { pos.x + width / 2.0f, pos.y + height / 2.0f }; // Top right
    Vector2 c = { pos.x + width / 2.0f, pos.y - height / 2.0f }; // Bottom right
    Vector2 d = { pos.x - width / 2.0f, pos.y - height / 2.0f }; // Bottom left

    // Exit with no intersection if found separated along an axis
    // X axis
    bool collisionX = AABB1.pos.x + AABB1.width / 2 >= AABB2.pos.x && AABB2.pos.x + AABB2.width / 2 >= AABB1.pos.x;

    bool collisionY = AABB1.pos.y + AABB1.height / 2 >= AABB2.pos.y && AABB2.pos.y + AABB2.height / 2 >= AABB1.pos.y;
    return collisionX && collisionY;

    //if (AABB2.pos.x - AABB2.width < AABB2.pos.x - width || AABB1.min.x > AABB2.max.y)
    //{
    //    return false;
    //}
    //if (AABB1.max.y < AABB2.min.y || AABB1.min.y > AABB2.max.y)
    //{
    //    return false;
    //}
    ////No separating axis found, must be overlap
    //return true;
}



