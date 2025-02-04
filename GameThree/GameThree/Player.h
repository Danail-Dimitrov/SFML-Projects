#pragma once

#include "Bullet.h"

class Player
{
public:
	Player();
	~Player();

	void update();
	void render(sf::RenderTarget& target);

	const sf::Vector2f getPosition() const { return this->sprite->getPosition(); }

private:
	sf::Sprite* sprite;
	sf::Texture texture;

	float movementSpeed;

	void initVariables();
	void initTexture();
	void initSprite();

	void move(const float x, const float y);
};

