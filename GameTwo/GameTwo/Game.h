#pragma once
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

private:
	// Private variables
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;

	// Private functions
	// Initialization functions
	// Initializes the variables
	void initVariables();
	// Initializes the window
	void initWindow();
	// Initializes the random seed
	void initRandomSeed();
};