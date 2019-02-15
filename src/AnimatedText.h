#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class AnimatedText
{
private:
	sf::Text text;
	int delay = 4;
	int currDelay = 0;

	int count = 40;
	int currCount = count / 2;

	sf::Vector2f scale = { 0.02f,0.02f };
	int scCount = 20;
	int currScCount = 0;

	float rotate = 0.3f;
public:
	void draw(sf::RenderWindow & window);
	void update(sf::RenderWindow & window);
	AnimatedText(sf::Text _text);
	AnimatedText();
};

