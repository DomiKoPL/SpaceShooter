#pragma once
#include "Drawable.h"
#include "ConstVariables.h"
#include <string>
#include <vector>

class Background
{
#pragma region Variables
private:
	std::string texturePath = "Resources/Backgrounds/purple.png";
public:
	sf::Texture texture;
	std::vector<sf::Sprite> sprites;

#pragma endregion

#pragma region Methodes
private:

public:
	static Background* GetInstance();
	Background();
	void draw(sf::RenderWindow & window);
#pragma endregion
};

#define background Background::GetInstance()