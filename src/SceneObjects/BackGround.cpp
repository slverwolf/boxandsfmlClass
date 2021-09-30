#include "../../Headers/SceneObjects/BackGround.h"
BackGround::BackGround()
{

}

void BackGround::update(RenderWindow& window)
{
	window.draw(m_sprite);
}

void BackGround::createSprite(std::string imageWay)
{
	m_image.loadFromFile(imageWay);
	m_image.createMaskFromColor(sf::Color(255, 255, 255));
	m_texture.loadFromImage(m_image);
	m_texture.setRepeated(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(IntRect(0, 0, 2000, 2000));
	m_sprite.setPosition(0, 0);
}