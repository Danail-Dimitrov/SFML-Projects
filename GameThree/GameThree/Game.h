#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow* window;

	void initWindow();

	void update();

	void render();
};

