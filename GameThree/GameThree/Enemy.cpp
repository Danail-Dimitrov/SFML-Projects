#include "Enemy.h"

Enemy::Enemy(float x, float y)
{
	this->initVariables();

	this->initShape(x, y);
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	this->shape.move({ 0.f, 1.f});
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

void Enemy::initVariables()
{
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 1;
	this->points = 5;
	this->type = 0;
}

void Enemy::initShape(float x, float y)
{
	float radius = rand() % 20 + 20;
	this->shape.setRadius(radius);
	
	float pointCount = rand() % 20 + 3;
	this->shape.setPointCount(pointCount);

	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));

	this->shape.setPosition({ x, y });
}
