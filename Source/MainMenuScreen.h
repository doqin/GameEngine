#pragma once
#include "GameObject.h"
#include "BoxCollider2D.h"
#include "GameScreen.h"
#include "Game.h"
#include "Text.h"
class MainMenuScreen : public GameScreen {
	// Inherited via GameScreen
public:
	Game* game;
	Text title;
	Text play;
	GameObject playButton;
	BoxCollider2D button;
	MainMenuScreen(Game* game);
	void Cleanup() override;
	void Init() override;
	void Pause() override;
	void Resume() override;
	void HandleEvents() override;
	void FixedUpdate() override;
	void Update() override;
	void Draw() override;
	void ChangeStage(GameStage* stage) override;
};

