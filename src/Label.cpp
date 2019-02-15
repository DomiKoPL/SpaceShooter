#include "Label.h"

void Label::draw(sf::RenderWindow & window)
{
	window.draw(sprite);

	window.draw(text);
}

void Label::setColor(sf::Color color)
{
	sprite.setColor(color);
}

void Label::setTextColor(sf::Color color)
{
	if (text.getFillColor() != color)
	{
		text.setFillColor(color);
	}
}

Label::Label(sf::Texture & texture, int width, int height, sf::Vector2f pos, sf::Text & _text, std::string alignment)
{
	sprite.setTexture(texture);

	float scaleY = (float)height / (float)texture.getSize().y;
	float scaleX = (float)width / (float)texture.getSize().x;

	sprite.setScale(sf::Vector2f(scaleX, scaleY));

	pos.x -= sprite.getGlobalBounds().width / 2;
	pos.y -= sprite.getGlobalBounds().height / 2;

	sprite.setPosition(pos);
	text = _text;

	sf::Vector2f shift;

	if (alignment == "inside")
	{
		shift.x = (sprite.getGlobalBounds().width - text.getGlobalBounds().width) / 2.f;
		shift.y = (sprite.getGlobalBounds().height - text.getGlobalBounds().height) / 2.f;
		shift.y -= text.getGlobalBounds().height / 2;//YYYYY IT WORKS :D
	}
	else if (alignment == "up")
	{
		shift.x = (sprite.getGlobalBounds().width - text.getGlobalBounds().width) / 2.f;
		shift.y = sprite.getGlobalBounds().height * 0.08;
	}

	text.setPosition(pos + shift);
}

Label::Label(sf::Texture & texture, int width, int height, sf::Vector2f pos, std::string alignment)
{
	sf::Text emptyText;
	Label(texture, width, height, pos, emptyText, alignment);
}


Label::Label()
{

}

sf::Sprite & Label::getSprite()
{
	return sprite;
}
