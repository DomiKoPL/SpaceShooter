#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Drawable
{
#pragma region Variables
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:

#pragma endregion

#pragma region Methodes
private:

public:
	Drawable(std::string path);
	Drawable(sf::Texture & texture);

	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	float getRotation();
	sf::Vector2f getOrigin();
	void setPosition(sf::Vector2f newPosition);
	void setRotation(float newRotation);  // in degrees
	void setOrigin(sf::Vector2f newOrigin);
	void rotate(float offset);
	void move(sf::Vector2f offset);
#pragma endregion
};

