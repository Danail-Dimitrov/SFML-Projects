#pragma once
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void update();

	void render(sf::RenderTarget& target);

private:
	sf::Sprite* sprite;
	sf::Texture texture;

	float movementSpeed;

	void initVariables();
	void initTexture();
	void initSprite();

	void move(const float x, const float y);
};

