#pragma once
struct Point2D {
    float x, y;
    Point2D() {
        x = 0;
        y = 0;
    }
    Point2D(const float x, const float y) {
        this->x = x;
        this->y = y;
    }
};