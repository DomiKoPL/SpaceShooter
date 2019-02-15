#include "UI.h"
#include <string>
#include "Player.h"
#include "Game.h"

void UI::setupCanvases()
{
	canvases[CanvasesIds::mainMenuCanvas] = new MainMenuCanvas();
	canvases[CanvasesIds::mainMenuCanvas]->setup();

	canvases[CanvasesIds::inGameCanvas] = new InGameCanvas();
	canvases[CanvasesIds::inGameCanvas]->setup();

	canvases[CanvasesIds::pauseCanvas] = new PauseCanvas();
	canvases[CanvasesIds::pauseCanvas]->setup();

	canvases[CanvasesIds::settingsCanvas] = new SettingsCanvas();
	canvases[CanvasesIds::settingsCanvas]->setup();

	currentCanvas = canvases[CanvasesIds::mainMenuCanvas];
}

UI * UI::GetInstance()
{
	static UI _ui;
	return &_ui;
}

void UI::draw(sf::RenderWindow & window)
{
	currentCanvas->draw(window);
}

void UI::update(sf::RenderWindow & window)
{
	currentCanvas->update(window);
}

void UI::checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)
{
	int newCanvasId = currentCanvas->checkTheChangeOfCanvas(window, event);

	if (newCanvasId != CanvasesIds::none)
	{
		currentCanvas = canvases[newCanvasId];
	}
}

UI::UI()
{
	setupCanvases();
}