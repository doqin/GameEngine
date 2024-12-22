#pragma once
#include <vector>
#include "BoundaryCollider2D.h"
#include "CircleCollider2D.h"
#include "GameObject.h"

class BoxCollider2D;

class RigidBody2D {
public:
    BoxCollider2D* boxCollider;
    CircleCollider2D* circleCollider;
    RigidBody2D() = default;
    RigidBody2D(GameObject* entity, BoxCollider2D* boxCollider = nullptr, const float mass = 1) : circleCollider(
        nullptr), jumpForce(0) {
        this->entity = entity;
        if (boxCollider != nullptr) {
            this->boxCollider = boxCollider;
        }
        isGrounded = false;
        this->mass = mass;
        velocity = 0;
        acceleration = mass;
    }

    RigidBody2D(GameObject* entity, CircleCollider2D* circleCollider = nullptr, const float mass = 1) : boxCollider(
        nullptr), jumpForce(0) {
        this->entity = entity;
        if (circleCollider != nullptr) {
            this->circleCollider = circleCollider;
        }
        isGrounded = false;
        this->mass = mass;
        velocity = 0;
        acceleration = mass;
    }

    void Update(const std::vector<BoundaryCollider2D*>& boundaryColliders,
        const std::vector<BoxCollider2D*>& boxColliders);
    void RollBack(float y, float height);

    float jumpForce;
    bool isGrounded;
private:
    GameObject* entity;
    float velocity;
    float mass;
    float acceleration;
};

