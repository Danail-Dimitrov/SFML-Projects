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

	// Returns if the game is over
	const bool getGameOver() const;

private:
	// Variables
	// I want to be able to delete the window when I want. That is why we need the pointer
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	std::string windowName;

	// Resources
	sf::Font font;

	// Text
	sf::Text* uiText;

	// Mouse positions
	sf::Vector2i mousePositionWindow; // Two integers
	sf::Vector2f mousePositionView; // Two floats
	bool mouseHeld;

	// Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned int maxEnemies;
	int health;
	bool gameOver;

	// Game objects
	std::vector<sf::RectangleShape> enemies;
	// Usualy we will use textures. For this game tho we use shapes
	sf::RectangleShape enemy;

	// Private functions
	// Initializers
	// Seeds the random number generator
	void initializeRandomEngine();
	// Initializes the variables
	void initializeVariables();
	// Initializes the window
	void initializeWindow();
	// Initializes the enemues
	void initializeEnemy();
	// Initializes fonts
	void initializeFonts();
	// Initializes text
	void initializeText();

	// Poll events. Did something happen?
	void pollEvents();

	// Mouse
	// Update mouse position
	void updateMousePositions();
	
	// Enemies
	// Spawns an enemy
	void spawnEnemy();
	// Update enemies
	void updateEnemies();
	// Updates enemy spawn timer
	void updateEnemySpawnTimer();
	// Handles enemy movement
	void moveEnemies();
	// Handles player atacking enemies
	void attackEnemies();

	// User stats
	// Update points
	void updatePoints(int amount);
	// Update health
	void updateHealth(int amount);

	// Text
	// Updates the text
	void updateText();

	// Render enemies
	void renderEnemies(sf::RenderTarget& target);
	// Render text
	// Renders the text in the given target. 
	// Sometimes I dont want the target to be the window.
	// I want to render the text in a view for example
	void renderText(sf::RenderTarget& target);
};

