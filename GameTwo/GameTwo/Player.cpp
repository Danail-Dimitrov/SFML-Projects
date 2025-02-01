#include "Player.h"

// Constructors and destructors
Player::Player(float x, float y)
{
	this->initVariables();
	this->initShape();
	this->shape.setPosition({ x, y });
}

Player::~Player()
{
}

// Functions
void Player::update(sf::RenderTarget* target)
{
	// Window bounds

	// Keyboard input
	this->updateInput();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
		this->shape.move({-this->movementSpeed, 0.f});
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
		this->shape.move({ this->movementSpeed, 0.f });
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
		this->shape.move({ 0.f, -this->movementSpeed });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
		this->shape.move({ 0.f, this->movementSpeed });
}

// Private functions
void Player::initVariables()
{
	this->movementSpeed = 3.f;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f({ 50.f, 50.f }));
}
