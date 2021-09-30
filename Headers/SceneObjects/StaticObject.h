#pragma once
#include <string>
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "../scales.h"
#include <iostream>
#include "Object.h"

class StaticObject
{
private:
	FixtureUserData* m_Data;
	b2PolygonShape m_shape;
	b2BodyDef m_bDef;
	b2FixtureDef m_fDef;
	b2Body* m_body;
	//sfml
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
public:
	//string- строка в userData
	//sence - осязаемость
	//w,h-Высота и ширина объекта
	//x,y - координаты центра . 
	//Объект - сенсор?
	//все в пикселях
	StaticObject(b2World& world, std::string string, std::string imageWay,
		int w, int h, int x, int y, bool sence);
	void createSprite(std::string imageWay, int x, int y, int w, int h);
	void update(sf::RenderWindow& window);
};

