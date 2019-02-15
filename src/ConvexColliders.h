#pragma once

#include "ConvexCollider.h"
#include "ConstVariables.h"
#include <SFML/Graphics.hpp>
#include <vector>

class ConvexColliders
{
private:
	std::vector<Collider*>colliders;
public:
	void addCollider(std::vector<sf::Vector2f> vertices, sf::Vector2f position = { 0,0 }, sf::Vector2f origin = { 0,0 });
	void addColliders(std::vector<std::vector<sf::Vector2f> > allVertices, sf::Vector2f position = { 0,0 }, sf::Vector2f origin = { 0,0 });
	void draw(sf::RenderWindow & window);
	bool isCollidingWith(Collider& collider);  //return true if this is coliding with given object
	bool isCollidingWith(Collider* collider);  //return true if this is coliding with given object
	bool isCollidingWith(ConvexColliders* collider);  //return true if this is coliding with given object
	void move(sf::Vector2f offset);
	void rotate(float offset);
	void setOrigin(sf::Vector2f newOrigin);
	float getMostLeftPoint();
	float getMostRightPoint();
	ConvexColliders(std::vector<std::vector<sf::Vector2f> > allVertices, sf::Vector2f position = { 0,0 }, sf::Vector2f origin = { 0,0 });
	ConvexColliders(std::vector<sf::Vector2f> vertices, sf::Vector2f position = { 0,0 }, sf::Vector2f origin = { 0,0 });
	ConvexColliders();
};

