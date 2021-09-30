#include "../Headers/SFMLFunctions.h"

void sSetPol(sf::Texture& texture, sf::Sprite& sprite, int w, int h, int x, int y)
{
	sf::Image image;
	image.loadFromFile("Images\\Use\\Terrain\\wall.png");
	texture.loadFromImage(image);
	texture.setRepeated(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	sprite.setPosition(x, y);
	sprite.setOrigin(w / 2, h / 2);
}