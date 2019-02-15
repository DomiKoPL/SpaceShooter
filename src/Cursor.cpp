#include "Cursor.h"

void Cursor::setup()
{
	std::string path = "Resources/PNG/UI/";
	cursorTexture.loadFromFile(path + "cursor.png");

	cursorSprite.setTexture(cursorTexture);
}

Cursor * Cursor::GetInstance()
{
	static Cursor _cursor;
	return &_cursor;
}

void Cursor::draw(sf::RenderWindow & window)
{
	window.draw(cursorSprite);
}

void Cursor::update(sf::RenderWindow & window)
{
	cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

Cursor::Cursor()
{
	setup();
}