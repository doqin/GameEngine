#include "CircleCollider2D.h"
#include "GameObject.h"

void CircleCollider2D::Update() {
    this->x = entity->x;
    this->y = entity->y;
}

bool CircleCollider2D::CheckCollision(const CircleCollider2D* collider) const {
    return (x - collider->x) * (x - collider->x) + (y - collider->y) * (y - collider->y) < (radius + collider->radius) * (radius + collider->radius);
}

bool CircleCollider2D::CheckCollision(const BoxCollider2D* collider) const {
    const int dx = std::max(collider->boxCollider->x, std::min(this->x, collider->boxCollider->x + collider->boxCollider->w));
    const int dy = std::max(collider->boxCollider->y, std::min(this->y, collider->boxCollider->y + collider->boxCollider->h));
    return (dx - x) * (dx - x) + (dy - y) * (dy - y) < radius * radius;
}

bool CircleCollider2D::CheckCollision(const BoundaryCollider2D* collider) const {
    if (const float y = static_cast<float>(collider->point.y) + collider->vector.y * (x - collider->point.x) / static_cast<float>(collider->vector.x);
        y < y + radius) {
        return true;
    }
    return false;
}