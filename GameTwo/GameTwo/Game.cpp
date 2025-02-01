#include "Game.h"

// Constructors and destructors
Game::Game()
{
	this->initVariables();
	this->initRandomSeed();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

// Functions
void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();
		
	this->player.render(this->window);

	this->window->display();
}

const bool Game::isRunning() const
{
	return this->window->isOpen() && !this->endGame;
}

// Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode({ 800, 600 });
	this->window = new sf::RenderWindow(this->videoMode, "GameTwo", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initRandomSeed()
{
	srand(static_cast<unsigned>(time(NULL)));
}

void Game::pollEvents()
{
	while (const std::optional event = this->window->pollEvent())
	{
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
