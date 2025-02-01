#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	// Constructors and destructors
	Player();
	~Player();
	// Accessors
	const int& getHealth() const;
	const int& getScore() const;
	// Modifiers
	void setHealth(const int health);
	void setScore(const int score);
	// Functions
	void update();
	void render(sf::RenderTarget* target);

private:
	// Private variables
	sf::RectangleShape shape;

	// Functions
	void initVariables();
	void initShape();
};

