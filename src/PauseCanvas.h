#pragma once
#include "Canvas.h"
#include "ConstVariables.h"
#include "Game.h"
#include "Cursor.h"
#include "UIManager.h"

class PauseCanvas : public Canvas
{
private:
	Button * resumeButton;
	Button * exitToMainMenuButton;

	Label* pauseEffect;
private:
	void drawMenu(sf::RenderWindow & window);
public:
	void draw(sf::RenderWindow & window) override;
	void update(sf::RenderWindow & window) override;
	void setup() override;
	int checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)override;
	PauseCanvas();
};

