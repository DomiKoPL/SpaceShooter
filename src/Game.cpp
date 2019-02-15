#include "Game.h"
#include <iostream>
#include <set>
#include <fstream>

Game * Game::GetInstance()
{
	static Game _game;
	return &_game;
}

Game::Game()
{
	window.create(sf::VideoMode(HEIGHT, WIDTH), "Space Shooter", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FRAME_RATE);
	window.setMouseCursorVisible(false);
	std::fstream data("data.txt");

	if (!data.eof())
		data >> highScore;

	float generalVolume = 100;
	if (!data.eof())
		data >> generalVolume;
	musicManager->setGeneralVolume(generalVolume);

	float musicVolume = 1;
	if (!data.eof())
		data >> musicVolume;
	musicManager->setMusicVolume(musicVolume);

	float soundVolume = 1;
	if (!data.eof())
		data >> soundVolume;
	musicManager->setSoundVolume(soundVolume);

	data.close();
}

void Game::playerControls()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player->rotateLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player->rotateRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player->moveForward();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player->moveBackward();
	}
	else
	{
		player->stopped();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if ((currentTIme - lastShot).asSeconds() >= player->getShotDelay())
		{
			player->shoot();
			lastShot = clock.getElapsedTime();
		}
	}
}

void Game::drawAll()
{
	window.clear();

	background->draw(window);

	if (!gameStoped)
	{

		for (auto& missile : player->missiles)
			missile->draw(window);

		player->draw(window);

		meteorManager->draw(window);
	}

	ui->draw(window);

	window.display();
}

void Game::spawnMeteors()
{
	if ((currentTIme - lastSpawnMeteor).asSeconds() >= curMeteorSpawnDelay)
	{
		meteorManager->randomMeteors(1);
		lastSpawnMeteor = clock.getElapsedTime();

		curMeteorSpawnDelay *= 0.999f;
	}
}

void Game::moveMissilesAndMeteors()
{
	meteorManager->moveMeteores();

	for (auto& missile : player->missiles)
	{
		missile->move();
	}
}

void Game::checkCollisions()
{

#pragma region O ( meteores.size() * missiles.size() )

	for (int i = (int)meteorManager->meteores.size() - 1; i >= 0; i--)
	{
		if (!meteorManager->meteores[i]->isOnMap())
		{
			meteorManager->meteores.erase(meteorManager->meteores.begin() + i);
		}
	}


	for (int i = (int)player->missiles.size() - 1; i >= 0; i--)
	{
		if (!player->missiles[i]->isOnMap())
		{
			player->missiles.erase(player->missiles.begin() + i);
			continue;
		}

		bool eraseMissile = false;
		for (int j = (int)meteorManager->meteores.size() - 1; j >= 0; j--)
		{
			if (player->missiles[i]->isCollidingWith(meteorManager->meteores[j]))
			{
#ifdef DEBUG
				std::cout << "meteor hit\n";
#endif // DEBUG

				currentScore += 1 * multiplier;

				multiplier++;

				eraseMissile = true;
				meteorManager->meteores.erase(meteorManager->meteores.begin() + j);
			}
		}

		if (eraseMissile)
		{
			player->missiles.erase(player->missiles.begin() + i);
		}
	}
#pragma endregion
}

bool Game::checkGameOver()
{
	if (!player->isOnMap())
	{
#ifdef DEBUG
		std::cout << "Nooo Noo Noo\n";
#endif // DEBUG
		player->loseHp(1);
		multiplier = 1;

		if (player->isDead())
		{

#ifdef DEBUG
			std::cout << "DEAD YOU ****\n";
#endif // DEBUG

			return true;
		}
	}

	for (int i = (int)meteorManager->meteores.size() - 1; i >= 0; i--)
	{
		if (player->isCollidingWith(meteorManager->meteores[i]))
		{


			if (player->haveShield())
			{
#ifdef DEBUG
				std::cout << "Shield hited\n";
#endif // DEBUG
				player->shieldDown();
			}
			else
			{
				player->loseHp(1);
				multiplier = 1;

#ifdef DEBUG
				std::cout << "Player hited\n";
#endif // DEBUG

				musicManager->playSound("lose");


				if (player->isDead())
				{

#ifdef DEBUG
					std::cout << "DEAD\n";
#endif // DEBUG

					return true;
				}
			}

			meteorManager->meteores.erase(meteorManager->meteores.begin() + i);
		}

	}

	return false;
}

void Game::restart()
{
#ifdef DEBUG
	std::cout << "game restarting\n...\n";
#endif // DEBUG

	currentScore = 0;
	multiplier = 1;

	curMeteorSpawnDelay = meteorSpawnDelay;

	player->missiles.clear();
	meteorManager->meteores.clear();
	player->restart();

#ifdef DEBUG
	std::cout << "game restarted\n";
#endif // DEBUG
}

void Game::start()
{
	lastShot = clock.getElapsedTime();
	lastSpawnMeteor = clock.getElapsedTime();

	musicManager->playMusic("mainTheme");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			ui->checkTheChangeOfCanvas(window, event);
		}

		if (!gamePause)
		{
			currentTIme = clock.getElapsedTime();

			playerControls();

			spawnMeteors();

			moveMissilesAndMeteors();

			checkCollisions();

			if (currentScore > highScore)
			{
				highScore = currentScore;
			}

			if (checkGameOver())
			{
				restart();
			}
		}
		else
		{
			player->stopped();
		}

		ui->update(window);

		drawAll();
	}
}

long long Game::getCurrentScore()
{
	return currentScore;
}

long long Game::getHighScore()
{
	return highScore;
}

bool Game::isGamePaused()
{
	return gamePause;
}

void Game::pauseGame()
{
#ifdef DEBUG
	std::cout << "game pause\n";
#endif // DEBUG

	gamePause = true;
}

void Game::unpauseGame()
{
#ifdef DEBUG
	std::cout << "game unpause\n";
#endif // DEBUG

	gameStoped = false;
	gamePause = false;
}

void Game::stopGame()
{
	gameStoped = true;
}


Game::~Game()
{
	std::fstream data("data.txt");

	data.clear();

	data << highScore << "\n";

	data << musicManager->getGeneralVolume() << "\n";

	data << musicManager->getMusicVolume() << "\n";

	data << musicManager->getSoundVolume() << "\n";

	data.close();
}
