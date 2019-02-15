#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Meteor.h"

class MeteorManager
{
#pragma region Variables
private:
	sf::Texture meteoresTexture[20];
	std::vector<std::vector<sf::Vector2f> >vertices[20];
	float maxXSpeed = 1.3f;
	float maxYSpeed = 1.3f;

public:
	std::vector<Meteor*>meteores;

#pragma endregion

#pragma region Methodes
private:
	void LoadTextures();
public:
	MeteorManager();
	static MeteorManager* GetInstance();
	void draw(sf::RenderWindow & window);
	void moveMeteores();
	void randomMeteors(int amount);
#pragma endregion
};

#define meteorManager MeteorManager::GetInstance()
