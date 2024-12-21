#include "BoxCollider2D.h"
#include "BoundaryCollider2D.h"
#include "GameObject.h"


bool BoxCollider2D::IsClicked(SDL_Event &e)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
	if (mouseX > boxCollider->x && mouseX < boxCollider->x + boxCollider->w && mouseY > boxCollider->y && mouseY < boxCollider->y + boxCollider->h) {
        isCollided = true;
	}
	else {
		isCollided = false;
	}
    if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (e.button.button == SDL_BUTTON_LEFT && isCollided) {
			return true;
		}
    }
    return false;
}

void BoxCollider2D::Update() const {
    boxCollider->x = entity->x - boxCollider->w / 2 - offsetX;
    boxCollider->y = entity->y - boxCollider->h / 2 - offsetY;
}

bool BoxCollider2D::CheckCollision(const BoxCollider2D* collider) const {
    bool isCollided = false;
    isCollided = SDL_HasIntersection(boxCollider, collider->boxCollider);
    if (isCollided) {
        return isCollided;
    }
    return isCollided;
}

bool BoxCollider2D::CheckCollision(const BoundaryCollider2D* boundaryCollider) const {
    int y = boundaryCollider->point.y + boundaryCollider->vector.y * (boxCollider->x - boundaryCollider->point.x) / boundaryCollider->vector.x;
    if (y < boxCollider->y + boxCollider->h) {
        return true;
    }
    return false;
}