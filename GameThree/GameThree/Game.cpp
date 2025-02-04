#include "Game.h"

Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initTextures();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	for (auto& i : this->textures)
		delete i.second;

	for (auto& i : this->bullets)
		delete i;
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
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture(); 
	if(!this->textures["BULLET"]->loadFromFile("Textures/bullet.png"))
		std::cout << "ERROR: BULLET TEXTURE VIOLATION";
}

void Game::update()
{
	this->pollEvents();

	this->player->update();
	
	this->updateBullets();
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

void Game::updateBullets()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		this->bullets.push_back(new Bullet(
		this->textures["BULLET"],
		this->player->getPosition().x,
		this->player->getPosition().y,
		0.f,
		0.f,
		0.f
		));
	}

	for (auto& i : this->bullets)
		i->update();
}

void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);

	for (auto& i : this->bullets)
		i->render(this->window);

	this->window->display();
}