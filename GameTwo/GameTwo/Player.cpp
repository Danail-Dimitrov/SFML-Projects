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
void Player::update(const sf::RenderTarget* target)
{
	// Keyboard input
	this->updateInput();
	
	// Window bounds
	this->updateWindowBounds(target);
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

void Player::updateWindowBounds(const sf::RenderTarget* target)
{
	sf::Vector2f position = this->shape.getPosition();
	// If we change the position imidiently the checks override each other when for example we press A and W at the same time while at the correner
	sf::Vector2f correctedPosition = position;

	// Left
	if (position.x < 0.f)
		correctedPosition.x = 0.f;
	// Right
	else if (position.x + this->shape.getSize().x > target->getSize().x)
		correctedPosition.x = target->getSize().x - this->shape.getSize().x;
	// Top
	if (position.y < 0.f)
		correctedPosition.y = 0.f;
	// Bottom
	else if (position.y + this->shape.getSize().y > target->getSize().y)
		correctedPosition.y = target->getSize().y - this->shape.getSize().y;

	this->shape.setPosition(correctedPosition);
}

// Private functions
void Player::initVariables()
{
	this->movementSpeed = 5.f;
	this->hpMax = 10;
	this->hp = this->hpMax;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f({ 50.f, 50.f }));
}