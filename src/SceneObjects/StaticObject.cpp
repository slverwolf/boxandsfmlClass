#include "../../Headers/SceneObjects/StaticObject.h"

StaticObject::StaticObject(b2World& world, std::string string, std::string imageWay,
	int w, int h, int x, int y, bool sence)
{
	m_shape.SetAsBox(PtoM(w / 2), PtoM(h / 2));
	m_bDef.position.Set(PtoM(x), PtoM(y));
	m_fDef.shape = &m_shape;
	m_fDef.isSensor = sence;

	m_Data = new FixtureUserData;
	m_Data->objectType = string;
	m_fDef.userData.pointer = reinterpret_cast<uintptr_t>(m_Data);

	m_body = world.CreateBody(&m_bDef);
	m_body->CreateFixture(&m_fDef);

	this->createSprite(imageWay, x, y, w, h);
}

void StaticObject::createSprite(std::string imageWay, int x, int y, int w, int h)
{
	m_image.loadFromFile(imageWay);
	m_image.createMaskFromColor(sf::Color(255, 255, 255));
	m_texture.loadFromImage(m_image,sf::IntRect(0,0,75,96));
	m_texture.setRepeated(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	m_sprite.setOrigin(w / 2, h / 2);
	m_sprite.setPosition(x, y);
}

void StaticObject::update(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}