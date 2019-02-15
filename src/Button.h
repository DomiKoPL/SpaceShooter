#pragma once

#include <SFML/Graphics.hpp>
#include "Label.h"

class Button : public Label
{
private:
	sf::Color color1;
	sf::Color color2;
private:

public:
	bool isClickInBounds(sf::Vector2f clickPosition);
	void checkIfHighlight(sf::Vector2f mousePosition);
	Button(sf::Texture & texture, int width, int height, sf::Vector2f pos, sf::Text & _text, sf::Color color1, sf::Color color2, std::string alignment = "inside");
	Button();
};