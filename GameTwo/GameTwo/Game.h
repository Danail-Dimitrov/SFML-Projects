#pragma once
#include <ctime>

#include "Player.h"

class Game
{
public:
	// Constructors and destructors
	Game();
	~Game();

	// Accessors

	// Modifiers

	// Functions
	void update();
	void render();
	const bool isRunning() const;

private:
	// Private variables
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	Player player;

	// Private functions
	// Initialization functions
	// Initializes the variables
	void initVariables();
	// Initializes the window
	void initWindow();
	// Initializes the random seed
	void initRandomSeed();

	// Polling function
	void pollEvents();
};