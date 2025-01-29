#include "Game.h"
// Constructors
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
	this->initializeEnemies();
}

// Destructors
Game::~Game()
{
	delete this->window;
}

// Public functions
void Game::pollEvents()
{
	// Event polling. (Did something happen)
	while (const std::optional event = this->window->pollEvent()) // Checks if an event occured and stores it in an optional
	{
		// If the event is to close the window, then close the window
		if (event->is<sf::Event::Closed>())
			this->window->close();
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			// Close the window if the pressed key is escape
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) //Scancode refers to the physical location of the key on the keyboard. For example Z in english and Y in German have the same scancode
				this->window->close();
		}
	}
}

void Game::update()
{
	this->pollEvents();

	// Update mouse position relative to the entire screen
	//auto pos = sf::Mouse::getPosition();
	//std::cout << "Mouse screen pos: " << pos.x << " " << pos.y << std::endl;

	// Update mouse position relative to the window
	auto posWindow = sf::Mouse::getPosition(*this->window);
	std::cout << "Mouse window pos: " << posWindow.x << " " << posWindow.y << std::endl;
}

void Game::render()
{
	// Clear old frame
	// Instead of a color constant I can pass 3 ints for rgb
	//sf::Color::Blue
	this->window->clear();

	// Draw new frame
	this->window->draw(this->enemy);

	// Tells the app that the frame is ready to be displayed. (The window is done drawing)
	this->window->display();
}

//Accessors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

// Private functions
void Game::initializeVariables()
{
	this->window = nullptr;
	this->videoMode.size = { 800, 600 }; // 800x600 
	this->windowName = "GameOne"; // The name of the window
}

void Game::initializeWindow()
{
	// Create a window with a default style. The style is the design of the window. Curently we have Titlebar, Close button and the option to resize the window.
	// Window is basic window that handles creation polling etc. It can not draw 2D graphics. I need to do my OpenGL rendering
	// RenderWindow inherits from Window and can draw 2D graphics
	this->window = new sf::RenderWindow(this->videoMode, this->windowName, sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

	// Set the position of the window on the screen
	this->window->setPosition({ 100, 100 });

	// We turn on vertical sync. This means that the game will run at the same speed as the monitor refresh rate.
	// We should call this function once after creating the window
	this->window->setVerticalSyncEnabled(true);
}

void Game::initializeEnemies()
{
	// Set the position of the rectangle (the coordinates are those of the top left corrner)
	this->enemy.setPosition({ 10.f, 10.f });
	// Size of the rectangle
	this->enemy.setSize({ 50.f, 50.f });
	// The color of the Rectangle
	this->enemy.setFillColor(sf::Color::Cyan);
	// The color of the outline
	this->enemy.setOutlineColor(sf::Color::Green);
	// Sets the thickness of the outline
	this->enemy.setOutlineThickness(1.f);
	// Change the scale of the enemy
	this->enemy.setScale({ 2.f, 2.f });
}