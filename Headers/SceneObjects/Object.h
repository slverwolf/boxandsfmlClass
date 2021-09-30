#pragma once
#include <string>
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "../scales.h"
#include <iostream>
struct FixtureUserData
{
	std::string objectType = "";
	bool  shouldBeDeleted = 0;
};

class Object
{
private:
	//box2d
	FixtureUserData* m_Data;
	b2PolygonShape m_shape;
	b2BodyDef m_bDef;
	b2FixtureDef m_fDef;
	b2Body* m_body;
	//sfml
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	bool m_isDeleted = 0;

public:
	Object();
	~Object();
	Object(b2World& world, std::string string, std::string imageWay,
		int w, int h, int x, int y);

	void setPos(b2World& world, int x, int y);
	void createSprite(std::string imageWay, int w, int h);
	void update(b2World& world, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void del(b2World& world);

	b2Body* getBody();
};

