#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class CircleCollider;
class RectangleCollider;
class ConvexCollider;
class PointCollider;

class Collider
{
public:
	Collider();
	Collider(sf::Vector2f position);
	Collider(sf::Vector2f position,sf::Vector2f _origin);

	virtual bool isCollidingWith(Collider& collider) = 0;  //return true if this is coliding with given object
	virtual bool isCollidingWith(Collider* collider) = 0;  //return true if this is coliding with given object
	virtual bool isCollidingWithCircle(CircleCollider& collider) = 0;
	virtual bool isCollidingWithRectangle(RectangleCollider& collider) = 0;
	virtual bool isCollidingWithConvex(ConvexCollider& collider) = 0;
	virtual bool isCollidingWithPoint(PointCollider& collider) = 0;

	virtual std::pair<float, float> getMinMaxAlong(sf::Vector2f vector) = 0;
	virtual const std::vector<sf::Vector2f>& getNormals();


	void setPosition(sf::Vector2f newPosition);
	void move(sf::Vector2f offset);
	virtual void setRotation(float newRoatation);
	virtual void rotate(float offset);
	sf::Vector2f getPosition();
	virtual float getMostLeftPoint();
	virtual float getMostRightPoint();
	float getRotation(); //in degrees
	sf::Vector2f getOrigin();
	virtual void setOrigin(sf::Vector2f newOrigin);

	virtual void draw(sf::RenderWindow& window) = 0;

protected:
	sf::Vector2f position;
	float rotation;
	sf::Vector2f origin;
	std::vector<sf::Vector2f> normals;
};

