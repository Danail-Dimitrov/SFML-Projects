#pragma once
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow* window;

	Player* player;

	void initWindow();
	void initPlayer();

	void update();
	void pollEvents();
	void updatePlayer();

	void render();
};

