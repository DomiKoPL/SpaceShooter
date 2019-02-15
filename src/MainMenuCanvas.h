#pragma once

#include "Canvas.h"
#include "ConstVariables.h"
#include "Game.h"
#include "CanvasesIds.h"
#include "UIManager.h"

class MainMenuCanvas : public Canvas
{
private:
	Button * playButton;
	Button * settingButton;
	Button * exitButton;

	AnimatedText * title;

	Label* pauseEffect;
private:
	void drawMenu(sf::RenderWindow & window);
public:
	void draw(sf::RenderWindow & window) override;
	void update(sf::RenderWindow & window) override;
	void setup() override;
	int checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)override;
	MainMenuCanvas();
	~MainMenuCanvas();
};