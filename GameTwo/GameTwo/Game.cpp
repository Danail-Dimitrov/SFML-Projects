#include "Game.h"

// Constructors and destructors
Game::Game()
{
	this->initVariables();
	this->initRandomSeed();
	this->initWindow();
	this->initFont();
	this->initText();
	this->initEndGameText();
}

Game::~Game()
{
	delete this->window;
	delete this->uiText;
	delete this->endGameText;
}

// Functions
void Game::update()
{
	this->pollEvents();

	if (!this->isEndGame())
	{
		this->spawnSwagBalls();

		this->player.update(this->window);

		this->updateCollision();

		this->updateText();
	}
}

void Game::render()
{
	this->window->clear();
		
	if (!this->isEndGame())
	{
		this->player.render(this->window);

		this->renderSwagBalls(*this->window);

		this->renderText(*this->window);
	}
	else
		this->window->draw(*this->endGameText);
	
	this->window->display();
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

// Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->endGame = false;
	this->spawnTimerMax = 40.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;
	this->points = 0;
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

void Game::initFont()
{
	if (!this->font.openFromFile("Fonts/Dosis-Light.ttf"))
		std::cout << "ERROR::GAME::INITIALIZEFONTS::Failed to load font" << std::endl;
}

void Game::initText()
{
	this->uiText = new sf::Text(this->font);
	this->uiText->setCharacterSize(24);
	this->uiText->setFillColor(sf::Color::White);
	this->uiText->setOutlineColor(sf::Color::Black);
	this->uiText->setOutlineThickness(1.f);
	this->uiText->setPosition({ 0.f, 0.f });
	this->uiText->setString("Points: NO VALUE \n Health: NO VALUE");

}

void Game::initEndGameText()
{
	this->endGameText = new sf::Text(this->font);
	this->endGameText->setCharacterSize(60);
	this->endGameText->setFillColor(sf::Color::Red);
	this->endGameText->setOutlineColor(sf::Color::Black);
	this->endGameText->setOutlineThickness(1.f);
	this->endGameText->setPosition({ 100.f, 250.f });
	this->endGameText->setString("GAME OVER");
}

const int Game::randomizeBallType() const
{
	int type = SwagBallTypes::DEFAULT;
	int random = rand() % 100 + 1;

	if (random > 10 && random <= 80)
		type = SwagBallTypes::DAMAGE;
	else if (random > 80) 
		type = SwagBallTypes::HEAL;

	return type;
}

bool Game::isEndGame() const
{
	return this->player.getHp() <= 0;
}

void Game::spawnSwagBalls()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (static_cast<int>(this->swagBalls.size()) < this->maxSwagBalls)
		{
			this->swagBalls.push_back(SwagBalls(*this->window, this->randomizeBallType()));
			this->spawnTimer = 0.f;
		}
	}
}

void Game::renderSwagBalls(sf::RenderTarget& target)
{
	for (auto& swagBall : this->swagBalls)
		swagBall.render(target);
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(*this->uiText);
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

void Game::updateCollision()
{
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().findIntersection(this->swagBalls[i].getShape().getGlobalBounds()))
		{
			this->points++;
			switch (this->swagBalls[i].getType())
			{
			case SwagBallTypes::DEFAULT:
				break;
			case SwagBallTypes::DAMAGE:
				this->player.loseHp(1);
				break;
			case SwagBallTypes::HEAL:
				this->player.gainHp(1);
				break;
			default:
				std::cout << "ERROR::GAME::UPDATECOLLISION::SWAGBALLTYPE::UNKNOWN_TYPE" << std::endl;
				break;
			}
			this->swagBalls.erase(this->swagBalls.begin() + i);

			this->updateGameState();
		}
	}
}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Points: " << this->points << "\n"
		<< "Health: " << this->player.getHp() << " / " << this->player.getHpMax();

	this->uiText->setString(ss.str());
}

void Game::updateGameState()
{
	if (this->player.getHp() < 1)
		this->endGame = true;
}
