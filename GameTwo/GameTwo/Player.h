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
	const int& getHp() const { return this->hp; }
	const int& getHpMax() const { return this->hpMax; }

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

	// Update functions
	void updateInput();
	void updateWindowBounds(const sf::RenderTarget* target);

	// Functions
	void initVariables();
	void initShape();
};

