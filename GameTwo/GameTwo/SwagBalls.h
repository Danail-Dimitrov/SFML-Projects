#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// NUMOFTYPES is the number of types of swag balls. I don't like this appraoch, but it's the best I can do for now.
// But for now it will do
enum SwagBallTypes { DEFAULT = 0, DAMAGE = 1, HEAL = 2, NUMOFTYPES };

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

