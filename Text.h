#include "stdafx.h"
#pragma once

class TextObject
{
public:
	sf::Text uiText;
	std::wstringstream stringStream;

	TextObject::TextObject(sf::Font font, const sf::RenderWindow& window, int characterSize, std::wstring caption);

	void centerTextOrigin();
	void centerTextPosition(sf::RenderWindow &window);
private:

};

/*

	void updateText();
	void renderText(sf::RenderTarget& target);


void Game::updateText(sf::Text& target)
{
	std::wstringstream stringStream;
	stringStream << L"something i want to print ♥♦♣♠";
	this->uiText.setString(stringStream.str());
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(textObject::uiText);
}

*/