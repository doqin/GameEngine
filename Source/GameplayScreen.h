#pragma once
#include "GameScreen.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"
#include "ScreenRepresentation.h"
#include "PlayerController.h"
class GameplayScreen : public GameScreen
{
public:
	Game* game;

	// Player components
	GameObject player;
	Sprite playerSprite;
	PlayerController playerController;
	ScreenRepresentation playerRepresentation;
	BoxCollider2D playerCollider;

	// Camera
	SDL_Rect camera = { 0, 0, 800, 600 };
	GameplayScreen(Game* game);
	// Inherited via GameScreen
	void Cleanup() override;
	void Init() override;
	void Pause() override;
	void Resume() override;
	void HandleEvents() override;
	void FixedUpdate() override;
	void Update() override;
	void Draw() override;
	void ChangeStage(GameStage* stage) override;
	std::vector<ScreenRepresentation*> entities;
	std::vector<PlayerController*> controllers;
private:
	std::vector<GameStage*> stages;
};

