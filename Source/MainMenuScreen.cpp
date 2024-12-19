#include "MainMenuScreen.h"
#include "GameplayScreen.h"
#include "BoxCollider2D.h"
#include "GameObject.h"

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
	title.loadFromRenderedText(game->renderer, game->gFont, "SDL2 Game", { 0, 0, 0, 255 });
	play.loadFromRenderedText(game->renderer, game->gFont, "Play", { 0, 0, 0, 255 });
	playButton = GameObject(400, 300);
	button = BoxCollider2D(&playButton, playButton.x, playButton.y, play.getWidth() / 2, play.getHeight() / 2);
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
		if (button.IsClicked(e)) {
			game->ChangeScreen(new GameplayScreen(game));
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
	play.render(game->renderer, playButton.x - play.getWidth() / 4, playButton.y - play.getHeight() / 2, play.getWidth() / 2, play.getHeight() / 2);
	if (button.isCollided) {
		SDL_SetRenderDrawColor(game->renderer, 0, 255, 0, 255);
	}
	else {
		SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);
	}
	SDL_RenderDrawRect(game->renderer, button.boxCollider);

	SDL_RenderPresent(game->renderer);
}

void MainMenuScreen::ChangeStage(GameStage* stage)
{
	if (!stages.empty()) {
		stages.back()->Cleanup();
		stages.pop_back();
	}
	stages.push_back(stage);
}
