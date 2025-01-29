#include "Game.h"
// Constructors
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
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
}

void Game::render()
{
	// Clear old frame
	// Instead of a color constant I can pass 3 ints for rgb
	this->window->clear(sf::Color::Blue);

	// Draw new frame

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
