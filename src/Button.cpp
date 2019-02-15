#include "Button.h"


bool Button::isClickInBounds(sf::Vector2f clickPosition)
{
	if (clickPosition.x < getSprite().getPosition().x || clickPosition.x > getSprite().getPosition().x + getSprite().getGlobalBounds().width
		|| clickPosition.y < getSprite().getPosition().y || clickPosition.y > getSprite().getPosition().y + getSprite().getGlobalBounds().height)
	{
		return false;
	}	

	return true;
}

void Button::checkIfHighlight(sf::Vector2f mousePosition)
{
	if (isClickInBounds(mousePosition))
	{
		Label::setColor(color2);
	}
	else
	{
		Label::setColor(color1);
	}
}

Button::Button(sf::Texture & texture, int width, int height, sf::Vector2f pos, sf::Text & _text, sf::Color color1, sf::Color color2, std::string alignment)
	:Label(texture, width, height, pos, _text, alignment)
{
	this->color1 = color1;
	this->color2 = color2;
}

Button::Button()
	: Label()
{
}
