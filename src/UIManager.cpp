#include "UIManager.h"
#include <iostream>
void UIManager::setup()
{
	//font.loadFromFile("Resources/Fonts/kenvector_future.ttf");
	font.loadFromFile("Resources/Fonts/Velocista-Demo-FFP.ttf");

	parts = { "_left.png", "_mid.png","_right.png" };

	buttonColors = { "blue","green","orange","yellow","white","shadow" };
	std::string path = "Resources/UI/";

	for (auto& color : buttonColors)
	{
		std::string name = "barHorizontal_" + color;
		for (auto& part : parts)
		{
			std::string fullName = color + part;
			sf::Texture texture;
			buttonTextures.insert({ fullName,texture });
			buttonTextures[fullName].loadFromFile(path + name + part);
		}
	}

	glasPanelsStyles = { "cornerBL","cornerBR","corners","cornerTL","cornerTR","normal","projection","tab" };

	for (auto& panelStyle : glasPanelsStyles)
	{
		std::string name = "glassPanel_" + panelStyle + ".png";
		sf::Texture texture;
		glasPanelsTextures.insert({ panelStyle,texture });
		glasPanelsTextures[panelStyle].loadFromFile(path + name);
	}
	glasPanelsStyles.insert("none");
	sf::Texture noneTexture;
	glasPanelsTextures.insert({ "none",noneTexture });
	glasPanelsTextures["none"].loadFromFile(path + "none.png");

	metalPanelsColors = { "blue","green","yellow","orange" };
	metalPanelsStyles = { "","Corner" };

	for (auto& color : metalPanelsColors)
	{
		for (auto& style : metalPanelsStyles)
		{
			std::string name = "metalPanel_" + color + style + ".png";
			sf::Texture texture;
			metalPanelsTextures.insert({ color + style,texture });
			metalPanelsTextures[color + style].loadFromFile(path + name);
		}
	}


	greyPanel.loadFromFile(path + "greyPanel.png");
}

UIManager * UIManager::GetInstance()
{
	static UIManager _UIManager;
	return &_UIManager;
}

bool UIManager::buttonColorExist(std::string name)
{
	return buttonColors.count(name);
}

bool UIManager::glasPanelStyleExist(std::string name)
{
	return glasPanelsStyles.count(name);
}

bool UIManager::metalPanelStyleExist(std::string name)
{
	return metalPanelsStyles.count(name);
}

bool UIManager::metalPanelColorExist(std::string name)
{
	return metalPanelsColors.count(name);
}

Button * UIManager::makeNewButton(std::string style, int width, int height, sf::Vector2f position, std::string text, sf::Color color1, sf::Color color2, std::string alignment)
{
	if (!glasPanelStyleExist(style))
	{
#ifdef DEBUG
		std::cout << "panel style " + style + " doesn't exist\n";
#endif // DEBUG

		return nullptr;
	}

	if (width < 0 || height < 0)
	{
#ifdef DEBUG
		std::cout << "width and height mus be greater than 0 !!!\n";
#endif // DEBUG
		return nullptr;
	}


	sf::Text _text(text, font);

	return  new Button(glasPanelsTextures[style],
		width, height, position, _text, color1, color2, alignment);

}

Label * UIManager::makeNewLabel(std::string style, int width, int height, sf::Vector2f position, std::string text, std::string alignment)
{
	if (width < 0 || height < 0)
	{
#ifdef DEBUG
		std::cout << "width and height mus be greater than 0 !!!\n";
#endif // DEBUG
		return nullptr;
	}

	if (style == "greyPanel")
	{
		sf::Text _text(text, font);

		return new Label(greyPanel,
			width, height, position, _text, alignment);
	}

	if (!glasPanelStyleExist(style))
	{
#ifdef DEBUG
		std::cout << "panel style " + style + " doesn't exist\n";
#endif // DEBUG

		return nullptr;
	}

	sf::Text _text(text, font);

	return  new Label(glasPanelsTextures[style],
		width, height, position, _text, alignment);
}

Label * UIManager::makeNewLabel(std::string style, std::string color, int width, int height, sf::Vector2f position, std::string text, std::string alignment)
{
	if (!metalPanelColorExist(color))
	{
#ifdef DEBUG
		std::cout << "laber color error : " + color + "\n";
#endif // DEBUG
		return nullptr;
	}

	if (!metalPanelStyleExist(style) || width < 0 || height < 0)
	{
#ifdef DEBUG
		std::cout << "laber style error : " + style + "\n";
#endif // DEBUG
		return nullptr;
	}
	if (width < 0 || height < 0)
	{
#ifdef DEBUG
		std::cout << "width and height mus be greater than 0 !!!\n";
#endif // DEBUG
		return nullptr;
	}

	sf::Text _text(text, font);

	return new Label(metalPanelsTextures[color + style],
		width, height, position, _text, alignment);
}

AnimatedText * UIManager::makeNewAnimatedText(std::string text, sf::Vector2f pos, int size)
{
	sf::Text _text(text, font);
	_text.setFillColor(sf::Color::Red);
	_text.setCharacterSize(size);

	_text.setOrigin({ _text.getGlobalBounds().width / 2,_text.getGlobalBounds().height / 2 });
	_text.setPosition(pos);
	_text.setStyle(sf::Text::Bold);

	return new AnimatedText(_text);
}


UIManager::UIManager()
{
	setup();
}