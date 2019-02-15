#include "ConvexColliders.h"

void ConvexColliders::addCollider(std::vector<sf::Vector2f> vertices, sf::Vector2f position, sf::Vector2f origin)
{
	colliders.push_back(new ConvexCollider(vertices, position, origin));
}

void ConvexColliders::addColliders(std::vector<std::vector<sf::Vector2f>> allVertices, sf::Vector2f position, sf::Vector2f origin)
{
	for (auto&vertices : allVertices)
	{
		addCollider(vertices, position, origin);
	}
}

void ConvexColliders::draw(sf::RenderWindow & window)
{
	for (auto& collider : colliders)
	{
		collider->draw(window);
	}
}

bool ConvexColliders::isCollidingWith(Collider & object)
{
	for (auto& collider : colliders)
	{
		if (collider->isCollidingWith(object))
		{
			return true;
		}
	}
	return false;
}

bool ConvexColliders::isCollidingWith(Collider * object)
{
	for (auto& collider : colliders)
	{
		if (collider->isCollidingWith(*object))
		{
			return true;
		}
	}
	return false;
}

bool ConvexColliders::isCollidingWith(ConvexColliders * object)
{
	for (auto& collider : colliders)
	{
		if (object->isCollidingWith(collider))
		{
			return true;
		}
	}
	return false;
}

void ConvexColliders::move(sf::Vector2f offset)
{
	for (auto& collider : colliders)
	{
		collider->move(offset);
	}
}

void ConvexColliders::rotate(float offset)
{
	for (auto& collider : colliders)
	{
		collider->rotate(offset);
	}
}

void ConvexColliders::setOrigin(sf::Vector2f newOrigin)
{
	for (auto& collider : colliders)
	{
		collider->setOrigin(newOrigin);
	}
}

float ConvexColliders::getMostLeftPoint()
{
	float res = INF;

	for (auto& i : colliders)
	{
		res = std::min(res, i->getMostLeftPoint());
	}

	return res;
}

float ConvexColliders::getMostRightPoint()
{
	float res = -INF;

	for (auto& i : colliders)
	{
		res = std::max(res, i->getMostRightPoint());
	}

	return res;
}

ConvexColliders::ConvexColliders(std::vector<std::vector<sf::Vector2f> > allVertices, sf::Vector2f position, sf::Vector2f origin)
{
	for (auto&vertices : allVertices)
	{
		addCollider(vertices, position, origin);
	}
}

ConvexColliders::ConvexColliders(std::vector<sf::Vector2f> vertices, sf::Vector2f position, sf::Vector2f origin)
{
	addCollider(vertices, position, origin);
}

ConvexColliders::ConvexColliders()
{

}