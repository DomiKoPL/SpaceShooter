#include "InGameCanvas.h"

void InGameCanvas::drawPlayerHpUi(sf::RenderWindow & window)
{
	window.draw(playerHpImgSprite);

	window.draw(xSprite);

	window.draw(playerHpTextSprite[player->getHp()]);

	for (int i = 0; i < maxDigitsScore; i++)
	{
		window.draw(scoreSprite[i]);
		window.draw(highScoreSprite[i]);
	}
}

void InGameCanvas::draw(sf::RenderWindow & window)
{
	drawPlayerHpUi(window);
}

void InGameCanvas::update(sf::RenderWindow & window)
{
	

	long long score = game->getCurrentScore();

	for (int i = 0; i < maxDigitsScore; i++)
	{
		scoreSprite[i].setTexture(digitsTexture[score % 10]);
		score /= 10;
	}

	score = game->getCurrentScore();

	if (score >= game->getHighScore())
	{

		for (int i = 0; i < maxDigitsScore; i++)
		{
			highScoreSprite[i].setTexture(digitsTexture[score % 10]);
			score /= 10;
		}
	}
}

void InGameCanvas::setup()
{
	std::string path = "Resources/PNG/UI/";

	for (char j = '0', i = 0; j <= '9'; j++, i++)
	{
		digitsTexture[i].loadFromFile(path + "numeral" + j + ".png");
	}

	playerHpImgTexture.loadFromFile(path + "playerLife2_blue.png");

	xTexture.loadFromFile(path + "numeralX.png");

	for (int i = 0; i < 10; i++)
	{
		playerHpTextSprite[i].setTexture(digitsTexture[i]);
	}

	playerHpImgSprite.setTexture(playerHpImgTexture);

	xSprite.setTexture(xTexture);

	sf::Vector2f pos(WIDTH - 50, 40);
	for (int i = 0; i < maxDigitsScore; i++)
	{
		scoreSprite[i].setTexture(digitsTexture[0]);
		scoreSprite[i].setPosition(pos);
		highScoreSprite[i].setTexture(digitsTexture[0]);
		highScoreSprite[i].setPosition({ pos.x,15 });
		pos.x -= 20;
	}

	long long highScore = game->getHighScore();

	for (int i = 0; i < maxDigitsScore; i++)
	{
		highScoreSprite[i].setTexture(digitsTexture[highScore % 10]);
		highScore /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		playerHpTextSprite[i].setPosition(sf::Vector2f(75, 15));
	}

	xSprite.setPosition(sf::Vector2f(50, 15));

	playerHpImgSprite.setPosition(sf::Vector2f(10, 10));
}

int InGameCanvas::checkTheChangeOfCanvas(sf::RenderWindow & window, sf::Event & event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape && !game->isGamePaused())
	{
		game->pauseGame();
		return CanvasesIds::pauseCanvas;
	}

	return CanvasesIds::none;
}

InGameCanvas::InGameCanvas()
{
}


InGameCanvas::~InGameCanvas()
{
}
