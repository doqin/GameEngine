#pragma once
#include "SDL2/SDL_rect.h"
#include <vector>
#include "BoundaryCollider2D.h"
#include "SDL2/SDL_events.h"


struct GameObject;

class BoxCollider2D {
public:
    GameObject* entity;
    SDL_Rect* boxCollider;
    BoxCollider2D() {
		entity = nullptr;
		boxCollider = nullptr;
		isCollided = false;
    }
    BoxCollider2D(GameObject* entity, const int x, const int y, const int w, const int h) {
        this->entity = entity;
        boxCollider = new SDL_Rect(x - w / 2, y - w / 2, w, h);
        isCollided = false;
    }
    BoxCollider2D(GameObject* entity, SDL_Rect* boxCollider) {
        this->entity = entity;
        this->boxCollider = boxCollider;
		isCollided = false;
    }
    ~BoxCollider2D() = default;

	bool IsClicked(SDL_Event &e);
    void Update() const;
    bool CheckCollision(const BoxCollider2D* collider) const;
    bool CheckCollision(const BoundaryCollider2D* boundaryCollider) const;
    bool isCollided;
};

