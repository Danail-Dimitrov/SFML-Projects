#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	// Constructors and destructors
	Player(float x = 0.f, float y = 0.f);
	~Player();
	// Accessors
	const int& getHealth() const;
	const int& getScore() const;
	// Modifiers
	void setHealth(const int health);
	void setScore(const int score);
	// Functions
	// I need the target to make the window bounds
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

private:
	// Private variables
	sf::RectangleShape shape;
	float movementSpeed;

	// Update functions
	void updateInput();

	// Functions
	void initVariables();
	void initShape();
};

