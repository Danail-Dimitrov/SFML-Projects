#include "Player.h"

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
	delete this->sprite;
}

void Player::initVariables()
{
	this->movementSpeed = 3.f;
}

void Player::initTexture()
{
	//Load a texture from file
	if (!this->texture.loadFromFile("Textures/ship.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}


void Player::initSprite()
{
	this->sprite = new sf::Sprite(this->texture);

	this->sprite->setScale({ 0.085f, 0.085f });

	this->sprite->setPosition({ 400.f, 300.f });
}

void Player::move(const float x, const float y)
{
	this->sprite->move({ this->movementSpeed * x, this->movementSpeed* y });
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		this->move(-1.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		this->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		this->move(0.f, -1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		this->move(0.f, 1.f);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(*this->sprite);
}
