#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SwagBalls
{
public:
	SwagBalls(const sf::RenderWindow& window);
	~SwagBalls();

	// Accessors
	const sf::CircleShape& getShape() const { return this->shape; }

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow& window);
};

