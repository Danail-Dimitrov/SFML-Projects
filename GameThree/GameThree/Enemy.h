#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(float x, float y);
	~Enemy();

	void update();
	void render(sf::RenderTarget& target);

	const sf::Vector2f getPosition() const { return this->shape.getGlobalBounds().position; }

	const sf::FloatRect getBounds() const { return this->shape.getGlobalBounds(); }

private:
	sf::CircleShape shape;
	int hp;
	int hpMax;
	int damage;
	int points;
	int type;

	void initVariables();
	void initShape(float x, float y);
};

