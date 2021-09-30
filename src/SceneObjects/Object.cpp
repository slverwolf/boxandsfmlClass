#include "../../Headers/SceneObjects/Object.h"

Object::Object()
{

}

Object::~Object()
{

}

Object::Object(b2World &world,std::string string,std::string imageWay,int w,int h,int x,int y)
{
	m_shape.SetAsBox( PtoM(w/2), PtoM(h/2));
	m_bDef.type = b2_dynamicBody;
	m_bDef.position.Set(PtoM(x), PtoM(y));
	m_fDef.shape = &m_shape;
	m_fDef.density = 1;

	m_Data = new FixtureUserData;
	m_Data->objectType = "box";
	m_fDef.userData.pointer = reinterpret_cast<uintptr_t>(m_Data);

	m_body = world.CreateBody(&m_bDef);
	m_body->CreateFixture(&m_fDef);

	m_image.loadFromFile(imageWay);
	m_image.createMaskFromColor(sf::Color(255, 255, 255));
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(w / 2, h / 2);
}

void Object::setPos(b2World &world,int x , int y)
{
	world.DestroyBody(m_body);
	m_bDef.position.Set(PtoM(x), PtoM(y));
	m_body = world.CreateBody(&m_bDef);
	m_body->CreateFixture(&m_fDef);
}

void Object::createSprite(std::string imageWay,int w,int h)
{
	m_image.loadFromFile(imageWay);
	m_image.createMaskFromColor(sf::Color(255,255,255));
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(w / 2, h / 2);
}

void Object::update(b2World &world, sf::RenderWindow& window)
{
	if (m_Data->shouldBeDeleted == 1)
		this->del(world);
	b2Vec2 pos = m_body->GetPosition();
	m_sprite.setPosition(MtoP(pos.x), MtoP(pos.y));
	this->draw(window);
}

void Object::del(b2World &world)
{
	world.DestroyBody(m_body);
}

void Object::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

b2Body* Object::getBody()
{
	return m_body;
}