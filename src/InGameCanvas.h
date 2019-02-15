#pragma once

#include "Canvas.h"
#include "ConstVariables.h"
#include "Game.h"

class InGameCanvas :public Canvas
{
private:
	static const int maxDigitsScore = 18;

	sf::Texture digitsTexture[10];
	sf::Texture playerHpImgTexture, xTexture;
	sf::Sprite playerHpTextSprite[10], playerHpImgSprite, xSprite;

	sf::Sprite scoreSprite[maxDigitsScore];
	sf::Sprite highScoreSprite[maxDigitsScore];

private:
	void drawPlayerHpUi(sf::RenderWindow & window);
public:
	void draw(sf::RenderWindow & window) override;
	void update(sf::RenderWindow & window) override;
	void setup() override;
	int checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)override;
	InGameCanvas();
	~InGameCanvas();
};

