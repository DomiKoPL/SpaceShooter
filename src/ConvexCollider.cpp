#include "ConvexCollider.h"
#include <iostream>

#include "ConstVariables.h"
#include <cmath>
#include <algorithm>



ConvexCollider::ConvexCollider(int size)
	: Collider()
	, vertices(size)
{
	normals.resize(size);
}

ConvexCollider::ConvexCollider(std::vector<sf::Vector2f> vertices, sf::Vector2f position, sf::Vector2f origin)
	: Collider(position, origin)
	, vertices(vertices)
{
	normals.resize(vertices.size());
	updateNormals();
}

void ConvexCollider::setVertex(sf::Vector2f position, int index)
{
	if (index >= (int)vertices.size() || index < 0)
	{

#ifdef DEBUG
		std::cout << "Bledny index\n";
#endif // DEBUG

		return;
	}

	vertices[index] = position;
}

bool ConvexCollider::isCollidingWith(Collider& object)
{
	return object.isCollidingWithConvex(*this);
}

bool ConvexCollider::isCollidingWith(Collider * object)
{
	return object->isCollidingWithConvex(*this);
}

bool ConvexCollider::isCollidingWithCircle(CircleCollider & collider)
{
	return false;
}

bool ConvexCollider::isCollidingWithRectangle(RectangleCollider & collider)
{
	return false;
}

bool ConvexCollider::isCollidingWithConvex(ConvexCollider & collider)
{

	for (auto& normal : normals)
	{
		auto result1 = getMinMaxAlong(normal);
		auto result2 = collider.getMinMaxAlong(normal);

		if (result1.first > result2.second || result1.second < result2.first)
			return false;
	}

	auto& normals2 = collider.getNormals();
	for (auto& normal : normals2)
	{
		auto result1 = getMinMaxAlong(normal);
		auto result2 = collider.getMinMaxAlong(normal);

		if (result1.first > result2.second || result1.second < result2.first)
			return false;
	}

#ifdef DEBUG
	std::cout << "Finded colision\n";
#endif // DEBUG

	return true;
}

bool ConvexCollider::isCollidingWithConvex(ConvexCollider * collider)
{

	for (auto& normal : normals)
	{
		auto result1 = getMinMaxAlong(normal);
		auto result2 = collider->getMinMaxAlong(normal);

		if (result1.first > result2.second || result1.second < result2.first)
			return false;
	}

	auto& normals2 = collider->getNormals();
	for (auto& normal : normals2)
	{
		auto result1 = getMinMaxAlong(normal);
		auto result2 = collider->getMinMaxAlong(normal);

		if (result1.first > result2.second || result1.second < result2.first)
			return false;
	}

#ifdef DEBUG
	std::cout << "Finded colision\n";
#endif // DEBUG

	return true;
}

bool ConvexCollider::isCollidingWithPoint(PointCollider & collider)
{
	return false;
}

std::pair<float, float> ConvexCollider::getMinMaxAlong(sf::Vector2f vector)
{
	std::pair<float, float> result = { INF, -INF };   //min and max

	float vectorMagnitude = sqrt(vector.x * vector.x + vector.y *vector.y);

	for (auto vertex : vertices)
	{
		vertex += position; //changing to global coordinates
		float dotProduct = vertex.x * vector.x + vertex.y * vector.y;
		float vertexCast = dotProduct / vectorMagnitude;

		result.first = std::min(result.first, vertexCast);
		result.second = std::max(result.second, vertexCast);
	}

	return result;
}


void ConvexCollider::setRotation(float newRoatation)
{
	float offset = newRoatation - rotation;
	rotate(offset);
}

void ConvexCollider::rotate(float offset)
{
	rotation += offset;

	float radAngle = offset / 180 * M_PI;
	for (auto & vertex : vertices)
	{
		sf::Vector2f newPosition;
		vertex -= getOrigin();

		newPosition.x = vertex.x * cos(radAngle) - vertex.y * sin(radAngle);
		newPosition.y = vertex.y * cos(radAngle) + vertex.x * sin(radAngle);

		vertex = newPosition + getOrigin();
	}

	updateNormals();
	//std::cout << "rotation complete\n";
}

float ConvexCollider::getMostLeftPoint()
{
	float res = INF;

	for (auto& i : vertices)
	{
		res = std::min(res, i.x);
	}

	return res;
}

float ConvexCollider::getMostRightPoint()
{
	float res = -INF;

	for (auto& i : vertices)
	{
		res = std::max(res, i.x);
	}

	return res;
}

void ConvexCollider::draw(sf::RenderWindow & window)
{

	sf::ConvexShape shape;

	shape.setPosition(position);
	shape.setPointCount(vertices.size());

	for (int i = 0; i < (int)vertices.size(); ++i)
		shape.setPoint(i, vertices[i]);

	shape.setFillColor(sf::Color::Cyan);

	window.draw(shape);
}

void ConvexCollider::updateNormals()
{
	normals[0].x = vertices[0].y - vertices[vertices.size() - 1].y;
	normals[0].y = -(vertices[0].x - vertices[vertices.size() - 1].x);
	for (int i = 0; i < (int)vertices.size() - 1; ++i)
	{
		normals[i + 1].x = vertices[i + 1].y - vertices[i].y;
		normals[i + 1].y = -(vertices[i + 1].x - vertices[i].x);
	}
}




