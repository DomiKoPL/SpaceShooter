#include "MeteorManager.h"
#include "ConstVariables.h"
#include <string>
#include <random>

void MeteorManager::LoadTextures()
{
	std::string path = "Resources/PNG/Meteors/";
	int i = 0;

	for (auto color : { "Brown", "Grey" })
	{
		for (char j = '1'; j <= '4'; j++)
		{
			meteoresTexture[i++].loadFromFile(path + "meteor" + color + "_big" + j + ".png");
		}
		vertices[i - 4].push_back({ {17,0},{73,0},{101,40}, {84,74}, {60,71},{0,52} });
		vertices[i - 4].push_back({ { 60,71 } ,{29,83},{0,52} });

		vertices[i - 3].push_back({ {67,0},{119,19},{105,66},{51,82},{34,97},{6,75},{0,44},{20,8} });
		vertices[i - 3].push_back({ {51,82},{34,97},{6,75} });

		vertices[i - 2].push_back({ {34,0},{73,12},{87,41},{65,81},{16,74},{2,55},{0,22} });
		vertices[i - 1].push_back({ {66,0},{97,36},{79,90},{30,94},{0,58} ,{13,14} });

		for (char j = '1'; j <= '2'; j++)
		{
			meteoresTexture[i++].loadFromFile(path + "meteor" + color + "_med" + j + ".png");
		}
		vertices[i - 2].push_back({ {11,1},{38,2},{43,28},{22,42},{6,36} ,{ 0,17 } });
		vertices[i - 1].push_back({ {31,0},{44,17},{29,39},{13,37},{0,24},{6,5} });

		for (char j = '1'; j <= '2'; j++)
		{
			meteoresTexture[i++].loadFromFile(path + "meteor" + color + "_small" + j + ".png");
		}
		vertices[i - 2].push_back({ {7,1},{24,2},{27,17},{13,26},{4,23},{0,12} });
		vertices[i - 1].push_back({ {19,0},{28,11},{18,25},{9,24},{0,15},{4,3} });

		for (char j = '1'; j <= '2'; j++)
		{
			meteoresTexture[i++].loadFromFile(path + "meteor" + color + "_tiny" + j + ".png");
		}
		vertices[i - 2].push_back({ {8,0},{17,4},{14,16},{5,16},{0,8} });
		vertices[i - 1].push_back({ {6,0},{15,4},{9,14},{0,7} });
	}
}

MeteorManager::MeteorManager()
{
	LoadTextures();
}

MeteorManager * MeteorManager::GetInstance()
{
	static MeteorManager _meteorManager;
	return &_meteorManager;
}

void MeteorManager::draw(sf::RenderWindow & window)
{
	for (auto& meteor : meteores)
	{
		meteor->draw(window);
	}
}

void MeteorManager::moveMeteores()
{
	for (auto& meteor : meteores)
	{
		meteor->move();
	}

	for (int i = (int)meteores.size() - 1; i >= 0; i--)
	{
		if (!meteores[i]->isOnMap())
		{
			meteores.erase(meteores.begin() + i);
		}
	}

}

thread_local std::mt19937 gen{ std::random_device{}() };

template<typename T>
T random(T min, T max) {
	using dist = std::conditional_t<
		std::is_integral<T>::value,
		std::uniform_int_distribution<T>,
		std::uniform_real_distribution<T>
	>;
	return dist{ min, max }(gen);
}

void MeteorManager::randomMeteors(int amount)
{

	for (int i = 0; i < amount; i++)
	{
		sf::Vector2f pos;
		sf::Vector2f offset;
		if (random(-1.f, 1.f) >= 0)
		{
			pos.x = (float)random(-200, -100);
			offset.x = (float)random(0.01f, maxXSpeed);
		}
		else
		{
			pos.x = (float)random(WIDTH + 100, WIDTH + 200);
			offset.x = (float)random(-maxXSpeed, -0.01f);
		}

		if (random(-1.f, 1.f) >= 0)
		{
			pos.y = (float)random(-200, -100);
			offset.y = (float)random(0.01f, maxYSpeed);
		}
		else
		{
			pos.y = (float)random(HEIGHT + 100, HEIGHT + 200);
			offset.y = (float)random(-maxYSpeed, -0.01f);
		}

		int id = random(0, 19);
		meteores.push_back(new Meteor(meteoresTexture[id], pos, offset, vertices[id]));
	}
}