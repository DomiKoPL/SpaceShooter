#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Label.h"
#include "CanvasesIds.h"
#include "ConstVariables.h"
#include "AnimatedText.h"
#include <string>
#include <unordered_map>
#include <set>
#include <vector>

class UIManager
{
private:
	std::unordered_map < std::string, sf::Texture> buttonTextures;//color_part.png  // part { left,mid,right}
	std::set<std::string> buttonColors;
	std::vector<std::string> parts;

	std::unordered_map < std::string, sf::Texture> glasPanelsTextures;
	std::set<std::string> glasPanelsStyles;
	std::unordered_map < std::string, sf::Texture> metalPanelsTextures;
	std::set<std::string> metalPanelsStyles, metalPanelsColors;

	sf::Texture greyPanel;

	sf::Font font;
private:
	void setup();
public:
	static UIManager* GetInstance();
	bool buttonColorExist(std::string name);
	bool glasPanelStyleExist(std::string name);
	bool metalPanelStyleExist(std::string name);
	bool metalPanelColorExist(std::string name);
	Button* makeNewButton(std::string style, int width, int height, sf::Vector2f position, std::string text, sf::Color color1, sf::Color color2, std::string alignment = "inside");
	Label* makeNewLabel(std::string style, int width, int height, sf::Vector2f position, std::string text = "", std::string alignment = "inside");
	Label* makeNewLabel(std::string style, std::string color, int width, int height, sf::Vector2f position, std::string text = "", std::string alignment = "inside");
	AnimatedText* makeNewAnimatedText(std::string text, sf::Vector2f pos, int size = 30);
	UIManager();
};

#define uiManager UIManager::GetInstance()