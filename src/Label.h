#pragma once

#include <SFML/Graphics.hpp>
#include "Drawable.h"

class Label
{
private:
	sf::Sprite sprite;
	sf::Text text;
private:

public:
	void draw(sf::RenderWindow & window);
	void setColor(sf::Color color);
	void setTextColor(sf::Color color);
	Label(sf::Texture & texture, int width, int height, sf::Vector2f pos, sf::Text & _text, std::string alignment = "inside");
	Label(sf::Texture & texture, int width, int height, sf::Vector2f pos, std::string alignment = "inside");
	Label();
protected:
	sf::Sprite& getSprite();
};

