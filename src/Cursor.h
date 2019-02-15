#pragma once

#include <SFML/Graphics.hpp>

class Cursor
{
private:
	sf::Texture cursorTexture;
	sf::Sprite cursorSprite;

private:
	void setup();
public:
	static Cursor* GetInstance();
	void draw(sf::RenderWindow & window);
	void update(sf::RenderWindow & window);
	Cursor();
};
#define cursor Cursor::GetInstance()

