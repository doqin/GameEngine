#pragma once
#include "GameEngine.h"
class Game : public GameEngine {
public:
	Game() = default;
	~Game() = default;
	void Init(const char* title, int width, int height, bool fullscreen) override;
};

