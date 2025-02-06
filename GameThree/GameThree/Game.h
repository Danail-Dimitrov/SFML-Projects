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

	Enemy* enemy;

	std::vector<Bullet*> bullets;

	void initWindow();
	void initPlayer();
	void initEnemy();
	void initRandomization();

	void update();
	void pollEvents();
	void updateBullets();
	void updatePlayer();

	void render();
};

