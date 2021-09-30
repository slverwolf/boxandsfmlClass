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
	//������� ��������� �����
	void addScene(std::unique_ptr<Scene> scene);
	//������� ������������� �����
	void setActiveScene(int num);
	//������ ������������� �����
	void update(b2World& world, sf::RenderWindow &window);
};

