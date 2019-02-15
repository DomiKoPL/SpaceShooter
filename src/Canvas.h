#pragma once

#include <SFML/Graphics.hpp>

class Canvas
{
public:
	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void setup() = 0;
	virtual void update(sf::RenderWindow & window) = 0;
	virtual int checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event) = 0;
	Canvas();
	~Canvas();
};

