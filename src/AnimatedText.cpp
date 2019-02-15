#include "AnimatedText.h"
#include <iostream>

void AnimatedText::draw(sf::RenderWindow & window)
{
	window.draw(text);
}

void AnimatedText::update(sf::RenderWindow & window)
{
	if (++currDelay >= delay)
	{
		currDelay -= delay;
		text.setRotation(text.getRotation() + rotate);

		if (++currCount >= count)
		{
			currCount -= count;
			rotate = -rotate;
		}

		text.setScale(text.getScale() + scale);
		if (++currScCount >= scCount)
		{
			currScCount -= scCount;
			scale = -scale;
		}
	}

}

AnimatedText::AnimatedText(sf::Text _text)
{
	text = _text;
}

AnimatedText::AnimatedText()
{

}