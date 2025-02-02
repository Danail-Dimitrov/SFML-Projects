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

	this->spawnSwagBalls();

	this->player.update(this->window);
}

void Game::render()
{
	this->window->clear();
		
	this->player.render(this->window);

	this->renderSwagBalls(*this->window);

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
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode({ 800, 600 });
	this->window = new sf::RenderWindow(this->videoMode, "GameTwo", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initRandomSeed()
{
	srand(static_cast<unsigned>(time(NULL)));
}

void Game::spawnSwagBalls()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (static_cast<int>(this->swagBalls.size()) < this->maxSwagBalls)
		{
			this->swagBalls.push_back(SwagBalls(*this->window));
			this->spawnTimer = 0.f;
		}
	}
}

void Game::renderSwagBalls(sf::RenderTarget& target)
{
	for (auto& swagBall : this->swagBalls)
		swagBall.render(target);
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
