#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen(Game* game)
{
	this->game = game;
}

void MainMenuScreen::Init()
{
}

void MainMenuScreen::Pause()
{
}

void MainMenuScreen::Resume()
{
}

void MainMenuScreen::HandleEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			game->Quit();
		}
	}
}

void MainMenuScreen::FixedUpdate()
{
}

void MainMenuScreen::Update()
{
}

void MainMenuScreen::Draw()
{
	SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
	SDL_RenderClear(game->renderer);
	SDL_RenderPresent(game->renderer);
}

void MainMenuScreen::ChangeStage(GameStage* stage)
{
}
