#pragma once
#include <ctime>
#include <vector>

#include "Player.h"
#include "SwagBalls.h"

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

	std::vector<SwagBalls> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

	// Private functions
	// Initialization functions
	// Initializes the variables
	void initVariables();
	// Initializes the window
	void initWindow();
	// Initializes the random seed
	void initRandomSeed();

	// Enemies
	// Spawns enemies
	void spawnSwagBalls();

	// Rendering
	// Renders the enemies
	void renderSwagBalls(sf::RenderTarget& target);

	// Polling function
	void pollEvents();

	// Update functions
	void updateCollision();
};