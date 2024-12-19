#pragma once
#include <SDL2/SDL_events.h>
#include "BoundaryCollider2D.h"
#include "GameObject.h"
#include "RigidBody2D.h"

class PlayerController {
public:
    PlayerController() {
		player = nullptr;
		rigidBody = nullptr;
		boxCollider = nullptr;
		circleCollider = nullptr;
		speed = 0;
		xDir = 0;
		jumpForce = 0;
    }
    PlayerController(GameObject* entity, RigidBody2D* rigidBody = nullptr, 
        BoxCollider2D* boxCollider = nullptr, const float speed = 0, 
        const float jumpForce = -10) {
        player = entity;
        this->speed = speed;
        if (rigidBody) {
            this->rigidBody = rigidBody;
        }
        if (boxCollider) {
            this->boxCollider = boxCollider;
        }
        if (jumpForce != 0) {
            this->jumpForce = jumpForce;
        }
    }

    PlayerController(GameObject* entity, RigidBody2D* rigidBody = nullptr, 
        CircleCollider2D* circleCollider = nullptr, 
        const float speed = 0, const float jumpForce = -10) : boxCollider(nullptr), xDir(0) {
        player = entity;
        this->speed = speed;
        if (rigidBody) {
            this->rigidBody = rigidBody;
        }
        if (circleCollider) {
            this->circleCollider = circleCollider;
        }
        if (jumpForce != 0) {
            this->jumpForce = jumpForce;
        }
    }

    void HandleEvents(const SDL_Event& e);
    void HandleEvents(const SDL_Event& e, RigidBody2D* rigidBody);
    void Update(const std::vector<BoundaryCollider2D*>& boundaryColliders, std::vector<BoxCollider2D*>& boxColliders);
    void RollBack(float x, float width);
    RigidBody2D* rigidBody;
private:
    GameObject* player;
    BoxCollider2D* boxCollider;
    CircleCollider2D* circleCollider;
    float speed;
    float xDir;
    float jumpForce;
};

