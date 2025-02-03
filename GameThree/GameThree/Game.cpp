#include "Game.h"

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Game Three", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::update()
{
}

void Game::render()
{
	this->window->clear();
	// Render items

	this->window->display();
}

