#pragma once
#include <vector>
#include "Scene.h"
#include <memory>
class Game
{
private:
	std::vector<std::unique_ptr<Scene>> GAME;
	std::vector<bool> isSceneActive;
public:
	//Функция добавляет сцену
	void addScene(std::unique_ptr<Scene> scene);
	//Выбрать проигрываемую сцену
	void setActiveScene(int num);
	//апдейт проигрываемой сцены
	void update(b2World& world, sf::RenderWindow &window);
};

