#pragma once
#include "../Headers/Scene.h"
#include "../Headers/SceneObjects/Object.h"
#include "box2d/box2d.h"
#include <iostream>

class Scene1 : public Scene
{
public:
	Scene1(b2World &world,sf::RenderWindow &window)
	{
		m_backGround.createSprite("Images\\Use\\Terrain\\back.png");
		Object box(world, "box", "Images\\Use\\Terrain\\box.png", 21, 16, 300, 100);
		Object box1(world, "box", "Images\\Use\\Terrain\\box.png", 21, 16, 400, 100);
		Object box2(world, "box", "Images\\Use\\Terrain\\box.png", 21, 16, 500, 100);
		this->addObject(box);
		this->addObject(box1);
		this->addObject(box2);
		StaticObject ground(world,"","Images\\Use\\Terrain\\wall.png",
			75*30,96,75*30/2,300,0);
		this->addStaticObject(ground);

	}
	virtual void update(b2World& world, sf::RenderWindow& window) override
	{
		std::cout << "children";
		m_backGround.update(window);

		for (int i = 0; i < m_staticObjects.size(); i++)
		{
			m_staticObjects[i].update(window);
		}

		for (int i = 0; i < m_objects.size(); i++)
		{
			m_objects[i].update(world, window);
		}

	}
};



