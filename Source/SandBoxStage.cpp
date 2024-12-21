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
		for (auto controller : screen->controllers) {
			controller->HandleEvents(e);
		}
	}
}

void SandBoxStage::FixedUpdate()
{
	for (auto controller : screen->controllers) {
		controller->Update(screen->boundaryColliders, screen->boxColliders);
	}
}

void SandBoxStage::Update()
{
}

void SandBoxStage::Draw()
{
	SDL_SetRenderDrawColor(screen->game->renderer, 255, 255, 255, 255);
	SDL_RenderClear(screen->game->renderer);
	SDL_SetRenderDrawColor(screen->game->renderer, 255, 0, 0, 255);
	for (auto collider : screen->boxColliders) {
		SDL_RenderDrawRect(screen->game->renderer, collider->boxCollider);
	}
	for (auto boundaryCollider : screen->boundaryColliders) {
		boundaryCollider->DrawCollider(screen->game->renderer, 0, 800);
	}
	for (auto entity : screen->entities) {
		entity->entitySprite->render(screen->game->renderer, entity->entity->x, entity->entity->y);
	}
	SDL_RenderPresent(screen->game->renderer);
}
