#include <iostream>
#include "Game.h"
#include "MainMenuScreen.h"

int main(int argc, char* argv[]) {
	Game game;
	game.Init("SDL2Game", 800, 600, false);
	game.ChangeScreen(new MainMenuScreen(&game));
	float timer = 0;
	Uint32 NOW = SDL_GetTicks();
	Uint32 LAST = 0;
	while (game.Running()) {
		const float fixedStep = 0.02f;
		game.HandleEvents();
		while (timer >= fixedStep) {
			game.FixedUpdate();
			timer -= fixedStep;
		}
		game.Update();
		game.Draw();
		LAST = NOW;
		NOW = SDL_GetTicks();
		float deltaTime = (float)(NOW - LAST) / 1000.0f;
		timer += deltaTime;
	}
	game.Cleanup();
	return 0;
}