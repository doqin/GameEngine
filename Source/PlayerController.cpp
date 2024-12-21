#include "PlayerController.h"
#include <iostream>
#include "BoundaryCollider2D.h"
#include "BoxCollider2D.h"
#include "GameObject.h"

void PlayerController::HandleEvents(const SDL_Event& e) {
    switch (e.type) {
    case SDL_KEYDOWN:
        if (e.key.repeat == 0)
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                xDir -= 1 * speed;
                break;
            case SDLK_RIGHT:
                xDir += 1 * speed;
                break;
            default:
                break;
            }
        break;
    case SDL_KEYUP:
        if (e.key.repeat == 0)
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                xDir += 1 * speed;
                break;
            case SDLK_RIGHT:
                xDir -= 1 * speed;
                break;
            default:
                break;
            }
    }
}

void PlayerController::HandleEvents(const SDL_Event& e, RigidBody2D* rigidBody) {
    switch (e.type) {
    case SDL_KEYDOWN:
        if (e.key.repeat == 0)
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                xDir -= 1 * speed;
                break;
            case SDLK_RIGHT:
                xDir += 1 * speed;
                break;
            default:
                break;
            }
        switch (e.key.keysym.sym) {
        case SDLK_UP:
            rigidBody->jumpForce = -jumpForce;
            break;
        default:
            break;
        }
        break;
    case SDL_KEYUP:
        if (e.key.repeat == 0)
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                xDir += 1 * speed;
                break;
            case SDLK_RIGHT:
                xDir -= 1 * speed;
                break;
            default:
                break;
            }
    }
}

void PlayerController::Update(const std::vector<BoundaryCollider2D*>& boundaryColliders, std::vector<BoxCollider2D*>& boxColliders) {
    player->x += xDir;
    if (boxCollider) {
        boxCollider->Update();
        for (const BoxCollider2D* collider : boxColliders) {
            if (boxCollider->CheckCollision(collider)) {
                this->RollBack(collider->boxCollider->x, collider->boxCollider->w);
                boxCollider->Update();
            }
        }
    }
    else if (circleCollider) {
        circleCollider->Update();
        for (const BoxCollider2D* collider : boxColliders) {
            if (circleCollider->CheckCollision(collider)) {
                this->RollBack(collider->entity->x, collider->boxCollider->w);
                circleCollider->Update();
            }
        }
    }
}

void PlayerController::RollBack(float x, float width) {
    if (xDir > 0)
        player->x = x - (width / 2.0 + circleCollider->radius);
    else if (xDir < 0)
        player->x = x + (width / 2.0 + circleCollider->radius);
}