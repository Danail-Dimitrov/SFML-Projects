#include "Game.h"

Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initRandomization();
	this->initEnemies();
	this->initText();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->pointsText;

	for (auto& i : this->bullets)
		delete i;

	for(auto & i : this->enemies)
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
	this->points = 0;
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 200.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initText()
{
	if (!this->font.openFromFile("Fonts/Dosis-Light.ttf"))
		std::cout << "ERROR::GAME::INITIALIZEFONTS::Failed to load font" << std::endl;

	this->pointsText = new sf::Text(this->font);
	this->pointsText->setCharacterSize(24);
	this->pointsText->setFillColor(sf::Color::White);
	this->pointsText->setOutlineColor(sf::Color::Black);
	this->pointsText->setOutlineThickness(1.f);
	this->pointsText->setPosition({ 0.f, 0.f });
	this->pointsText->setString("Points: NO VALUE \n Health: NO VALUE");
}

void Game::initRandomization()
{
	srand(static_cast<unsigned>(time(NULL)));
}

void Game::update()
{
	this->pollEvents();

	this->updatePlayer();
	
	this->updateBullets();

	this->updateEnemies();

	this->updateText();
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
	for (int i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i]->update();

		if (this->bullets[i]->getPosition().y + this->bullets[i]->getBounds().size.y < 0.f)
		{
			delete this->bullets[i];
			this->bullets.erase(this->bullets.begin() + i);
			i--;
		}

		std::cout << this->bullets.size() << std::endl;
	}
}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Points: " << this->points << "\n";

	this->pointsText->setString(ss.str());
}

void Game::updatePlayer()
{
	this->player->update();

	Bullet* bullet = this->player->updateAtack();

	if (bullet != nullptr)
		this->bullets.push_back(bullet);
}

void Game::updateEnemies()
{
	this->spawnTimer += 1.f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		float x = rand() % this->window->getSize().x - 20.f;
		this->enemies.push_back(new Enemy({ x, -100.f }));
		this->spawnTimer = 0;
	}

	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool enemyRemoved = false;
		this->enemies[i]->update();

		for (size_t j = 0; j < this->bullets.size(); j++)
		{
			if (this->enemies[i]->getBounds().findIntersection(this->bullets[j]->getBounds()))
			{
				this->bullets.erase(this->bullets.begin() + j);
				this->enemies.erase(this->enemies.begin() + i);
				i -= 1.f;
				enemyRemoved = true;
				this->points += 1;
				break;
			}
		}

		if (!enemyRemoved && this->enemies[i]->getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			i -= 1.f;
		}
	}
}

void Game::updateEnemiesCollision()
{
}

void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);

	for (auto& i : this->bullets)
		i->render(this->window);

	this->renderEnemies();

	this->renderText();

	this->window->display();
}

void Game::renderEnemies()
{
	for (auto* enemy : this->enemies)
		enemy->render(*this->window);
}

void Game::renderText()
{
	this->window->draw(*this->pointsText);
}
