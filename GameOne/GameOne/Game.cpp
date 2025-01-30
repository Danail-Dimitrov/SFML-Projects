#include "Game.h"
// Constructors
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
	this->initializeEnemies();
	this->initializeRandomEngine();
}

// Destructors
Game::~Game()
{
	delete this->window;
}

// Public functions
void Game::update()
{
	this->pollEvents();

	this->updateMousePositions();

	this->updateEnemies();
}

void Game::render()
{
	// Clear old frame
	// Instead of a color constant I can pass 3 ints for rgb
	//sf::Color::Blue
	this->window->clear();

	// Draw new frame
	this->renderEnemies();

	// Tells the app that the frame is ready to be displayed. (The window is done drawing)
	this->window->display();
}

//Accessors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

// Private functions
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

void Game::updateMousePositions()
{
	// Update mouse position relative to the window
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
}

void Game::spawnEnemy()
{
	// Spawns enemies and sets random color and a random position
	this->enemy.setPosition({
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y)),
		});
	
	this->enemy.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));

	// Spawned the enemy
	this->enemies.push_back(this->enemy);
}

void Game::updateEnemies()
{
	// Updading the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			// Spawn and enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}

	// Moves enemies downwards
	// Wraps the enemies at the bottom of the screen back to the top
	for (auto& e : this->enemies)
	{
		e.move({ 0.f, 1.f });
		// If the enemy is at the bottom of the screen
		if (e.getPosition().y > this->window->getSize().y)
		{
			e.setPosition({ e.getPosition().x, 0.f  });
		}
	}
}

void Game::renderEnemies()
{
	// Draws the enemies
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}

void Game::initializeRandomEngine()
{
	std::srand(static_cast<unsigned>(time(NULL)));
}

void Game::initializeVariables()
{
	this->window = nullptr;
	this->videoMode.size = { 800, 600 }; // 800x600 
	this->windowName = "GameOne"; // The name of the window

	// Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
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
	//this->window->setVerticalSyncEnabled(true);

	this->window->setFramerateLimit(60);
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