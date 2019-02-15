#include "MusicManager.h"
#include <iostream>

void MusicManager::updateVolume()
{
	for (auto& sound : sounds)
	{
		sound.second->setVolume(soundVolume * generalVolume);
	}

	for (auto& mus : music)
	{
		mus.second->setVolume(musicVolume * generalVolume);
	}
}

MusicManager * MusicManager::GetInstance()
{
	static MusicManager _musicManager;
	return &_musicManager;
}

MusicManager::MusicManager()
{

	//LOAD SOUNDS
	soundBuffers["laser1"].loadFromFile("Resources/Sounds/sfx_laser1.ogg");

	sounds.insert({ "laser1",new sf::Sound });
	sounds["laser1"]->setBuffer(soundBuffers["laser1"]);

	soundBuffers["laser2"].loadFromFile("Resources/Sounds/sfx_laser2.ogg");
	sounds.insert({ "laser2",new sf::Sound });
	sounds["laser2"]->setBuffer(soundBuffers["laser2"]);

	soundBuffers["lose"].loadFromFile("Resources/Sounds/sfx_lose.ogg");
	sounds.insert({ "lose",new sf::Sound });
	sounds["lose"]->setBuffer(soundBuffers["lose"]);

	soundBuffers["shield_down"].loadFromFile("Resources/Sounds/sfx_shield_down.ogg");
	sounds.insert({ "shield_down",new sf::Sound });
	sounds["shield_down"]->setBuffer(soundBuffers["shield_down"]);

	soundBuffers["shield_up"].loadFromFile("Resources/Sounds/sfx_shield_up.ogg");
	sounds.insert({ "shield_up",new sf::Sound });
	sounds["shield_up"]->setBuffer(soundBuffers["shield_up"]);

	//LOAD MUSIC
	music.insert({ "mainTheme",new sf::Music });
	music["mainTheme"]->openFromFile("Resources/Sounds/boss.ogg");
	music["mainTheme"]->setLoop(true);

	music.insert({ "engine_long", new sf::Music });
	music["engine_long"]->openFromFile("Resources/Sounds/engine_long.ogg");
	music["engine_long"]->setLoop(true);
	music["engine_long"]->pause();


	//UPDATE VOLUME
	updateVolume();
}

MusicManager::~MusicManager()
{
	for(auto& sound : sounds)
	{
		delete(sound.second);
	}

	for(auto& m : music)
	{
		delete(m.second);
	}
}

void MusicManager::playSound(std::string name)
{
	if (!sounds.count(name))
	{
#ifdef DEBUG
		std::cout << "Sound " + name + "doesn't exist\n";
#endif // DEBUG
		return;
	}
	sounds[name]->play();
}

void MusicManager::playMusic(std::string name)
{
	if (!music.count(name))
	{
#ifdef DEBUG
		std::cout << "Music " + name + "doesn't exist\n";
#endif // DEBUG
		return;
	}

	if (music[name]->getStatus() != music[name]->Playing)
		music[name]->play();
}

void MusicManager::pauseMusic(std::string name)
{
	if (!music.count(name))
	{
#ifdef DEBUG
		std::cout << "Music " + name + "doesn't exist\n";
#endif // DEBUG
		return;
	}

	if (music[name]->getStatus() != music[name]->Paused)
		music[name]->pause();
}
void MusicManager::setGeneralVolume(float newVolume)
{
	generalVolume = newVolume;

	generalVolume = std::min(generalVolume, 100.f);
	generalVolume = std::max(generalVolume, 0.f);

	updateVolume();
}

void MusicManager::setSoundVolume(float newVolume)
{
	soundVolume = newVolume;

	soundVolume = std::min(soundVolume, 1.f);
	soundVolume = std::max(soundVolume, 0.f);

	updateVolume();
}

void MusicManager::setMusicVolume(float newVolume)
{
	musicVolume = newVolume;

	musicVolume = std::min(musicVolume, 1.f);
	musicVolume = std::max(musicVolume, 0.f);

	updateVolume();
}

float MusicManager::getGeneralVolume()
{
	return generalVolume;
}

float MusicManager::getMusicVolume()
{
	return musicVolume;
}

float MusicManager::getSoundVolume()
{
	return soundVolume;
}

void MusicManager::changeGeneralVolume(float offset)
{
	generalVolume += offset;
	generalVolume = std::min(generalVolume, 100.f);
	generalVolume = std::max(generalVolume, 0.f);

	updateVolume();
}

void MusicManager::changeSoundVolume(float offset)
{
	soundVolume += offset;
	soundVolume = std::min(soundVolume, 1.f);
	soundVolume = std::max(soundVolume, 0.f);

	updateVolume();
}

void MusicManager::changeMusicVolume(float offset)
{
	musicVolume += offset;
	musicVolume = std::min(musicVolume, 1.f);
	musicVolume = std::max(musicVolume, 0.f);

	updateVolume();
}
