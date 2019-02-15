#include "Background.h"

Background * Background::GetInstance()
{
	static Background _background;
	return &_background;
}

Background::Background()
{
	texture.loadFromFile(texturePath);

	int countX = 0;
	while (countX * texture.getSize().x <= WIDTH)
		countX++;

	int countY = 0;
	while (countY * texture.getSize().y <= HEIGHT)
		countY++;

	for (int i = 0; i < countX; i++)
	{
		for (int j = 0; j < countY; j++)
		{
			sf::Sprite sprite;
			sprites.push_back(sprite);
			sprites.back().setTexture(texture);
			sprites.back().setPosition(sf::Vector2f(1.f * i * texture.getSize().x, 1.f * j * texture.getSize().y));
		}
	}
}

void Background::draw(sf::RenderWindow & window)
{
	for (auto& sprite : sprites)
	{
		window.draw(sprite);
	}
}