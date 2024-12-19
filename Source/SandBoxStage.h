#pragma once
#include "GameStage.h"
#include "GameplayScreen.h"
class SandBoxStage : public GameStage
{
public:
	GameplayScreen* screen;
	SandBoxStage(GameplayScreen* screen) {
		this->screen = screen;
	}
	// Inherited via GameStage
	void Init() override;
	void Cleanup() override;
	void Pause() override;
	void Resume() override;
	void HandleEvents() override;
	void FixedUpdate() override;
	void Update() override;
	void Draw() override;
private:
};

