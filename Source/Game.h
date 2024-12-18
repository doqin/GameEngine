#pragma once
#include "GameEngine.h"
#include "SDL2/SDL_ttf.h"
class Game : public GameEngine {
public:
	TTF_Font* gFont;
	Game() = default;
	~Game() = default;
	void Init(const char* title, int width, int height, bool fullscreen) override;
};

