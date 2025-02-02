#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SwagBalls
{
public:
	SwagBalls(const sf::RenderWindow& window);
	~SwagBalls();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow& window);
};

