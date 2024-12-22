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
	for (auto entity : entities) {
		entity->entitySprite->free();
	}
	controllers.clear();
	entities.clear();
	boxColliders.clear();
	boundaryColliders.clear();
}

void GameplayScreen::Init()
{
	// Player
	player = GameObject(200, 150);
	// Player sprite
	playerSprite.loadFromFile(game->renderer, "Assets/Textures/KakoIdle.png");
	// Player representation
	playerRepresentation = ScreenRepresentation(&player, &playerSprite);
	entities.push_back(&playerRepresentation);
	// Player collider
	playerCollider = BoxCollider2D(&player, player.x, player.y, 20, 139, 0, -10);
	boxColliders.push_back(&playerCollider);
	// PLayer rigidbody
	playerRigidBody = RigidBody2D(&player, &playerCollider, 0.8f);
	rigidBodies.push_back(&playerRigidBody);
	// Player controller
	playerController = PlayerController(&playerRepresentation, &playerRigidBody, &playerCollider, 10, 15);
	controllers.push_back(&playerController);

	// Boundary colliders
    boundaryColliders.push_back(new BoundaryCollider2D(350, 500, Vector2D(0, 1)));

	// Change stage
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
