#include "PauseCanvas.h"

void PauseCanvas::drawMenu(sf::RenderWindow & window)
{
	pauseEffect->draw(window);

	exitToMainMenuButton->draw(window);

	resumeButton->draw(window);
}

void PauseCanvas::draw(sf::RenderWindow & window)
{
	drawMenu(window);

	cursor->draw(window);
}

void PauseCanvas::update(sf::RenderWindow & window)
{
	sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

	exitToMainMenuButton->checkIfHighlight(mousePosition);

	resumeButton->checkIfHighlight(mousePosition);

	cursor->update(window);
}
#include <functional>
#include <iostream>
void PauseCanvas::setup()
{
	pauseEffect = uiManager->makeNewLabel
	("greyPanel", WIDTH, HEIGHT, sf::Vector2f(WIDTH / 2, HEIGHT / 2));
	pauseEffect->setColor(sf::Color::Blue);

	resumeButton = uiManager->makeNewButton
	("projection", 300, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2 - 100), "RESUME", sf::Color::Blue, sf::Color::White);

	exitToMainMenuButton = uiManager->makeNewButton
	("projection", 300, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2), "MAIN MENU", sf::Color::Blue, sf::Color::White);
}

int PauseCanvas::checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape && game->isGamePaused())
	{
		game->unpauseGame();
		return CanvasesIds::inGameCanvas;
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
		if (resumeButton->isClickInBounds(mousePosition))
		{
			game->unpauseGame();
			return CanvasesIds::inGameCanvas;
		}

		if (exitToMainMenuButton->isClickInBounds(mousePosition))
		{
			game->restart();
			game->pauseGame();
			game->stopGame();
			return CanvasesIds::mainMenuCanvas;
		}
	}

	return CanvasesIds::none;
}

PauseCanvas::PauseCanvas()
{
}