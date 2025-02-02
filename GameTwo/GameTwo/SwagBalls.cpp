#include "SwagBalls.h"

SwagBalls::SwagBalls(const sf::RenderWindow& window, int type) : type(type)
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
	this->shape.setPosition({
		static_cast<float>(rand() % static_cast<int>(window.getSize().x - this->shape.getRadius() * 2)),
		static_cast<float>(rand() % static_cast<int>(window.getSize().y - this->shape.getRadius() * 2))
		});
	
	sf::Color color;
	switch (this->type)
	{
	case SwagBallTypes::DEFAULT:
		color = sf::Color::White;
		break;
	case SwagBallTypes::DAMAGE:
		color = sf::Color::Red;
		break;
	case SwagBallTypes::HEAL:
		color = sf::Color::Green;
		break;
	default:
		color = sf::Color::Magenta;
		break;
	}

	this->shape.setFillColor(color);
}
