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
	for (auto collider : screen->boxColliders) {
		collider->Update();
	}
}

void SandBoxStage::Update()
{
}

void SandBoxStage::Draw()
{
	// Clear screen
	SDL_SetRenderDrawColor(screen->game->renderer, 255, 255, 255, 255);
	SDL_RenderClear(screen->game->renderer);


	SDL_SetRenderDrawColor(screen->game->renderer, 255, 0, 0, 255);
	// Draw colliders
	for (auto collider : screen->boxColliders) {
		SDL_RenderDrawRect(screen->game->renderer, collider->boxCollider);
	}

	// Draw boundaries
	for (auto boundaryCollider : screen->boundaryColliders) {
		boundaryCollider->DrawCollider(screen->game->renderer, 0, 800);
	}

	// Draw entities
	for (auto entity : screen->entities) {
		entity->entitySprite->render(screen->game->renderer, entity->entity->x - entity->entitySprite->getWidth() / 2, entity->entity->y - entity->entitySprite->getHeight() / 2, nullptr, nullptr, 0, nullptr, entity->flipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
	}

	// Update screen
	SDL_RenderPresent(screen->game->renderer);
}
