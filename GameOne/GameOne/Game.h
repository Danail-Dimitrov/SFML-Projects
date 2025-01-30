#pragma once
#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Class that acts as the game engine
// Wrapper class for the game loop
class Game
{
public:
	// Constructors
	Game();

	// Destructors
	virtual ~Game();

	// Functions
	// Update the game. Not the drawwing. This is the behind the scenes stuff
	// As an analogy if I close my eyes I am not rendering but I am alive and move around (updating)
	void update();
	// Render the game. This is the drawing part
	void render();

	// Accessors
	// Returns if the window is open
	const bool getWindowIsOpen() const;

private:
	// Variables
	// I want to be able to delete the window when I want. That is why we need the pointer
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	std::string windowName;

	// Mouse positions
	sf::Vector2i mousePositionWindow;

	// Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned int maxEnemies;

	// Game objects
	std::vector<sf::RectangleShape> enemies;
	// Usualy we will use textures. For this game tho we use shapes
	sf::RectangleShape enemy;

	// Private functions
	// Seeds the random number generator
	void initializeRandomEngine();
	// Initializes the variables
	void initializeVariables();
	// Initializes the window
	void initializeWindow();
	// Initializes the enemues
	void initializeEnemies();
	// Poll events. Did something happen?
	void pollEvents();
	// Update mouse position
	void updateMousePositions();
	// Spawns an enemy
	void spawnEnemy();
	// Update enemies
	void updateEnemies();
	// Render enemies
	void renderEnemies();
};

