#include "Meteor.h"
#include "ConstVariables.h"

Meteor::Meteor(sf::Texture & texture, sf::Vector2f position, sf::Vector2f _offset, std::vector<sf::Vector2f> vertices)
	: ConvexColliders(vertices, position)
{
	sprite.setTexture(texture);
	sprite.setPosition(position);
	offset = _offset;
}
Meteor::Meteor(sf::Texture & texture, sf::Vector2f position, sf::Vector2f _offset, std::vector<std::vector<sf::Vector2f> >vertices)
	: ConvexColliders(vertices, position)
{
	sprite.setTexture(texture);
	sprite.setPosition(position);
	offset = _offset;
}

void Meteor::draw(sf::RenderWindow & window)
{
	window.draw(sprite);

	#ifdef SHOW_COLLIDERS
	ConvexColliders::draw(window);
	#endif // SHOW_COLLIDERS

}

void Meteor::move()
{
	sprite.move(offset);
	ConvexColliders::move(offset);
}

bool Meteor::isOnMap()
{
	if (sprite.getPosition().x < -200 || sprite.getPosition().x > WIDTH + 200)
		return false;

	if (sprite.getPosition().y < -200 || sprite.getPosition().y > WIDTH + 200)
		return false;

	return true;
}
