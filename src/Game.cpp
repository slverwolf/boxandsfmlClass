#include "../Headers/Game.h"

void Game::addScene(std::unique_ptr<Scene> scene)
{
	GAME.emplace_back(std::move(scene));
	isSceneActive.push_back(0);
}

void Game::setActiveScene(int num)
{
	for (int i = 0; i < GAME.size(); i++)
	{
		isSceneActive[i] = 0;
	}
	isSceneActive[num] = 1;
}
void Game::update(b2World& world, sf::RenderWindow& window)
{
	for (int i = 0; i < GAME.size(); i++)
	{
		if (isSceneActive[i] == 1)
		{
			GAME[i].get()->update(world,window);
			return;
		}
	}
}