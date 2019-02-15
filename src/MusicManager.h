#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <string>
#include <unordered_map>
#include "ConstVariables.h"
#include <vector>

class MusicManager
{
#pragma region Variables
private:
	std::unordered_map<std::string, sf::Sound*>sounds;
	std::unordered_map < std::string, sf::SoundBuffer> soundBuffers;
	std::unordered_map<std::string, sf::Music*>music;

	float generalVolume = 100;// <0,100>
	float soundVolume = 1;// <0,1>
	float musicVolume = 1;// <0,1>
public:

#pragma endregion

#pragma region Methodes
private:
	void updateVolume();
public:
	static MusicManager* GetInstance();
	MusicManager();
	void playSound(std::string name);
	void playMusic(std::string name);
	void pauseMusic(std::string name);

	void setGeneralVolume(float newVolume);
	void setSoundVolume(float newVolume);
	void setMusicVolume(float newVolume);

	float getGeneralVolume();
	float getMusicVolume();
	float getSoundVolume();

	void changeGeneralVolume(float offset);
	void changeSoundVolume(float offset);
	void changeMusicVolume(float offset);
#pragma endregion
};

#define musicManager MusicManager::GetInstance()