#pragma once
#include "BoxCollider2D.h"


class CircleCollider2D {
public:
    int x, y;
    int radius;
    CircleCollider2D() : entity(nullptr) {
        x = 0;
        y = 0;
        radius = 0;
    }

    CircleCollider2D(GameObject* entity, const int x, const int y, const int radius) {
        this->entity = entity;
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    ~CircleCollider2D() = default;

    void Update();

    bool CheckCollision(const CircleCollider2D* collider) const;

    bool CheckCollision(const BoxCollider2D* collider) const;

    bool CheckCollision(const BoundaryCollider2D* collider) const;
private:
    GameObject* entity;
};

