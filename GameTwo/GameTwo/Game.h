#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

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
	// Game variables
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;

	// Player
	Player player;
	int points;

	// Enemies
	std::vector<SwagBalls> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

	// Text
	sf::Font font;
	sf::Text* uiText;
	sf::Text* endGameText;

	// Private functions
	// Initialization functions
	// Initializes the variables
	void initVariables();
	// Initializes the window
	void initWindow();
	// Initializes the random seed
	void initRandomSeed();
	// Initializes the font
	void initFont();
	// Initializes the text
	void initText();
	// Initializes the end game text
	void initEndGameText();
	// Randomizes the ball type
	const int randomizeBallType() const;

	// Game state
	bool isEndGame() const;

	// Enemies
	// Spawns enemies
	void spawnSwagBalls();

	// Rendering
	// Renders the enemies
	void renderSwagBalls(sf::RenderTarget& target);
	// Renders the text
	void renderText(sf::RenderTarget& target);

	// Polling function
	void pollEvents();

	// Update functions
	void updateCollision();
	void updateText();
	// If the player goes below 1 hp the game ends
	void updateGameState();
};