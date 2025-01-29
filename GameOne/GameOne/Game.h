#pragma once
#include <iostream>

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
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	std::string windowName;

	// Game objects
	// Usualy we will use textures. For this game tho we use shapes
	sf::RectangleShape enemy;

	// Private functions
	// Initializes the variables
	void initializeVariables();
	// Initializes the window
	void initializeWindow();
	// Initializes the enemues
	void initializeEnemies();
	// Poll events. Did something happen?
	void pollEvents();
};

