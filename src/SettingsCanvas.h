#pragma once
#include "Canvas.h"
#include "CanvasesIds.h"
#include "ConstVariables.h"
#include "Cursor.h"
#include "UIManager.h"

class SettingsCanvas : public Canvas
{
private:
	Button * backButton;
	Label * soundSettings;

	Button * generalVolumeUp, *generalVolumeDown;
	Label * generalVolume;

	Button * musicVolumeUp, *musicVolumeDown;
	Label * musicVolume;

	Button * soundVolumeUp, *soundVolumeDown;
	Label * soundVolume;

	Label* pauseEffect;
public:
	void drawMenu(sf::RenderWindow & window);
public:
	void draw(sf::RenderWindow & window) override;
	void update(sf::RenderWindow & window) override;
	void setup() override;
	int checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)override;
	SettingsCanvas();
};

