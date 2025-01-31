#include <iostream>
#include "Game.h"

int main()
{
	//Initializaing game object;
	Game game;

	// Game loop
	// Every game frame has three stages: Evvent polling, Update and Render
	// While the window is open and the game is not over, the game will run
	while (game.getWindowIsOpen() && !game.getGameOver())
	{
		// Update
		game.update();

		// Render 
		game.render();
	}

	// End of the game
	return 0;
}