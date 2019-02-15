#pragma once

#include <SFML/Graphics.hpp>
#include "Canvas.h"
#include "MainMenuCanvas.h"
#include "InGameCanvas.h"
#include "CanvasesIds.h"
#include "PauseCanvas.h"
#include "SettingsCanvas.h"

class UI
{
private:
	Canvas * currentCanvas;
	Canvas* canvases[4];

public:

private:
	void setupCanvases();
public:
	static UI* GetInstance();
	void draw(sf::RenderWindow & window);
	void update(sf::RenderWindow & window);
	void checkTheChangeOfCanvas(sf::RenderWindow & window , sf::Event & event);
	UI();
};

#define ui UI::GetInstance()