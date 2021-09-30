#pragma once
#include "SFML/Graphics.hpp"
#include <string>
using namespace sf;

class BackGround
{
private:
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
public:
	//Задать картинку бекгрануда
	BackGround();
	void update(RenderWindow& window);
	void createSprite(std::string imageWay);
};

