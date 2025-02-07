#pragma once
#include <vector>
#include <map>
#include <time.h>

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

	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	std::vector<Bullet*> bullets;

	void initWindow();
	void initPlayer();
	void initEnemies();
	void initRandomization();

	void update();
	void pollEvents();
	void updateBullets();
	void updatePlayer();
	void updateEnemies();
	void updateEnemiesCollision();

	void render();
	void renderEnemies();
};

