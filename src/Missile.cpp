#include "Missile.h"
#include "ConstVariables.h"

Missile::Missile(sf::Texture &texture, sf::Vector2f position, float rotation, sf::Vector2f dpos)
{
	ConvexColliders::addCollider({ { 0,0 }, { 9,0 }, { 9,54 }, { 0,54 } });
	ConvexColliders::rotate(rotation);
	ConvexColliders::move(position);

	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setRotation(rotation);
	offset = dpos;
}

void Missile::draw(sf::RenderWindow & window)
{
	window.draw(sprite);

#ifdef SHOW_COLLIDERS 
	ConvexColliders::draw(window);
#endif // SHOW_COLLIDERS

}

void Missile::move()
{
	sprite.move(offset * speed);
	ConvexColliders::move(offset * speed);
}

bool Missile::isOnMap()
{
	if (sprite.getPosition().x < -100 || sprite.getPosition().x > WIDTH + 100)
		return false;

	if (sprite.getPosition().y < -100 || sprite.getPosition().y > WIDTH + 100)
		return false;

	return true;
}
