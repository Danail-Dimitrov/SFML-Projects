#pragma once
#include <vector>
#include <map>
#include <time.h>
#include <sstream>

#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow* window;

	Player* player;
	int points;

	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	std::vector<Bullet*> bullets;

	sf::Font font;
	sf::Text* pointsText;

	void initWindow();
	void initPlayer();
	void initEnemies();
	void initText();
	void initRandomization();

	void update();
	void pollEvents();
	void updateBullets();
	void updateText();
	void updatePlayer();
	void updateEnemies();
	void updateEnemiesCollision();

	void render();
	void renderEnemies();
	void renderText();
};

