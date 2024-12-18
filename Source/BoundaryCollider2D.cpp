#include "BoundaryCollider2D.h"
#include "Vector2D.h"
#include "Point2D.h"
#include "SDL2/SDL_render.h"

BoundaryCollider2D::~BoundaryCollider2D() {
    delete& normal;
    delete& vector;
    delete& point;
}

void BoundaryCollider2D::DrawCollider(SDL_Renderer* gRenderer, const int x1, const int x2) const {
    for (int i = x1; i <= x2; i++) {
        SDL_RenderDrawPoint(gRenderer, i, point.y + vector.y * (i - point.x) / vector.x);
    }
}