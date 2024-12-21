#include "GameplayScreen.h"
#include "SandBoxStage.h"
#include "Vector2D.h"
#include "BoundaryCollider2D.h"
GameplayScreen::GameplayScreen(Game* game) 
{
	this->game = game;
}

void GameplayScreen::Cleanup()
{
	while (!stages.empty()) {
		stages.back()->Cleanup();
		stages.pop_back();
	}
	playerSprite.free();
	for (auto entity : entities) {
		delete entity;
	}
	entities.clear();
	for (auto controller : controllers) {
		delete controller;
	}
	controllers.clear();
	for (auto collider : boxColliders) {
		delete collider;
	}
	boxColliders.clear();
}

void GameplayScreen::Init()
{
	player = GameObject(200, 150);
	playerSprite.loadFromFile(game->renderer, "Assets/Textures/KakoIdle.png");
	entities.push_back(new ScreenRepresentation(&player, &playerSprite));
	playerCollider = BoxCollider2D(&player, player.x, player.y, playerSprite.getWidth(), playerSprite.getHeight());
	playerController = PlayerController(&player, nullptr, &playerCollider, 5, 10);
	controllers.push_back(&playerController);
	boxColliders.push_back(&playerCollider);
    boundaryColliders.push_back(new BoundaryCollider2D(350, 500, Vector2D(0, 1)));
	this->ChangeStage(new SandBoxStage(this));
}

void GameplayScreen::Pause()
{
	stages.back()->Pause();
}

void GameplayScreen::Resume()
{
	stages.back()->Resume();
}

void GameplayScreen::HandleEvents()
{
	stages.back()->HandleEvents();
}

void GameplayScreen::FixedUpdate()
{
	stages.back()->FixedUpdate();
}

void GameplayScreen::Update()
{
	stages.back()->Update();
}

void GameplayScreen::Draw()
{
	stages.back()->Draw();
}

void GameplayScreen::ChangeStage(GameStage* stage)
{
	if (!stages.empty()) {
		stages.back()->Cleanup();
		stages.pop_back();
	}
	stages.push_back(stage);
	stages.back()->Init();

}
