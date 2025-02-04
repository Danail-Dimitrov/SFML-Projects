#pragma once
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(sf::Texture* texture, float x, float y, float dirX, float dirY, float movementSpeed);
	Bullet();
	~Bullet();

	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);

private:
	sf::Sprite* sprite;
	sf::Vector2f direction;
	float movementSpeed;

	void initSptite(sf::Texture* texture, float x, float y);
};

