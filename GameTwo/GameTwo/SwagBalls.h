#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum SwagBallTypes { DEFAULT = 0, DAMAGE = 1, HEAL = 2};

class SwagBalls
{
public:
	SwagBalls(const sf::RenderWindow& window, int type);
	~SwagBalls();

	// Accessors
	const sf::CircleShape& getShape() const { return this->shape; }
	const int& getType() const { return this->type; }

	void update();
	void render(sf::RenderTarget& target);

private:
	int type;
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow& window);
};

