#pragma once

#include <SFML/Graphics.hpp>
#include "ConvexColliders.h"

class Missile : public ConvexColliders
{
#pragma region Variables
private:
	sf::Sprite sprite;
	sf::Vector2f offset;
	float speed = 2.0f;
public:

#pragma endregion

#pragma region Methodes
private:

public:
	Missile(sf::Texture &texture, sf::Vector2f position, float rotation, sf::Vector2f dpos);
	void draw(sf::RenderWindow & window);
	void move();
	bool isOnMap();

#pragma endregion
};

