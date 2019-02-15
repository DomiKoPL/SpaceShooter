#include "SpaceShip.h"
#include "ConstVariables.h"
#include "MusicManager.h"
#include <cmath>
#include <string>
#include <iostream>

SpaceShip::SpaceShip()
	: Drawable("Resources/PNG/playerShip2_blue.png")
{
	float ox = 50, oy = 30;
	sf::Vector2f origin = { ox, oy };

	ConvexColliders::addCollider({ { 52,0 },{ 59,0 },{ 65,17 },{ 72,66 },{ 67,75 },{ 44,74 },{ 39,67 },{ 46,17 } });
	ConvexColliders::addCollider({ { 65,17 },{ 111,43 },{ 93,72 },{ 72,66 } });
	ConvexColliders::addCollider({ { 39,67 },{ 18,72 },{ 0,43 },{ 46,17 } });
	ConvexColliders::move(-origin);

	Drawable::setOrigin(origin);
	ConvexColliders::setOrigin(origin);
	sf::Vector2f startPos = { WIDTH / 2, HEIGHT / 2 };
	Drawable::move(startPos);//start position
	ConvexColliders::move(startPos);

	for (int i = 0; i < 3; i++)
	{
		std::string path = "Resources/PNG/Effects/shield"; path += (i + 1) + '0'; path += ".png";
		shieldTextures[i].loadFromFile(path);
		shieldSprite[i].setTexture(shieldTextures[i]);
	}
	shieldSprite[0].setOrigin(sf::Vector2f(60, 65));
	shieldSprite[1].setOrigin(sf::Vector2f(66, 65));
	shieldSprite[2].setOrigin(sf::Vector2f(66, 65));

	missileTexture.loadFromFile("Resources/PNG/Lasers/laserBlue01.png");


	for (char i = 0, j = '1'; i < 3; i++, j++)
	{
		std::string path = "Resources/PNG/Damage/playerShip2_damage";
		damageTexture[i].loadFromFile(path + j + ".png");
		damageSprite[i].setTexture(damageTexture[i]);
		damageSprite[i].setOrigin(getOrigin());
		damageSprite[i].setColor(sf::Color(255, 255, 255, 180));
	}

	hp = maxHp;
	shotDelay = defaultShotDelay;
	shieldLevel = startingShieldLevel;
}

sf::Vector2f SpaceShip::VectorForward()
{
	return sf::Vector2f(-std::sin((360 - Drawable::getRotation()) * M_PI / 180.f), -std::cos((360 - Drawable::getRotation())* M_PI / 180.f));
}

void SpaceShip::rotateLeft()
{
	ConvexColliders::rotate(-rotationSpeed);
	Drawable::rotate(-rotationSpeed);
}

void SpaceShip::rotateRight()
{
	ConvexColliders::rotate(rotationSpeed);
	Drawable::rotate(rotationSpeed);
}

void SpaceShip::moveForward()
{
	musicManager->playMusic("engine_long");
	Drawable::move(sf::Vector2f(VectorForward() * movementSpeed));
	ConvexColliders::move(VectorForward() * movementSpeed);
}

void SpaceShip::moveBackward()
{
	musicManager->playMusic("engine_long");
	Drawable::move(-VectorForward() * movementSpeed * 0.75f);
	ConvexColliders::move(-VectorForward() * movementSpeed * 0.75f);
}

void SpaceShip::stopped()
{
	musicManager->pauseMusic("engine_long");
}

void SpaceShip::shieldUp()
{
	if (shieldLevel < maxShieldLevel)
	{
		shieldLevel++;
		musicManager->playSound("shield_up");
	}
}

void SpaceShip::shieldDown()
{
	if (shieldLevel > 0)
	{
		shieldLevel--;
		musicManager->playSound("shield_down");
	}
}

bool SpaceShip::haveShield()
{
	return (shieldLevel > 0);
}

void SpaceShip::setPosition(sf::Vector2f newPosition)
{
	ConvexColliders::move(newPosition - getPosition());
	Drawable::setPosition(newPosition);
}

void SpaceShip::restart()
{
	setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2));

	hp = maxHp;
	shotDelay = defaultShotDelay;
	shieldLevel = startingShieldLevel;
}

void SpaceShip::draw(sf::RenderWindow & window)
{
	Drawable::draw(window);

#ifdef SHOW_COLLIDERS
	ConvexColliders::draw(window);
#endif // SHOW_COLLIDERS

	if (shieldLevel > 0 && shieldLevel < 4)
	{
		shieldSprite[shieldLevel - 1].setPosition(Drawable::getPosition());
		shieldSprite[shieldLevel - 1].setRotation(Drawable::getRotation());
		window.draw(shieldSprite[shieldLevel - 1]);
	}

	if (hp < maxHp / 3)
	{
		damageSprite[2].setPosition(Drawable::getPosition());
		damageSprite[2].setRotation(Drawable::getRotation());
		window.draw(damageSprite[2]);
	}
	else if (hp <= maxHp * 2 / 3)
	{
		damageSprite[1].setPosition(Drawable::getPosition());
		damageSprite[1].setRotation(Drawable::getRotation());
		window.draw(damageSprite[1]);
	}
	else if (hp < maxHp)
	{
		damageSprite[0].setPosition(Drawable::getPosition());
		damageSprite[0].setRotation(Drawable::getRotation());
		window.draw(damageSprite[0]);
	}
}

void SpaceShip::shoot()
{
	musicManager->playSound("laser2");
	missiles.push_back(new Missile(missileTexture, Drawable::getPosition() + VectorForward() * 45.f, Drawable::getRotation(), VectorForward()));
}

float SpaceShip::getShotDelay()
{
	return shotDelay;
}

int SpaceShip::getHp()
{
	return hp;
}

void SpaceShip::loseHp(int amount)
{
	if (amount <= 0)
	{
#ifdef DEBUG
		std::cout << "amount of losing hp must be greater than zero !!! \n";
#endif // DEBUG
		return;
	}

	hp = std::max(0, hp - amount);
}

void SpaceShip::gainHp(int amount)
{
	if (amount <= 0)
	{
#ifdef DEBUG
		std::cout << "amount of gaining hp must be greater than zero !!! \n";
#endif // DEBUG
		return;
	}

	hp = std::min(maxHp, hp + amount);
}

bool SpaceShip::isOnMap()
{
	return (getPosition().x > -50 && getPosition().x < WIDTH + 50 &&
		getPosition().y > -50 && getPosition().y < HEIGHT + 50);
}

bool SpaceShip::isDead()
{
	return hp <= 0;
}
