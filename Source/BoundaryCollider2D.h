#pragma once
#include "SDL2/SDL_render.h"
#include <vector>

#include "Point2D.h"
#include "Vector2D.h"

struct GameObject;
class BoxCollider2D;

class BoundaryCollider2D {
public:
    BoundaryCollider2D(int x, int y, Vector2D normal) {
        this->normal = normal;
        this->point.x = x;
        this->point.y = y;
        this->vector.x = normal.y;
        this->vector.y = -normal.x;
    }
    ~BoundaryCollider2D();
    void DrawCollider(SDL_Renderer* gRenderer, int x1, int x2) const;
    Vector2D normal;
    Vector2D vector;
    Point2D point;
};

