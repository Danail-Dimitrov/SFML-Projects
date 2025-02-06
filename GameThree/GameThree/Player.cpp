#include "Player.h"

Player::Player()
{
	this->initVariables();
	this->initTextures();
	this->initSprite();
}

Player::~Player()
{
	delete this->sprite;
}

void Player::initVariables()
{
	this->movementSpeed = 3.f;
	this->attackCooldownMax = 20.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initTextures()
{
	//Load a texture from file
	if (!this->texture.loadFromFile("Textures/ship.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	
	if (!this->bulletTexture.loadFromFile("Textures/bullet.png"))
		std::cout << "ERROR: BULLET TEXTURE VIOLATION";
}


void Player::initSprite()
{
	this->sprite = new sf::Sprite(this->texture);

	this->sprite->setScale({ 0.085f, 0.085f });

	this->sprite->setPosition({ 400.f, 300.f });
}

void Player::updateMovement()
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

Bullet* Player::updateAtack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && 
		(this->attackCooldown >= this->attackCooldownMax) ||
		(this->attackCooldown < 0)) // Preventing a possible overfllow
	{
		this->attackCooldown = 0;

		return new Bullet(
			&this->bulletTexture,
			this->sprite->getPosition().x + this->sprite->getGlobalBounds().size.x / 3.4f,
			this->sprite->getPosition().y,
			0.f,
			-1.f,
			2.f
		);
	}

	this->attackCooldown += 1.f;

	return nullptr;
}

void Player::move(const float x, const float y)
{
	this->sprite->move({ this->movementSpeed * x, this->movementSpeed* y });
}

void Player::update()
{
	this->updateMovement();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(*this->sprite);
}
