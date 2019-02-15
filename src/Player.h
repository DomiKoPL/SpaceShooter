#pragma once
#include <SFML/Graphics.hpp>
#include "SpaceShip.h"

class Player : public SpaceShip
{
public:
	static Player* GetInstance();
	Player();
};

#define player Player::GetInstance()