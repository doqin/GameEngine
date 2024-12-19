#include "SandBoxStage.h"
#include <SDL2/SDL_events.h>

void SandBoxStage::Init()
{
}

void SandBoxStage::Cleanup()
{
}

void SandBoxStage::Pause()
{
}

void SandBoxStage::Resume()
{
}

void SandBoxStage::HandleEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			screen->game->Quit();
		}
	}
}

void SandBoxStage::FixedUpdate()
{
}

void SandBoxStage::Update()
{
}

void SandBoxStage::Draw()
{
	SDL_SetRenderDrawColor(screen->game->renderer, 255, 255, 255, 255);
	SDL_RenderClear(screen->game->renderer);
	for (auto entity : screen->entities) {
		entity->entitySprite->render(screen->game->renderer, entity->entity->x, entity->entity->y);
	}
	SDL_RenderPresent(screen->game->renderer);
}
