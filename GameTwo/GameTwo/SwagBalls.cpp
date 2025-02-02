#include "SwagBalls.h"

SwagBalls::SwagBalls(const sf::RenderWindow& window)
{
	this->initShape(window);
}

SwagBalls::~SwagBalls()
{
}

void SwagBalls::update()
{

}

void SwagBalls::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

void SwagBalls::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));
	sf::Color color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	this->shape.setFillColor(color);
	this->shape.setPosition({
		static_cast<float>(rand() % static_cast<int>(window.getSize().x - this->shape.getRadius() * 2)),
		static_cast<float>(rand() % static_cast<int>(window.getSize().y - this->shape.getRadius() * 2))
		});
}
