#pragma once

#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Missile.h"
#include "ConvexColliders.h"
#include <vector>

class SpaceShip : public Drawable, public ConvexColliders
{
private:
	float rotationSpeed = 2.20f;
	float movementSpeed = 1.30f;

	int shieldLevel = 0;
	sf::Texture shieldTextures[3];
	sf::Sprite shieldSprite[3];

	sf::Texture damageTexture[3];
	sf::Sprite damageSprite[3];

	sf::Texture missileTexture;
	float shotDelay;
	int hp;

	int maxHp = 9;
	float defaultShotDelay = 0.2f;
	int maxShieldLevel = 3;
	int startingShieldLevel = 3;
public:
	std::vector<Missile*> missiles;

private:
	sf::Vector2f VectorForward();
public:
	void rotateLeft();
	void rotateRight();
	void moveForward();
	void moveBackward();
	void stopped();

	void shieldUp();
	void shieldDown();
	bool haveShield();

	void setPosition(sf::Vector2f newPosition);
	void restart();

	void draw(sf::RenderWindow & window);
	void shoot();

	float getShotDelay();
	int getHp();

	void loseHp(int amount);
	void gainHp(int amount);

	bool isOnMap();

	bool isDead();
	SpaceShip();
};

