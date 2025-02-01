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
}

void Game::render()
{
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
