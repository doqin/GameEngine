#pragma once
struct GameObject {
    float x, y;
    GameObject() {
        x = 0;
        y = 0;
    }
    GameObject(const float x, const float y) {
        this->x = x;
        this->y = y;
    }
};

