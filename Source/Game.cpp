#include "Game.h"

void Game::Init(const char* title, int width, int height, bool fullscreen)
{
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

	if (TTF_Init() == -1) {
		printf("TTF_Init Error: %s\n", TTF_GetError());
		mRunning = false;
	}

	gFont = TTF_OpenFont("Assets/Fonts/JMH Typewriter.ttf", 14);
	if (gFont == NULL) {
		printf("TTF_OpenFont Error: %s\n", TTF_GetError());
		mRunning = false;
	}
}
