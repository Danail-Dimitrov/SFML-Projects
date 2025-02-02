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
	const sf::RectangleShape& getShape() const { return this->shape; }

	// Functions
	// I need the target to make the window bounds
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

private:
	// Private variables
	sf::RectangleShape shape;
	float movementSpeed;
	int hp;
	int hpMax;
	int points;

	// Update functions
	void updateInput();
	void updateWindowBounds(const sf::RenderTarget* target);

	// Functions
	void initVariables();
	void initShape();
};

