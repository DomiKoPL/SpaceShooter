#include "Player.h"
#include "MusicManager.h"
#include "ConstVariables.h"
#include <cmath>
#include <string>
#include <iostream>

Player * Player::GetInstance()
{
	static Player _player;
	return &_player;
}

Player::Player()
	: SpaceShip()
{
}