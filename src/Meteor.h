#pragma once

#include <SFML/Graphics.hpp>
#include "ConvexColliders.h"

class Meteor : public ConvexColliders
{
#pragma region Variables
private:
	sf::Vector2f offset;
	sf::Sprite sprite;
public:

#pragma endregion

#pragma region Methodes
private:

public:
	Meteor(sf::Texture & texture, sf::Vector2f position, sf::Vector2f _offset, std::vector<sf::Vector2f> vertices);
	Meteor(sf::Texture & texture, sf::Vector2f position, sf::Vector2f _offset, std::vector<std::vector<sf::Vector2f> >vertices);
	void draw(sf::RenderWindow & window);
	void move();
	bool isOnMap();

#pragma endregion
};

