#pragma once
#include "GameScreen.h"
#include "Game.h"
#include "Text.h"
class MainMenuScreen : public GameScreen {
	// Inherited via GameScreen
public:
	Game* game;
	Text title;
	Text play;
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

