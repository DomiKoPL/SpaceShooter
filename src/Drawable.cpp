#include "Drawable.h"

Drawable::Drawable(std::string path)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

Drawable::Drawable(sf::Texture & texture)
{
	sprite.setTexture(texture);
}

void Drawable::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

sf::Vector2f Drawable::getPosition()
{
	return sprite.getPosition();
}

float Drawable::getRotation()
{
	return sprite.getRotation();
}

sf::Vector2f Drawable::getOrigin()
{
	return sprite.getOrigin();
}

void Drawable::setPosition(sf::Vector2f newPosition)
{
	sprite.setPosition(newPosition);
}

void Drawable::setRotation(float newRotation)
{
	sprite.setRotation(newRotation);
}

void Drawable::setOrigin(sf::Vector2f newOrigin)
{
	sprite.setOrigin(newOrigin);
}

void Drawable::rotate(float offset)
{
	sprite.rotate(offset);
}

void Drawable::move(sf::Vector2f offset)
{
	sprite.move(offset);
}