#pragma once
#include <vector>
#include <map>

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

	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	void initWindow();
	void initPlayer();
	void initTextures();

	void update();
	void pollEvents();
	void updateBullets();
	void updatePlayer();

	void render();
};

