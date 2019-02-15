#include "SettingsCanvas.h"
#include "MusicManager.h"

void SettingsCanvas::drawMenu(sf::RenderWindow & window)
{
	pauseEffect->draw(window);

	backButton->draw(window);

	soundSettings->draw(window);


	generalVolumeDown->draw(window);

	generalVolumeUp->draw(window);

	generalVolume->draw(window);


	musicVolumeDown->draw(window);

	musicVolumeUp->draw(window);

	musicVolume->draw(window);


	soundVolumeDown->draw(window);

	soundVolumeUp->draw(window);

	soundVolume->draw(window);
}

void SettingsCanvas::draw(sf::RenderWindow & window)
{
	drawMenu(window);

	cursor->draw(window);
}

void SettingsCanvas::update(sf::RenderWindow & window)
{
	sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

	backButton->checkIfHighlight(mousePosition);

	generalVolumeUp->checkIfHighlight(mousePosition);

	generalVolumeDown->checkIfHighlight(mousePosition);


	soundVolumeUp->checkIfHighlight(mousePosition);

	soundVolumeDown->checkIfHighlight(mousePosition);


	musicVolumeUp->checkIfHighlight(mousePosition);

	musicVolumeDown->checkIfHighlight(mousePosition);

	cursor->update(window);
}
#include <iostream>
void SettingsCanvas::setup()
{
	pauseEffect = uiManager->makeNewLabel
	("greyPanel", WIDTH, HEIGHT, sf::Vector2f(WIDTH / 2, HEIGHT / 2));
	pauseEffect->setColor(sf::Color::Blue);

	backButton = uiManager->makeNewButton
	("projection", 300, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2 - 200), "BACK", sf::Color::Blue, sf::Color::White);

	soundSettings = uiManager->makeNewLabel
	("normal", 350, 350, sf::Vector2f(WIDTH / 2, HEIGHT / 2 + 50), "Sound Settings", "up");
	soundSettings->setColor(sf::Color::Blue);

	//generalVolume Settings setup
	generalVolumeUp = uiManager->makeNewButton
	("projection", 50, 50, sf::Vector2f(WIDTH / 2 - 120, HEIGHT / 2), "+", sf::Color::Blue, sf::Color::White);


	generalVolumeDown = uiManager->makeNewButton
	("projection", 50, 50, sf::Vector2f(WIDTH / 2 + 120, HEIGHT / 2), "-", sf::Color::Blue, sf::Color::White, "up");

	generalVolume = uiManager->makeNewLabel
	("none", 350, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2), "General");

	//musicVolume Settings setup
	musicVolumeUp = uiManager->makeNewButton
	("projection", 50, 50, sf::Vector2f(WIDTH / 2 - 120, HEIGHT / 2 + 80), "+", sf::Color::Blue, sf::Color::White);

	musicVolumeDown = uiManager->makeNewButton
	("projection", 50, 50, sf::Vector2f(WIDTH / 2 + 120, HEIGHT / 2 + 80), "-", sf::Color::Blue, sf::Color::White, "up");

	musicVolume = uiManager->makeNewLabel
	("none", 350, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2 + 80), "Music");

	//soundsVolume Settings setup
	soundVolumeUp = uiManager->makeNewButton
	("projection", 50, 50, sf::Vector2f(WIDTH / 2 - 120, HEIGHT / 2 + 160), "+", sf::Color::Blue, sf::Color::White);

	soundVolumeDown = uiManager->makeNewButton
	("projection", 50, 50, sf::Vector2f(WIDTH / 2 + 120, HEIGHT / 2 + 160), "-", sf::Color::Blue, sf::Color::White, "up");

	soundVolume = uiManager->makeNewLabel
	("none", 350, 60, sf::Vector2f(WIDTH / 2, HEIGHT / 2 + 160), "Sounds");
}

int SettingsCanvas::checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
	{
		return CanvasesIds::pauseCanvas;
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
		if (backButton->isClickInBounds(mousePosition))
		{
			return CanvasesIds::mainMenuCanvas;
		}

		if (generalVolumeUp->isClickInBounds(mousePosition))
		{
			musicManager->changeGeneralVolume(5.f);
		}

		if (generalVolumeDown->isClickInBounds(mousePosition))
		{
			musicManager->changeGeneralVolume(-5.f);
		}

		if (musicVolumeUp->isClickInBounds(mousePosition))
		{
			musicManager->changeMusicVolume(0.05f);
		}

		if (musicVolumeDown->isClickInBounds(mousePosition))
		{
			musicManager->changeMusicVolume(-0.05f);
		}

		if (soundVolumeUp->isClickInBounds(mousePosition))
		{
			musicManager->changeSoundVolume(0.05f);
		}

		if (soundVolumeDown->isClickInBounds(mousePosition))
		{
			musicManager->changeSoundVolume(-0.05f);
		}
	}

	return CanvasesIds::none;
}

SettingsCanvas::SettingsCanvas()
{
}