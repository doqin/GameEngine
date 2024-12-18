#include "GameEngine.h"
#include "GameScreen.h"

void GameEngine::Init(const char* title, int width, int height, bool fullscreen) {
	mWidth = width;
	mHeight = height;
	mFullscreen = fullscreen;
	mRunning = true;
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		screen = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth, mHeight, flags);
		renderer = SDL_CreateRenderer(screen, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		else {
			printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
			mRunning = false;
		}
	}
	else {
		printf("SDL_Init Error: %s\n", SDL_GetError());
		mRunning = false;
	}
}

void GameEngine::Cleanup() {
	while (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	SDL_Quit();
}

void GameEngine::ChangeScreen(GameScreen* state) {
	if (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}
	screens.push_back(state);
	screens.back()->Init();
}

void GameEngine::PushScreen(GameScreen* state) {
	if (!screens.empty()) {
		screens.back()->Pause();
	}
	screens.push_back(state);
	screens.back()->Init();
}

void GameEngine::PopScreen() {
	if (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}
	if (!screens.empty()) {
		screens.back()->Resume();
	}
}

void GameEngine::HandleEvents() {
	screens.back()->HandleEvents();
}

void GameEngine::FixedUpdate() {
	screens.back()->FixedUpdate();
}

void GameEngine::Update() {
	screens.back()->Update();
}

void GameEngine::Draw() {
	screens.back()->Draw();
}
