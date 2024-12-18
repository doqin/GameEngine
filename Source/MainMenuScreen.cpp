#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen(Game* game)
{
	this->game = game;
}

void MainMenuScreen::Cleanup()
{
	title.free();
	play.free();
}

void MainMenuScreen::Init()
{
	title.loadFromRenderedText(game->renderer, game->gFont, "SDL2Game", { 0, 0, 0, 255 });
	play.loadFromRenderedText(game->renderer, game->gFont, "Play", { 0, 0, 0, 255 });
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

	title.render(game->renderer, 400 - title.getWidth() / 2, 100);
	play.render(game->renderer, 400 - play.getWidth() / 2, 300);

	SDL_RenderPresent(game->renderer);
}

void MainMenuScreen::ChangeStage(GameStage* stage)
{
}
