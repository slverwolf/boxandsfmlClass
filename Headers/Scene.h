#pragma once
#include <vector>
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "SceneObjects/Object.h"
#include "SceneObjects/StaticObject.h"
#include "SceneObjects/BackGround.h"
class Scene
{
protected:
	std::vector<Object> m_objects;
	std::vector<bool> m_isObjectLive;
	std::vector<StaticObject> m_staticObjects;
	BackGround m_backGround;
public:
	Scene() {};
	//������� ���������� � ����� �������
	void addObject(Object &obj);
	void addStaticObject(StaticObject& obj);
	//������� ���������� �����
	virtual void update(b2World& world, sf::RenderWindow& window);
	//����� ������� ��� �������� ������� m_isobjLive,������� == 0
	//� ��� �� ��������������� ������� m_objects
	void deleteDeadObj();
};

