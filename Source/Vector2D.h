#pragma once
struct Vector2D {
    float x, y;
    Vector2D() {
        x = 0;
        y = 0;
    }
    Vector2D(const float x, const float y) {
        this->x = x;
        this->y = y;
    }
};