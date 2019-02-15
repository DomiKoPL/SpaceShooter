#include "Collider.h"
#include <cmath>

Collider::Collider()
	: position({ 0,0 })
	, rotation(0)
	, origin({0,0})
{
}

Collider::Collider(sf::Vector2f position)
	: position(position)
	, origin({0,0})
{

}

Collider::Collider(sf::Vector2f position, sf::Vector2f origin)
	:position(position)
	,origin(origin)
{
}

const std::vector<sf::Vector2f>& Collider::getNormals()
{
	return normals;
}

void Collider::setPosition(sf::Vector2f newPosition)
{
	position = newPosition;
}

void Collider::move(sf::Vector2f offset)
{
	position += offset;
}

void Collider::setRotation(float newRoatation)
{
	rotation = newRoatation;

	while (rotation > 360.0)
		rotation -= 360.0;
	while (rotation < 360.0)
		rotation += 360.0;
}

void Collider::rotate(float offset)
{
	rotation += offset;


	//normalizing rotation
	while (rotation > 360.0)
		rotation -= 360.0;
	while (rotation < 360.0)
		rotation += 360.0;
}

sf::Vector2f Collider::getPosition()
{
	return position;
}

float Collider::getMostLeftPoint()
{
	return 0.0f;
}

float Collider::getMostRightPoint()
{
	return 0.0f;
}

float Collider::getRotation()
{
	return rotation;
}

sf::Vector2f Collider::getOrigin()
{
	return origin;
}

void Collider::setOrigin(sf::Vector2f newOrigin)
{
	origin = newOrigin;
}

