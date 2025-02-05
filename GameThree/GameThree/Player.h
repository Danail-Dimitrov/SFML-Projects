#pragma once

#include "Bullet.h"

class Player
{
public:
	Player();
	~Player();

	void update();
	Bullet* updateAtack();

	void render(sf::RenderTarget& target);

	const sf::Vector2f getPosition() const { return this->sprite->getPosition(); }

private:
	sf::Sprite* sprite;
	sf::Texture texture;
	sf::Texture bulletTexture;

	float movementSpeed;
	float attackCooldown;
	float attackCooldownMax;

	void initVariables();
	void initTextures();
	void initSprite();

	void updateMovement();
	void move(const float x, const float y);
};

