#include "Game.h"

void main(int argc, void** argv[]) {
	// program entry point
	Game game; // create the game object
	while (!game.GetWindow()->IsDone()) {
		// game loop
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock(); // restart the clock
	}
}