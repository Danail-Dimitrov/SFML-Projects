#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, float x, float y, float dirX, float dirY, float movementSpeed)
{
	this->direction = { dirX, dirY };
	this->movementSpeed = movementSpeed;
	this->initSptite(texture, x, y);
}

Bullet::Bullet()
{
	this->sprite = nullptr;
	this->movementSpeed = 0.f;
	this->direction = { 0.f, 0.f };
}

Bullet::~Bullet()
{
	delete this->sprite;
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->sprite->getGlobalBounds();
}

void Bullet::update()
{
	this->sprite->move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(*this->sprite);
}

void Bullet::initSptite(sf::Texture* texture, float x, float y)
{
	this->sprite = new sf::Sprite(*texture);
	this->sprite->setScale({ 0.02f,0.02f });
	this->sprite->setPosition({ x,y });
}
