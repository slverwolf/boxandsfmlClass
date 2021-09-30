#include "../Headers/Scene.h"

void Scene::addObject(Object &obj)
{
	m_objects.push_back(obj);
	m_isObjectLive.push_back(1);
}

void Scene::update(b2World& world, sf::RenderWindow& window)
{
	std::cout << "father";
	this->deleteDeadObj();
	m_backGround.update(window);
	for (int i = 0; i < m_staticObjects.size(); i++)
	{
		m_staticObjects[i].update(window);
	}
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i].update(world,window);
	}
}

void Scene::deleteDeadObj()
{
	int i = 0;
	for (std::vector<bool>::const_iterator it = m_isObjectLive.begin(); it != m_isObjectLive.end(); ++it)
	{
		if (*it == 0)
		{
			m_isObjectLive.erase(m_isObjectLive.begin() + i);
			m_objects.erase(m_objects.begin() + i);
			i--;
		}
		i++;
	}
}

void Scene::addStaticObject(StaticObject& obj)
{
	m_staticObjects.push_back(obj);
}
