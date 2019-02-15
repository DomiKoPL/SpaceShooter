#pragma once
#include "Collider.h"
#include <vector>
#include <initializer_list>

class ConvexCollider :
	public Collider
{
public:
	ConvexCollider(int size);
	ConvexCollider(std::vector<sf::Vector2f> vertices, sf::Vector2f position = { 0.f,0.f }, sf::Vector2f origin = { 0,0 });

	void setVertex(sf::Vector2f position, int index); //counting starts at 0;

	virtual bool isCollidingWith(Collider& collider);  //return true if this is coliding with given object
	virtual bool isCollidingWith(Collider* collider);  //return true if this is coliding with given object
	virtual bool isCollidingWithCircle(CircleCollider& collider);
	virtual bool isCollidingWithRectangle(RectangleCollider& collider);
	virtual bool isCollidingWithConvex(ConvexCollider& collider);
	virtual bool isCollidingWithConvex(ConvexCollider* collider);
	virtual bool isCollidingWithPoint(PointCollider& collider);

	virtual std::pair<float, float> getMinMaxAlong(sf::Vector2f vector); //return pair<min,max> of dot products along given vector


	virtual void setRotation(float newRoatation);
	virtual void rotate(float offset);

	virtual float getMostLeftPoint();
	virtual float getMostRightPoint();

	virtual void draw(sf::RenderWindow& window);


protected:
	std::vector<sf::Vector2f> vertices;

	void updateNormals();
};

