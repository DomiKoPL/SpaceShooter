#include "MainMenuCanvas.h"

void MainMenuCanvas::drawMenu(sf::RenderWindow & window)
{
	pauseEffect->draw(window);

	playButton->draw(window);

	settingButton->draw(window);

	exitButton->draw(window);

	title->draw(window);
}

void MainMenuCanvas::draw(sf::RenderWindow & window)
{
	drawMenu(window);

	cursor->draw(window);
}

void MainMenuCanvas::update(sf::RenderWindow & window)
{
	cursor->update(window);

	sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

	playButton->checkIfHighlight(mousePosition);

	settingButton->checkIfHighlight(mousePosition);

	exitButton->checkIfHighlight(mousePosition);

	title->update(window);
}

void MainMenuCanvas::setup()
{
	pauseEffect = uiManager->makeNewLabel
	("greyPanel", WIDTH, HEIGHT, sf::Vector2f(WIDTH / 2, HEIGHT / 2));
	pauseEffect->setColor(sf::Color::Blue);

	playButton = uiManager->makeNewButton
	("projection", 300, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2 - 100), "PLAY", sf::Color::Blue, sf::Color::White);

	settingButton = uiManager->makeNewButton
	("projection", 300, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2), "SETTINGS", sf::Color::Blue, sf::Color::White);

	exitButton = uiManager->makeNewButton
	("projection", 300, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2 + 100), "EXIT", sf::Color::Blue, sf::Color::White);

	title = uiManager->makeNewAnimatedText
	("SPACE SHOOTER", sf::Vector2f(WIDTH / 2, HEIGHT / 2 - 250), 45);
}

int MainMenuCanvas::checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			game->unpauseGame();
			return CanvasesIds::inGameCanvas;
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
		if (playButton->isClickInBounds(mousePosition))
		{
			game->unpauseGame();
			return CanvasesIds::inGameCanvas;
		}

		if (settingButton->isClickInBounds(mousePosition))
		{
			return CanvasesIds::settingsCanvas;
		}

		if (exitButton->isClickInBounds(mousePosition))
		{
			window.close();
			return CanvasesIds::none;
		}
	}
	return CanvasesIds::none;
}

MainMenuCanvas::MainMenuCanvas()
{

}


MainMenuCanvas::~MainMenuCanvas()
{
}
