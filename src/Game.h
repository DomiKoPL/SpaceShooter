#pragma once

#include <SFML/Graphics.hpp>
#include "UI.h"
#include "Player.h"
#include "ConstVariables.h"
#include "Background.h"
#include "MeteorManager.h"
#include "MusicManager.h"

class Game
{
private:
	sf::RenderWindow window;

	sf::Clock clock;
	sf::Time lastShot;
	sf::Time lastSpawnMeteor;
	sf::Time currentTIme;

	float curMeteorSpawnDelay = 0.5f;
	float meteorSpawnDelay = 0.5f;

	long long currentScore = 0;
	long long highScore = 0;

	long long multiplier = 1;
	bool gamePause = true;
	bool gameStoped = true;
public:

private:
	void playerControls();
	void drawAll();
	void spawnMeteors();
	void moveMissilesAndMeteors();
	void checkCollisions();
	bool checkGameOver();
public:
	static Game* GetInstance();
	void start();
	void restart();
	long long getCurrentScore();
	long long getHighScore();
	bool isGamePaused();
	void pauseGame();
	void unpauseGame();
	void stopGame();
	Game();
	~Game();
};

#define game Game::GetInstance()

